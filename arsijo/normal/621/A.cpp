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
const ll MOD = 51123987;
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


int main() {

	cout.precision(11);
	cout << fixed;
	sync;

#ifdef LOCAL
	input;
#endif

	int n;
	cin >> n;

	ll ans = 0;
	vector<int> vec;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a % 2)
			vec.push_back(a);
		else
			ans += a;
	}
	sort(vec.rbegin(), vec.rend());
	for(int i = 1; i < (int) vec.size(); i += 2)
		ans += vec[i] + vec[i - 1];
	cout << ans;

}