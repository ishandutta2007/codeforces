#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
const int LIM=1e5+7;
vector<int>V[LIM];
int r[LIM], dp[LIM], ma[LIM], n, m, ans;
void DFS(int x, int o) {
	if(x && ma[x]<=m && V[x].size()==1) ++ans;
	for(auto i : V[x]) if(i!=o) {
		if(r[i]==1) dp[i]=dp[x]+1;
		ma[i]=max(ma[x], dp[i]);
		DFS(i, x);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	rep(i, n) cin >> r[i];
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	if(r[0]) dp[0]=ma[0]=1;
	DFS(0, 0);
	cout << ans << '\n';
}