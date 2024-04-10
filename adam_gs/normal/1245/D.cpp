#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e3+7;
int c[LIM], k[LIM], x[LIM], y[LIM], odw[LIM];
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) cin >> x[i] >> y[i];
	rep(i, n) cin >> c[i];
	rep(i, n) cin >> k[i];
	priority_queue<pair<int,pair<int,int>>>q;
	rep(i, n) q.push({-c[i], {i, -1}});
	int ile=0, ans=0;
	vector<int>v;
	vector<pair<int,int>>e;
	while(ile<n) {
		int a=-q.top().st, b=q.top().nd.st, c=q.top().nd.nd; q.pop();
		if(c==-1) {
			if(odw[b]) continue;
			odw[b]=1;
			++ile;
			ans+=a;
			v.pb(b);
			rep(i, n) q.push({(-k[b]-k[i])*(abs(x[b]-x[i])+abs(y[b]-y[i])), {b, i}});
		} else {
			if(odw[c]) continue;
			odw[c]=1;
			++ile;
			ans+=a;
			e.pb({b, c});
			rep(i, n) q.push({(-k[c]-k[i])*(abs(x[c]-x[i])+abs(y[c]-y[i])), {c, i}});
		}
	}
	cout << ans << '\n';
	cout << v.size() << '\n';
	for(auto i : v) cout << i+1 << " ";
	cout << '\n' << e.size() << '\n';
	for(auto i : e) cout << i.st+1 << " " << i.nd+1 << '\n';
}