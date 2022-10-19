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
using namespace std;

const int N = 200'010;
int a[N], b[N], c[N], d[N];
int n;

namespace seg
{
	set<pii> dirtydeedsdonedirtcheap[N];
	pii t[N<<2];

	void init(int i=0, int b=0, int e=N){
		if(e-b==1) {t[i] = dirtydeedsdonedirtcheap[b].size()? *dirtydeedsdonedirtcheap[b].begin(): pii{N, -1}; return;}
		init(2*i+1, b, (b+e)/2);
		init(2*i+2, (b+e)/2, e);
		t[i] = min(t[2*i+1], t[2*i+2]);
	}

	pii getmin(int l, int r, int i=0, int b=0, int e=N){
		if(l <= b && e <= r) return t[i];
		if(r <= b || e <= l) return {N, -1};
		return min(getmin(l,r,2*i+1,b,(b+e)/2),getmin(l,r,2*i+2,(b+e)/2,e));
	}

	void erase(int p, int i=0, int b=0, int e=N){
		if(e-b == 1) {dirtydeedsdonedirtcheap[b].erase(dirtydeedsdonedirtcheap[b].begin()); t[i] = dirtydeedsdonedirtcheap[b].size()? *dirtydeedsdonedirtcheap[b].begin(): pii{N, -1}; return;}
		if(p < (b+e)/2) erase(p,2*i+1,b,(b+e)/2);
		else            erase(p,2*i+2,(b+e)/2,e);
		t[i] = min(t[2*i+1], t[2*i+2]);
	}
}

void comp(int* a, int* b){
	vector<int> wonderofU;
	Loop(i,0,n+1) wonderofU.push_back(a[i]);
	Loop(i,0,n+1) wonderofU.push_back(b[i]);
	sort(wonderofU.begin(), wonderofU.end());
	wonderofU.resize(unique(wonderofU.begin(), wonderofU.end()) - wonderofU.begin());
	Loop(i,0,n+1) a[i] = lower_bound(wonderofU.begin(), wonderofU.end(), a[i]) - wonderofU.begin();
	Loop(i,0,n+1) b[i] = lower_bound(wonderofU.begin(), wonderofU.end(), b[i]) - wonderofU.begin();
}

int par[N];

void bfs(){
	queue<int> q;
	c[N-1] = d[N-1] = 0;
	q.push(N-1);
	while(q.size()){
		int v = q.front(); q.pop();
		int x = c[v], y = d[v];
		for(;;){
			auto [_, u] = seg::getmin(0, x+1);
			if(y < _) break;
			seg::erase(a[u]);
			q.push(u);
			par[u] = v;
		}
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	comp(a, c); comp(b, d);
	Loop(i,0,n) seg::dirtydeedsdonedirtcheap[a[i]].insert({b[i], i});
	seg::init();
	par[n-1] = -1;
	bfs();
	if(par[n-1] == -1) Kill(-1);
	vector<int> ans;
	for(int v = n-1; v != N-1; v = par[v]) ans.push_back(v);
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int x : ans) cout << x+1 << ' ';
	cout << '\n';
}