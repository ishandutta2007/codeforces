#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-22;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else

#define dbg if(0) cout
#endif

int main() {

	sync;
#ifdef LOCAL
	//rand_test();
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	int ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}

	sort(ar, ar + n);

	int ans = 0;
	for(int i = n - 1; i >= 0 && m > 0; i--){
		m -= ar[i];
		//cout << ar[i] << endl;
		ans++;
	}

	cout << ans;

}