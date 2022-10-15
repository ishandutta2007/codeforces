#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-10;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef LOCAL
const int MAX = 1e4 + 10;
#else
const int MAX = 1e6 + 10;
#endif
#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

struct matrix {
	ll ar[100][100];
	matrix() {
		ms(ar, 0);
	}
};

matrix operator*(matrix a, matrix b) {
	matrix ans;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			ll res = 0;
			for (int k = 0; k < 100; k++) {
				res = (res + 1LL * a.ar[i][k] * b.ar[k][j])mod;
			}
			ans.ar[i][j] = res;
		}
	}
	return ans;
}

matrix _pow(matrix m, int n) {
	if(n == 0){
		matrix ans;
		for(int i = 0; i < 100; i++)
			ans.ar[i][i] = 1;
		return ans;
	}
	if (n == 1)
		return m;
	matrix ans = _pow(m, n >> 1);
	ans = ans * ans;
	if (n & 1)
		ans = ans * m;
	return ans;
}

void print(matrix m) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << m.ar[i][j] << " ";
		}
		cout << endl;
	}

}

int main() {

	cout.precision(11);
	cout << fixed;
	sync;

#ifdef LOCAL
	input;
#endif

	int n, b, k, x;
	cin >> n >> b >> k >> x;

	int ar[10];
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		ar[a]++;
	}

	matrix tt;

	for (int i = 0; i < x; i++) {
		for(int j = 1; j < 10; j++){
			int q = (i * 10 + j) % x;
			tt.ar[i][q] += ar[j];
		}
	}

	//print(tt);

	tt = _pow(tt, b);

	matrix t;
	t.ar[0][0] = 1;

	//print(t);

	t = t * tt;

	//print(t);

	ll ans = 0;
	for(int i = 0; i < 100; i++)
		if(i % x == k)
			ans += t.ar[0][i];
	cout << ans;

}