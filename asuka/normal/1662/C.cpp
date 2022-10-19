#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 105, mod = 998244353;

void inc(int &x, int y) {
	x += y;

	if (x >= mod) x -= mod;
}

int n, m, k, deg[N];

struct mat {
	int dat[N << 1][N << 1];
	mat() {memset(dat, 0, sizeof dat);}
	int* operator[](int i) {return dat[i];}
} Base[17], Final;

mat operator * (mat a, mat b) {
	mat c;

	rep(i, 1, n << 1) rep(j, 1, i) swap(b[i][j], b[j][i]);

	rep(i, 1, n << 1) rep(j, 1, n << 1) rep(k, 1, n << 1) {
		inc(c[i][j], (ll) a[i][k] * b[j][k] % mod);
	}

	return c;
}

struct arr {
	int dat[N << 1];
	arr() {memset(dat, 0, sizeof dat);}
	int& operator[](int i) {return dat[i];}
} Ori;

arr operator * (arr a, mat b) {
	arr c;

	rep(k, 1, n << 1) rep(j, 1, n << 1) inc(c[j], (ll) a[k] * b[k][j] % mod);

	return c;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	k--;

	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		Base[0][u][v] = Base[0][v][u] = Final[u][v] = Final[v][u] = 1;
		deg[u]++; deg[v]++;
	}

	rep(i, 1, n) Base[0][i + n][i] = (mod - deg[i] + 1) % mod, Base[0][i][i + n] = 1, Final[i + n][i] = (mod - deg[i]) % mod;

	rep(i, 1, 16) Base[i] = Base[i - 1] * Base[i - 1];

	int ans = 0;

	rep(i, 1, n) {
		Ori = arr();
		Ori[i] = 1;

		rep(j, 0, 16) if (k >> j & 1) Ori = Ori * Base[j];

		Ori = Ori * Final;
		inc(ans, Ori[i]);
	}

	printf("%d\n", ans);

	return 0;
}