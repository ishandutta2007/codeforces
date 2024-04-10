// written by aitch
// on 2019 12/17 at 16:05:00
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> net(n);
	rep(_,0,m){
		int u, v, d;
		cin >> u >> v >> d;
		--u, --v;
		net[u] -= d;
		net[v] += d;
	}
	stack<int> pos, neg;
	rep(i,0,n) if(net[i] > 0) pos.push(i);
		else if(net[i] < 0) neg.push(i);

	vector<vector<ll>> ans;

	while(!pos.empty()){
		int v = pos.top(), u = neg.top();
		ll d = min(net[v], -net[u]);
		vector<ll> ls = {u+1,v+1,d};
		ans.emplace_back(ls);
		net[v] -= d;
		net[u] += d;
		if(!net[v]) pos.pop();
		if(!net[u]) neg.pop();
	}
	cout << sz(ans) << endl;
	trav(v, ans){
		trav(x, v) cout << x << " ";
		cout << endl;
	}
}