#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
const ll INF=1e18+7;
vector<pair<int,ll>>V[LIM];
ll odl[LIM], T[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c; --a; --b;
		V[a].pb({b, c});
		V[b].pb({a, c});
	}
	priority_queue<pair<ll,pair<int,int>>>q;
	rep(i, n) {
		odl[i]=INF;
		T[i]=-1;
	}
	q.push({0, {0, 0}});
	while(!q.empty()) {
		int p=q.top().nd.st, lst=q.top().nd.nd;
		ll o=-q.top().st;
		q.pop();
		if(odl[p]<INF) continue;
		odl[p]=o;
		T[p]=lst;
		for(auto i : V[p]) if(odl[i.st]==INF) {
			q.push({-o-i.nd, {i.st, p}});
		}
	}
	if(odl[n-1]==INF) {
		cout << -1;
		return 0;
	}
	vector<int>ans;
	ans.pb(n-1);
	int akt=n-1;
	while(akt!=0) {
		akt=T[akt];
		ans.pb(akt);
	}
	reverse(all(ans));
	for(auto i : ans) cout << i+1 << " ";
}