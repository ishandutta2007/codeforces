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
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef map<int, int>::iterator mit;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 10000;
//#define DEBUG
#else
const ll MAX = 1e5 + 3;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	vector<ii> a1, b1;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(a < 0)
			a1.push_back(make_pair(a, b));
		else
			b1.push_back(make_pair(a, b));
	}

	sort(a1.rbegin(), a1.rend());
	sort(b1.begin(), b1.end());

	ll ans = 0;
	for(int i = 0; i < (int) min(a1.size(), b1.size()); i++){
		ans += a1[i].second + b1[i].second;
	}

	if(a1.size() > b1.size())
		ans += a1[b1.size()].second;

	if(b1.size() > a1.size())
		ans += b1[a1.size()].second;

	cout << ans;



}