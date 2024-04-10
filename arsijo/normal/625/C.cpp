#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
template<typename T> T sqr(T a) {
	return a * a;
}
#define endl "\n"
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
#define DEBUG
#endif

#ifdef DEBUG
#define db 1
#else
#define db 0
#endif
#define dbg if(db) cout

int main() {

	cout.precision(11);
	cout << fixed;
	sync;

#ifdef LOCAL
	input;
#endif

	int n, k;
	cin >> n >> k;

	int ar[n][n];
	int next = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k - 1; j++)
			ar[i][j] = ++next;
	}

	for(int i = 0; i < n; i++){
		for(int j = k - 1; j < n; j++){
			ar[i][j] = ++next;
		}
	}

	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += ar[i][k - 1];
	cout << sum << endl;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}

}