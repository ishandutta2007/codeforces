#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
#define x first
#define y second
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-5;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 200;
#else
const ll MAX = 200;
#endif

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n, d;
	cin >> n >> d;

	vector<ii> vec;
	for(int i = 0; i < n; i++){
		ll a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}

	sort(vec.begin(), vec.end());

	ll sum[n];
	for(int i = 0; i < n; i++){
		sum[i] = (vec[i].second + (i == 0 ? 0 : sum[i - 1]));
	}

	ll ans = 0;

	for(int l = 0, r = 0; r < n; r++){
		while(vec[r].first - vec[l].first >= d)
			l++;
		ans = max(ans, sum[r] - (l == 0 ? 0 : sum[l - 1]));
	}

	cout << ans;

}