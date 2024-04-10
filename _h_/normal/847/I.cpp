#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,q,p;
	cin >> n >> m >> q >> p;
	vector<string> v(n);
	trav(s, v) cin >> s;
	vector<vi> vis(n, vi(m));
	rep(i,0,n) rep(j,0,m) if(v[i][j]=='*') vis[i][j]=1;
	vector<vi> noise(n, vi(m));
	rep(i,0,n) rep(j,0,m) if(v[i][j]>='A'&&v[i][j]<='Z'){
		int lvl = q*(v[i][j]-'A'+1);
		vector<pii> seen;
		queue<pair<pii,int>> ko;
		ko.push({{i,j},lvl});
		while(!ko.empty()){
			pii pa = ko.front().first;
			int i = pa.first, j = pa.second, lvl = ko.front().second;
			ko.pop();
			if(min(i,j)<0 || i>=n || j>=m || vis[i][j])
				continue;
			vis[i][j] = 1;
			seen.push_back(pa);
			noise[i][j] += lvl;
			if(lvl>=2)
				rep(t,0,4)
					ko.push({{i+dx[t],j+dy[t]},lvl/2});
		}
		trav(pa, seen) vis[pa.first][pa.second] = 0;
	}
	int cnt = 0;
	rep(i,0,n) rep(j,0,m) if(noise[i][j]>p)
		++cnt;
	cout << cnt << endl;
}