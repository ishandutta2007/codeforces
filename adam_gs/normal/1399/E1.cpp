#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7;
vector<pair<int,ll>>V[LIM];
priority_queue<pair<ll,pair<ll,ll>>>q;
ll dp[LIM], sum;
void DFS(int x, int o) {
	if(o!=-1 && V[x].size()==1) dp[x]=1;
	for(auto i : V[x]) if(i.st!=o) DFS(i.st, x);
	for(auto i : V[x]) if(i.st!=o) {
		q.push({dp[i.st]*((i.nd+1)/2), {i.nd/2, dp[i.st]}});
		sum+=dp[i.st]*i.nd;
		dp[x]+=dp[i.st];
	}
}
void solve() {
	while(!q.empty()) q.pop();
	int n;
	ll s;
	cin >> n >> s;
	sum=0;
	rep(i, n) {
		V[i].clear();
		dp[i]=0;
	}
	rep(i, n-1) {
		int a, b, w;
		cin >> a >> b >> w; --a; --b;
		V[a].pb({b, w});
		V[b].pb({a, w});
	}
	DFS(0, -1);
	int ans=0;
	while(sum>s) {
		ll ile=q.top().st, waga=q.top().nd.st, d=q.top().nd.nd;
		q.pop();
		sum-=ile;
		q.push({d*((waga+1)/2), {waga/2, d}});
		++ans;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}