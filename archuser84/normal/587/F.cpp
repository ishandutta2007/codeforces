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
	template<class... T> int _dbg(T... x){
		cout << "dbg: ";
		_impl_dbg(x...);
		cout << endl;
		return 0;
	}
#ifdef DBG
#define dbg(...) dbgcrap::_dbg(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
}

const int S = 310;
const int N = 100'010+S;
int ql[N], qr[N]; ll qans[N];
vector<int> vqry[N];
string s[N];
ll ps[N];
int n, q;

namespace sqrtd{ // square root daemon haha
	ll a[N], b[N/S];

	ll get(int r){ //O(1)
		return a[r]+b[r/S];
	}
	void add(int i, ll x){ // O(sqrt)
		++i;
		while(i%S) a[i++] += x;
		Loop(j,i/S,N/S) b[j] += x;
	}
}

namespace aho{
	struct node {
		vector<int> leaf;
		vector<int> contain;
		vector<int> A;
		int child[26]={};
		int next[26]={};
		int link=0;
		int val=0;
	} t[N]; int ts = 1;

	void add(int j)
	{
		int i = 0;
		for(char c : s[j]){
			t[i].contain.push_back(j);
			c -= 'a';
			if(!t[i].child[c]) t[i].child[c] = ts++;
			i = t[i].child[c];
		}
		t[i].contain.push_back(j);
		t[i].leaf.push_back(j);
	}

	void make_dfa()
	{
		queue<pii> q;
		Loop(i,0,26) if(t[0].child[i]) {
			t[0].next[i] = t[0].child[i];
			q.emplace(0,i);
		}
		t[0].link = -1;
		while(q.size()){
			auto [p, c] = q.front(); q.pop();
			int v = t[p].child[c];
			t[v].link = p? t[t[p].link].next[c]: 0;
			Loop(i,0,26) t[v].next[i] = t[v].child[i]? t[v].child[i]: t[t[v].link].next[i];
			t[t[v].link].A.push_back(v);
			Loop(i,0,26) if(t[v].child[i]) q.emplace(v,i);
		}
	}

	void addval(int j, int x){
		int i = 0;
		t[0].val += x;
		for(char c : s[j]){
			c -= 'a';
			i = t[i].child[c];
			t[i].val += x;
		}
	}


	ll dfs1(int v)
	{
		ll sum=t[v].val;
		for(int u : t[v].A)
			sum += dfs1(u);
		for(int i : t[v].leaf)
			ps[i] += sum;
		return sum;
	}
	void dfs2(int v)
	{
		for(int i : t[v].leaf)
			sqrtd::add(i,1);
		for(int i : t[v].contain) if(s[i].size() <= S) for(int q : vqry[i]){
			ll x = sqrtd::get(qr[q]) - sqrtd::get(ql[q]);
			dbg("adding",x,"to",q,"in",v);
			qans[q] += x;
		}
		for(int u : t[v].A)
			dfs2(u);
		for(int i : t[v].leaf)
			sqrtd::add(i,-1);
	}

	void dfsdbg(int v, string s){
		dbg("s:",s);
		dbg("A:",t[v].A);
		dbg("con:",t[v].contain);
		dbg("leaf:",t[v].leaf);
		dbg("next:",vector<int>(t[v].next,t[v].next+26));
		dbg("link:",t[v].link);
		dbg();
		Loop(i,0,26)
			if(t[v].child[i])
				dfsdbg(t[v].child[i], s + char(i+'a'));
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> q;
	Loop(i,0,n){
		cin >> s[i];
		aho::add(i);
	}
	aho::make_dfa();
	#ifdef DBG
	aho::dfsdbg(0,"");
	#endif
	Loop(i,0,q){
		int v;
		cin >> ql[i] >> qr[i] >> v; --ql[i];
		vqry[v-1].push_back(i);
	}
	Loop(i,0,n) dbg("vqry",i,":",vqry[i]);
	Loop(i,0,n){
		if(s[i].size() > S){
			aho::addval(i,1);
			fill(ps,ps+N,0);
			aho::dfs1(0);
			{
				ll x = 0;
				Loop(i,0,N){
					x = x+ps[i];
					ps[i] = x-ps[i];
				}
			}
			dbg("ps for",i,vector<ll>(ps,ps+10));
			for(int q : vqry[i]){
				qans[q] = ps[qr[q]] - ps[ql[q]];
			}
			aho::addval(i,-1);
		}
	}
	aho::dfs2(0);
	Loop(i,0,q) cout << qans[i] << '\n';
}