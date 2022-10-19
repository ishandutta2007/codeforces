#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=2e5+7, INF=1e9+7;
vector<int>V[LIM];
int odl[LIM];
pair<int,int>kraw[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, n) odl[i]=INF;
	rep(i, m) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
		kraw[i]={a, b};
	}
	odl[0]=0;
	queue<int>q;
	q.push(0);
	while(!q.empty()) {
		int p=q.front(); q.pop();
		for(auto i : V[p]) if(odl[i]==INF) {
			odl[i]=odl[p]+1;
			q.push(i);
		}
	}
	string ans="";
	rep(i, m) {
		if(odl[kraw[i].st]%2==odl[kraw[i].nd]%2) {
			cout << "NO" << '\n';
			return 0;
		}
		ans+=char(odl[kraw[i].st]%2+'0');
	}
	cout << "YES\n";
	cout << ans << '\n';
}