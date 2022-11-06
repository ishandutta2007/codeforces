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

struct State;

int n;
vector<vi> gr;
vi par, sub;

vector<vector<State*>> states;

State* loc(int a, int b){
	if(a > b) swap(a,b);
	assert(states[a][b]);
	return states[a][b];
}

ll ans = 0;

struct State {
	int a, b, pa, pb, deg = 0;
	ll rek = 0;

	State(){};

	ll myval(){
		int sa = a==par[pa] ? n - sub[pa] : sub[a],
		    sb = b==par[pb] ? n - sub[pb] : sub[b];
		return (ll) sb * sa;
	}

	template<typename T>
	void trav_nbrs(T f){
		trav(a1, gr[a]) if(a1 != pa){
			f(loc(a1,b), 0);
		}
		trav(b1, gr[b]) if(b1 != pb){
			f(loc(a,b1), 1);
		}
	}

	void init(){
		trav_nbrs([&](State *s, bool foo){
			if(!(s->deg)++){
				if(foo){
					s->pa = pa;
					s->pb = b;
					if(s->a != a) swap(s->pa, s->pb);
				} else {
					s->pa = a;
					s->pb = pb;
					if(s->b != b) swap(s->pa, s->pb);
				}
				s->init();
			}
		});
	}
	void calc(){
		rek += myval();
		ans = max(ans, rek);
		trav_nbrs([&](State *s, bool foo){
			s->rek = max(s->rek, rek);
			if(!--(s->deg)){
				s->calc();
			}
		});
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	cin >> n;

	gr.resize(n);
	rep(_,1,n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	par.resize(n), sub.resize(n,1);
	function<void(int)> dfs = [&](int v){
		trav(u, gr[v]) if(u != par[v]){
			par[u] = v;
			dfs(u);
			sub[v] += sub[u];
		}
	};
	dfs(0);

	states.resize(n, vector<State*>(n));		

	rep(u,0,n) rep(v,0,u){
		states[v][u] = new State();
		states[v][u]->a = v;
		states[v][u]->b = u;
	}

	rep(u,0,n) trav(v,gr[u]) if(v < u){
		auto s = loc(v,u);
		s->pa = u;
		s->pb = v;
		s->init();
	}

	rep(u,0,n) trav(v,gr[u]) if(v < u){
		loc(v, u)->calc();
	}

	cout << ans << endl;
	_Exit(0);
}