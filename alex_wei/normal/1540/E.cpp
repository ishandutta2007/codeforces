#include <bits/stdc++.h>
using namespace std;
 
using db = double;
using ll = long long;
using ld = long double;
using vint = vector <int>;
using pll = pair <ll, ll>;
using pii = pair <int, int>;
using ull = unsigned long long;
 
/*
#define db double
#define ll long long
#define ld long double
#define vint vector <int>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define ull unsigned long long
*/
 
#define fi first
#define se second
#define pb emplace_back
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
 
inline ll read() {
	ll x = 0, sgn = 0; char s = getchar();
	while(!isdigit(s)) sgn |= s == '-', s = getchar();
	while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
	return sgn ? -x : x;
}

const int N = 300 + 5;
const ll mod = 1e9 + 7;

void cmin(int &x, int y) {x = x < y ? x : y;}
ll gsm[N][N << 2], inv[N][N << 2];
ll ksm(ll a, ll b = mod - 2) {
	if(1 <= a && a < N && b <= 1000) return gsm[a][b];
	ll s = 1;
	while(b) {
		if(b & 1) s = s * a % mod;
		a = a * a % mod, b >>= 1;
	} return s;
}

int n, q, a[N], d[N];
ll E[N][N], T[N][N]; // Matrices
ll v[N][N], c[N][N], tmp[N][N]; // Vectors
void Read() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		a[i] = read(), E[i][i] = 1;
	for(int i = 1; i <= n; i++) {
		int c = read();
		for(int j = 1; j <= c; j++)
			E[i][read()] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			T[i][j] = E[i][j] * j;
}
void Init() {
	for(int i = 1; i < N; i++) {
		gsm[i][0] = 1;
		for(int j = 1; j < N << 2; j++)
			gsm[i][j] = gsm[i][j - 1] * i % mod;
		inv[i][0] = 1, inv[i][1] = ksm(i);
		for(int j = 2; j < N << 2; j++)
			inv[i][j] = inv[i][j - 1] * inv[i][1] % mod;
	}
	
	mem(c, 0, N), mem(v, 0, N);
	// solve an upper triangular matrix equation : T * v = lambda * v
	// (T - labmda * I) * v = 0
	for(int i = 1; i <= n; i++) { // i represents the eigenvalue
		v[i][i] = 1; // v_{i, j} = 0 (i < j)
		// because T is already an upper triangular matrix
		// we can simply replace each variable with what we've worked out
		for(int j = i - 1; j; j--) {
			// replace the variable that we've already figuered out
			for(int k = j + 1; k <= i; k++)
				v[i][j] = (v[i][j] + mod - T[j][k] * v[i][k] % mod) % mod;
			// then divided by the coefficient (T - i * I)_{j, j}, which is j - i
			v[i][j] = mod - v[i][j] * ksm(i - j) % mod;
		}
	}
	
	// OK then we decompose e_i into the linear representation of v_i
	// e_i = \sum_{1 \leq j \leq n} v_j * c_{i, j} (a typo in the tutourial)
	// obviously v is also an upper triangular matrix
	for(int i = 1; i <= n; i++) {
		c[i][i] = 1;
		for(int j = i - 1; j; j--)
			for(int k = j + 1; k <= i; k++)
				c[i][j] = (c[i][j] + mod - v[k][j] * c[i][k] % mod) % mod;
		// because v_{i, i} = 1 we don't need to divide it by a coefficient
	}
	
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= n; j++)
//			cerr << i << " " << j << " " << c[i][j] << endl;
	
	// because we need to calculate the sum of v_{i, j} * lambda_i ^ k
	// with i \in [1, n], j \in [l, r], so we do a prefix sum for d_i
	for(int i = 1; i <= n; i++)
		for(int j = 2; j <= n; j++)
			v[i][j] = (v[i][j] + v[i][j - 1]) % mod;
}

struct BIT {
	int a[N];
	void clear() {mem(a, 0, N);}
	void add(int x, int v) {
		x += 1;
		while(x <= n + 1) a[x] = (a[x] + v) % mod, x += x & -x;
	}
	int query(int x) {
		ll s = 0; x += 1;
		while(x) s = s + a[x], x -= x & -x;
		return s % mod;
	}
} tr[N];

void Rebuild() {
//	cerr << "Rebuild\n";
	mem(tmp, 0, N);
	
	// recalculate d
	for(int i = n; i; i--) {
		d[i] = (a[i] <= 0 ? mod : 0), tr[i].clear();
		for(int j = i + 1; j <= n; j++)
			if(E[i][j]) cmin(d[i], d[j] + 1);
	}
	
	for(int j = 1; j <= n; j++) {
//		cerr << d[j] << ' ';
		// caculate the contribution from j to i :
		// lambda_j ^ {-d_i} * c_{i, j} * a_i
		for(int i = 1; i <= n; i++) {
			if(d[i] > n) continue;
			ll coef = inv[j][d[i]] * c[i][j] % mod;
//			cerr << j << " " << i << " " << coef << endl;
			tr[j].add(d[i], (tmp[j][i] = coef) * (a[i] + mod) % mod);
		}
	}
//	cerr << endl;
}

void Query() {
	cin >> q;
	for(int i = 1; i <= q; i++) {
		int op = read();
		if(op == 1) {
			int k = read(), l = read(), r = read(), ans = 0;
//			cerr << k << " " << l << " " << r << endl;
			for(int i = 1; i <= n; i++) {
				ll coef = ksm(i, k) * (v[i][r] - v[i][l - 1] + mod) % mod;
				ans = (ans + coef * tr[i].query(min(n, k - 1))) % mod;
			}
			for(int i = l; i <= r; i++)
				if(d[i] >= k) ans = (ans + a[i] + mod) % mod;
			printf("%d\n", ans);
		} else {
			int id = read(), x = read();
			if((a[id] += x) > 0 && a[id] <= x) Rebuild();
			else for(int i = 1; i <= n; i++) if(d[id] <= n)
				tr[i].add(d[id], x * tmp[i][id] % mod);
//			cerr << a[id] << " " << x << endl;
		}
	}
}
int main() {
//	freopen("ex_data2.in", "r", stdin);
//	freopen("dag.in", "r", stdin);
//	freopen("dag.out", "w", stdout);
	Read(), Init(), Rebuild(), Query();
	return 0;
}