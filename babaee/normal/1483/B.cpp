#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;

inline int solve() {
	cin >> n;
	vector<int> ans;
	list<deque<pll>> v;
	v.push_back({});

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (v.back().empty() || __gcd(v.back().back().X, x) > 1) v.back().push_back({x, i + 1});
		else v.push_back({{x, i + 1}});
	}

	auto it = v.begin();
	while (v.size() > 1) {
		if (it == v.end()) it = v.begin();
		auto it2 = it;
		it2++;
		
		if (it2 == v.end()) it2 = v.begin();	
	
		if (__gcd(it -> back().X, it2 -> front().X) == 1) {
			ans.push_back(it2 -> front().Y);
			it2 -> pop_front();	
		}

		if (it2 -> empty()) it = v.erase(it2);
		else if (__gcd(it2 -> front().X, it -> back().X) > 1) {
			if (it->size() > it2->size()) {
				while (!it2 -> empty()) it -> push_back(it2 -> front()), it2 -> pop_front();
				v.erase(it2);
			} else {
				while (!it -> empty()) it2 -> push_front(it -> back()), it -> pop_back();
				it = v.erase(it);
			}
		} else it = it2;
	
	}


	while (!v.front().empty() && __gcd(v.front().front().X, v.front().back().X) == 1) {
		ans.push_back(v.front().front().Y);
		v.front().pop_front();
	}
	
	cout << ans.size() << sep;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}