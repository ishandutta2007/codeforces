///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

namespace dbgcrap{
	template<class T>
	ostream& operator<<(ostream& str, vector<T> vec){
		str << "[";
		if(vec.size()){
			Loop(i,0,vec.size()-1)
				str << vec[i] << ", ";
			str << vec.back();
		}
		str << "]";
		return str;
	}
	template<class T, class U>
	ostream& operator<<(ostream& str, pair<T,U> p){
		return str << "(" << p.first << ", " << p.second << ")";
	}
	void _impl_dbg(){}
	template<class T, class... U> void _impl_dbg(T x, U... y){
		cout << x << ' ';
		_impl_dbg(y...);
	}
	template<class... T> void _dbg(T... x){
		cout << "dbg: ";
		_impl_dbg(x...);
		cout << '\n';
	}
	template<class... T> void _vdbg(T... x){
		cout << "vdbg: ";
		_impl_dbg(x...);
		cout << '\n';
	}
#if defined DBG || defined VRB
#define dbg(...) dbgcrap::_dbg(__VA_ARGS__)
#else
#define dbg(...) NULL
#endif
#ifdef VRB
#define vdbg(...) dbgcrap::_vdbg(__VA_ARGS__)
#else
#define vdbg(...) NULL
#endif
}

struct node
{
	int link=0;
	int next[2]={};
	int child[2]={};
	bool bad=0;
};
vector<node> t;
int new_node(){t.emplace_back(); return t.size()-1;}
int rt;

void add(vector<int> v)
{
	int i = rt;
	for(int x : v){
		if(!t[i].child[x])
			t[i].child[x] = new_node();
		i = t[i].child[x];
	}
	t[i].bad=1;
}

void make_dfa()
{
	queue<pii> q; t[rt].link = -1;
	Loop(i,0,2) if(t[rt].child[i]){
		q.emplace(rt,i);
		t[rt].next[i] = t[rt].child[i];
	} else t[rt].next[i] = rt;
	while(q.size()){
		auto [p, c] = q.front(); q.pop();
		int v = t[p].child[c];
		t[v].link = p!=rt?t[t[p].link].next[c]:rt;
		Loop(i,0,2){
			if(t[v].child[i]){
				q.emplace(v,i);
				t[v].next[i] = t[v].child[i];
			} else t[v].next[i] = t[t[v].link].next[i];
		}
		t[v].bad |= t[p].bad;
	}
}

const int N = 212;

vector<int> bad[N];
pair<int,vector<int>> tran[N];
vector<pair<int,int>> tran1;
vector<pair<int,pii>> tran2;
bool is_bad[2];
int genes, trans, bads, mgenes;
const ll inf = 1e15;
ll dp[N][N][N];

set<tuple<ll,int,int,int>> s;

void up(int a, int i, int j, ll d)
{
	vdbg("trying",a,i,j,d);
	if(d < dp[a][i][j]){
		dbg("up",a,i,j,d);
		s.erase({dp[a][i][j], a, i, j});
		dp[a][i][j] = d;
		s.insert({dp[a][i][j], a, i, j});
	}
}

void dfs(int v, vector<int> vec){
	dbg("t",v,vec,pii(t[v].next[0],t[v].next[1]),t[v].bad);
	vec.push_back(0);
	if(t[v].child[0]) dfs(t[v].child[0],vec);
	vec.back()=1;
	if(t[v].child[1]) dfs(t[v].child[1],vec);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> genes >> trans >> bads; mgenes=genes;
	Loop(i,0,trans){
		int a, k;
		cin >> a >> k;
		while(k--){
			int x;
			cin >> x;
			tran[i].second.push_back(x);
		}
		tran[i].first = a;
	}
	rt = new_node();
	Loop(i,0,bads){
		int k;
		cin >> k;
		while(k--){
			int x;
			cin >> x;
			bad[i].push_back(x);
		}
		if(bad[i].size()==1 && bad[i][0] == 0) is_bad[0] = 1;
		if(bad[i].size()==1 && bad[i][0] == 1) is_bad[1] = 1;
		add(bad[i]);
	}
	make_dfa();
	#if defined DBG || defined VRB
	dfs(0,{});
	#endif
	Loop(i,0,trans){
		while(tran[i].second.size() > 2){
			tran2.emplace_back(tran[i].first, pii{genes, tran[i].second.back()});
			tran[i].second.pop_back();
			tran[i].first = genes;
			genes++;
		}
		if(tran[i].second.size()==2)
			tran2.push_back({tran[i].first, pii{tran[i].second[0], tran[i].second[1]}});
		if(tran[i].second.size()==1)
			tran1.push_back({tran[i].first, tran[i].second[0]});
	}
	dbg("tran1:",tran1);
	dbg("tran2:",tran2);
	Loop(i,0,N) Loop(j,0,N) Loop(k,0,N) dp[i][j][k]=inf;
	Loop(z,0,2){
		if(is_bad[z]) continue;
		Loop(i,0,t.size()){
			int j = t[i].next[z];
			if(!t[i].bad && !t[j].bad){
				dp[z][i][j] = 1;
				s.emplace(1,z,i,j);
				dbg("dp1:",z,i,j);
			}
		}
	}
	while(s.size()){
		auto [d, z, i, j] = *s.begin();
		s.erase(s.begin());
		for(auto [a, b] : tran1)
			if(b == z)
				up(a,i,j,d);
		for(auto [a, p] : tran2){
			auto [x, y] = p;
			if(x == z){
				Loop(v,0,t.size()){
					ll d = dp[x][i][j]+dp[y][j][v];
					up(a,i,v,d);
				}
			}
			if(y == z){
				Loop(v,0,t.size()){
					ll d = dp[x][v][i]+dp[y][i][j];
					up(a,v,j,d);
				}
			}
		}
	}
	Loop(i,2,mgenes){
		ll ans = inf;
		Loop(v,0,t.size()) ans = min(ans, dp[i][0][v]);
		if(ans==inf) cout << "YES\n";
		else cout << "NO " << ans << '\n';
	}
}