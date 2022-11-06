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

const int inf = 1e8;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, s;
	cin >> n >> m >> k >> s;

	vector<vi> dist(k, vi(n, inf));
	rep(i,0,n){
		int a;
		cin >> a;
		dist[a-1][i] = 0;
	}

	vector<vi> gr(n);
	rep(_,0,m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	rep(j,0,k){
		queue<int> ko;
		rep(i,0,n) if(dist[j][i]==0) ko.push(i);

		while(!ko.empty()){
			int u = ko.front();
			ko.pop();
			trav(v, gr[u]){
				if(dist[j][v] == inf){
					dist[j][v] = dist[j][u]+1;
					ko.push(v);
				}
			}
		}
	}

	rep(i,0,n){
		vi ls(k);
		rep(j,0,k) ls[j] = dist[j][i];
		sort(all(ls));
		int ans = 0;
		rep(j,0,s) ans += ls[j];
		cout << ans << ' ';
	}
	cout << endl;
}