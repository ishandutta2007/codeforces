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

int solve(){

	int n;
	cin >> n;

	vector<vi> ls(60);
	rep(j,0,n){
		ll a;
		cin >> a;
		rep(i,0,60){
			if(a & 1) ls[i].push_back(j);
			a >>= 1;
		}
	}
	vector<vector<pii>> gr(n);
	vector<pii> ab;
	int ex = 0;
	trav(v, ls) if(sz(v) >= 3){
		return 3;
	} else if(sz(v) == 2){
		trav(pa, gr[v[0]]) if(pa.first == v[1]) goto nogood;	
		gr[v[0]].emplace_back(v[1],ex);
		gr[v[1]].emplace_back(v[0],ex);
		ab.emplace_back(v[0], v[1]);
		ex++;
		nogood: ;
	}
	auto dist = [&](int s, int t, int f){
		vi dist(n, 100);
		dist[s] = 0;
		queue<int> ko;
		ko.push(s);
		while(!ko.empty()){
			int v = ko.front(); ko.pop();
			trav(e, gr[v]) if(e.second != f){
				int u = e.first;
				if(dist[u] == 100){
					dist[u] = dist[v]+1;
					ko.push(u);
				}
			}
		}
		return dist[t];
	};
	int ans = 100;
	rep(e,0,ex){
		ans = min(ans, 
		 	dist(ab[e].first, ab[e].second, e)+1);
	}
	return ans==100 ? -1 : ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cout << solve() << endl;
}