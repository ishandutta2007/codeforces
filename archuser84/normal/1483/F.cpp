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

const int alpha = 26;

struct node
{
	vector<int> A;
	int link=0;
	int next[alpha]={};
	int child[alpha]={};
	int par;
	int st, ft;
	int len = 0;
	bool bad=0;
};
vector<node> t;
int new_node(){t.emplace_back(); return t.size()-1;}
int rt;

void add(string s)
{
	int i = rt;
	int len = 0;
	for(char x : s){
		x -= 'a';
		if(!t[i].child[x])
			t[i].child[x] = new_node();
		i = t[i].child[x];
		t[i].len = ++len;
	}
	t[i].bad=1;
}

void make_dfa()
{
	queue<pii> q; t[rt].link = -1; t[rt].par = rt;
	Loop(i,0,alpha) if(t[rt].child[i]){
		q.emplace(rt,i);
		t[rt].next[i] = t[rt].child[i];
	} else t[rt].next[i] = rt;
	while(q.size()){
		auto [p, c] = q.front(); q.pop();
		int v = t[p].child[c];
		t[v].link = p!=rt?t[t[p].link].next[c]:rt;
		Loop(i,0,alpha){
			if(t[v].child[i]){
				q.emplace(v,i);
				t[v].next[i] = t[v].child[i];
			} else t[v].next[i] = t[t[v].link].next[i];
		}
		t[v].par = t[t[v].link].bad? t[v].link: t[t[v].link].par;
		t[t[v].link].A.push_back(v);
	}
}

void dfs(int v, int& tm)
{
	t[v].st = tm++;
	for(int u : t[v].A){
		dfs(u,tm);
	}
	t[v].ft = tm;
}

void ddfs(int v)
{
	static string s;
	dbg("t",v,s,t[v].A,t[v].st,t[v].ft);
	Loop(i,0,alpha){
		if(!t[v].child[i]) continue;
		s += char(i+'a');
		ddfs(t[v].child[i]);
		s.pop_back();
	}
}

const int N = 1e6+10;
string s[N];
int n;

int count(string s)
{
	vector<int> vec;
	int i = 0;
	for(char c : s){
		i = t[i].child[c-'a'];
		vec.push_back(i);
	}
	vector<pii> a, b;
	int mn = N;
	reverse(vec.begin(), vec.end());
	i = s.size()-1;
	for(int v : vec){
		int p = t[v].bad && i<s.size()-1? v: t[v].par;
		int tmp = i+1-t[p].len;
		--i;
		if(p==rt) continue;
		if(tmp >= mn) {
			b.emplace_back(t[p].st, p);
		} else {
			mn = tmp;
			a.emplace_back(t[p].ft, p);
			p = t[p].par;
			b.emplace_back(t[p].st, p);
		}
	}
	b.emplace_back(t[rt].st, rt);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end()); reverse(b.begin(), b.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	dbg("count",s);
	dbg("a",a);
	dbg("b",b);
	int ans = 0;
	for(auto [st, v] : b){
		while(a.size() && t[a.back().second].ft > st){
			if(t[a.back().second].st > st) ++ans;
			a.pop_back();
		}
	}
	ans += a.size();
	dbg(ans);
	return ans;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	rt = new_node();
	cin >> n;
	Loop(i,0,n) cin >> s[i];
	Loop(i,0,n) add(s[i]);
	ll ans = 0;
	make_dfa(); dfs(rt,*new int(0));
	#ifdef DBG
	ddfs(rt);
	#endif
	Loop(i,0,n) ans += count(s[i]);
	cout << ans << '\n';
}