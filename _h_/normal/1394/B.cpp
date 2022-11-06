#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

bool sings[9][9] = {};
bool pairs[9][9][9][9] = {};
int ins[(int)2e5+1][9][9] = {};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pii>> outs(n);

	rep(_,0,m){
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		outs[u].emplace_back(w, v);
	}
	trav(v, outs){
		sort(all(v));
		rep(i,0,sz(v))
			ins[v[i].second][sz(v)][i]++;
	}
	rep(v,0,n){
		vector<pii> ls;
		rep(s,1,k+1) rep(i,0,s) if(ins[v][s][i] == 1)
			ls.emplace_back(s, i);
			else if(ins[v][s][i] > 1)
				sings[s-1][i] = true;
		rep(j,0,sz(ls)) rep(i,0,j)
			pairs[ls[i].first-1][ls[i].second][ls[j].first-1][ls[j].second] = true;
	}

	int cnt = 0;

	vi vals(k+1);

	function<void(int)> calc = [&](int s){
		if(s == k+1){
			++cnt;
			return;
		}
		rep(i,0,s) if(!sings[s-1][i]){
			rep(j,1,s) if(pairs[j-1][vals[j]][s-1][i]) goto foo;
			vals[s] = i;
			calc(s+1);
			foo: ;
		}
	};
	calc(1);	
	cout << cnt << endl;
}