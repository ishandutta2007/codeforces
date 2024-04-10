#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
const int LIM=2e5+7;
vector<int>V[LIM];
int odl[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	int ans=0;
	rep(i, n) if(!odl[i]) {
		odl[i]=1;
		queue<int>q;
		q.push(i);
		int ma=V[i].size(), mi=V[i].size();
		while(!q.empty()) {
			int p=q.front(); q.pop();
			ma=max(ma, int(V[p].size()));
			mi=min(mi, int(V[p].size()));
			for(auto j : V[p]) if(!odl[j]) {
				odl[j]=1;
				q.push(j);
			}
		}
		if(ma==mi && ma==2) ++ans;
	}
	cout << ans << '\n';
}