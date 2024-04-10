#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
// head

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n; --n;
	ll T, W; cin >> T >> W;
	vector<pii> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].ff >> a[i].ss;
	sort(all(a));
	priority_queue<ll> q;
	while(!a.empty() && a.back().ff > T)
		q.push(-(a.back().ss-a.back().ff+1)),
		a.pop_back();
	int ans = sz(q);
	while(!q.empty() && T > 0) {
		ll w = -q.top(); q.pop();
		if(w > T) break;
		T -= w;
		while(!a.empty() && a.back().ff > T)
			q.push(-(a.back().ss-a.back().ff+1)),
			a.pop_back();
		ans = min(ans, sz(q));
	}
	cout<<ans+1;
}