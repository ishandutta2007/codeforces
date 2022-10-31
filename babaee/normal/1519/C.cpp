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
#define int 			    long long

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<int> V[MAXN], ps[MAXN];
int n, S[MAXN], U[MAXN];

inline int solve() {
	for (int i = 0; i < n + 10; i++) ps[i].clear(), V[i].clear();
	ll sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> U[i];
	for (int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		V[U[i]].push_back(s);
		sum += s;
	}


	vector<int> ind_v;
	for (int i = 1; i <= n; i++) {
		sort(all(V[i]));
		ps[i].push_back(0);
		for (int e : V[i]) ps[i].push_back(ps[i].back() + e);
		ind_v.push_back(i);
	}

	sort(all(ind_v), [] (int i, int j) {
		return V[i].size() > V[j].size();		
	});

	for (int i = 1; i <= n; i++) {
		while (!ind_v.empty() && V[ind_v.back()].size() < i) sum -= ps[ind_v.back()].back(), ind_v.pop_back();
		ll ans = sum;
		for (int e : ind_v) {
			ans -= ps[e][V[e].size() % i];
		}

		cout << ans << sep;
	}

	cout << endl;
	
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}