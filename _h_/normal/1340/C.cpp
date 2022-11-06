#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x,v) for(auto &x : (v))
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

typedef bitset<1001> bs;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m, g, r;
	n = 9999;
	m = 10000;
	g = 1000;
	cin >> n >> m;

	vi d(m);
	rep(i,0,m) d[i] = i;
	trav(x, d) cin >> x;
	sort(all(d));

	cin >> g >> r;

	vector<vector<bool>> vis(m, vector<bool>(g+1, false));	

	vector<pii> nx;
	nx.emplace_back(0, g);
	for(int cur = 0; ; cur++){
		int ans = 1e9;
		vector<pii> ko;
		swap(nx, ko);
		if(ko.empty()) break;
		while(!ko.empty()){
			pii pa = ko.back();
			ko.pop_back();
			int i = pa.first, t = pa.second;
			if(vis[i][t]) continue;
			vis[i][t] = true;
			if(d[i] == n) ans = min(ans, g - t);
			if(t == 0 && !vis[i][g]) nx.emplace_back(i,g);
			if(i){
				int di = d[i] - d[i-1];
				if(t >= di && !vis[i-1][t-di]) ko.emplace_back(i-1, t-di);
			}
			if(i+1<m){
				int di = d[i+1] - d[i];
				if(t >= di && !vis[i+1][t-di]) ko.emplace_back(i+1, t-di);
			}
		}
		if(ans < 1e9){
			cout << cur*(r+g) + ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}