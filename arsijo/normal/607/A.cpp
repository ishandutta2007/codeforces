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
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-8;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

const int MAX = 2e5 + 4;

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	vector<ii> vec;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}
	sort(vec.begin(), vec.end());
	int dp[n + 1];
	set<ii> s;
	s.insert(make_pair(1000000000, 0));
	dp[0] = 0;
	int ans = 0;
	for(int i = 0; i < (int) vec.size(); i++){
		//cout << "find " << vec[i].first - vec[i].second << endl;
		set<ii>::iterator it = s.upper_bound(make_pair(-(vec[i].first - vec[i].second), INT_MAX));
		dp[i + 1] = dp[it->second] + 1;
		s.insert(make_pair(-vec[i].first, i + 1));
		//cout << i << " " << dp[i + 1] << " " << vec[i].first << endl;
		ans = max(ans, dp[i + 1]);
	}

	cout << n - ans << endl;

}