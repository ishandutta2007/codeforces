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

#define int ll

const int N = 1e5+10;

struct node
{
	pll v={}; // cnt, sum
	int l=0, r=0;
};

vector<node> t;

int new_node(){return t.emplace_back(), t.size()-1;}

void merge(int i){
	if(!t[i].l) {t[i].v = t[t[i].r].v; return;}
	if(!t[i].r) {t[i].v = t[t[i].l].v; return;}
	if(t[t[i].l].v.first == t[t[i].r].v.first)
		t[i].v = {t[t[i].l].v.first, t[t[i].l].v.second + t[t[i].r].v.second};
	else
		t[i].v = max(t[t[i].l].v, t[t[i].r].v);
}

struct yasds // yet another shokhmatic data structure
{
	vector<int> s;
	int rt;
	yasds(){rt = new_node();}

	void add(int c, int i, int b, int e){
		if(e-b==1){s.push_back(c); t[i].v.first++; t[i].v.second=c; return;}
		if(c < (b+e)/2) add(c,t[i].l?t[i].l:t[i].l=new_node(),b,(b+e)/2);
		else            add(c,t[i].r?t[i].r:t[i].r=new_node(),(b+e)/2,e);
		merge(i);
	} void add(int c){add(c,rt,0,N);}
};

vector<int> A[N];
int c[N];
int ans[N];

yasds* dfs(int v, int p){
	yasds* ans = new yasds;
	for(int u : A[v]){
		if(u != p){
			auto x = dfs(u, v);
			if(ans->s.size() < x->s.size()) swap(ans, x);
			for(auto c : x->s)
				ans->add(c);
		}
	}
	ans->add(c[v]);
	::ans[v] = t[ans->rt].v.second;
	return ans;
}

int n;

signed main()
{
	t.emplace_back();
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) cin >> c[i];
	Loop(i,1,n){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	dfs(0, -1);
	Loop(i,0,n) cout << ans[i] << ' ';
	cout << '\n';
}