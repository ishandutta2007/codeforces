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

const int N = 100'010;
const int M = 1010;
bitset<M> prm;
int st[N], ft[N];
int b[N], a[N];
int n, m;

namespace seg
{
	bitset<M> t[262144];
	int lzy[262144];

	void tag(int i, int x){
		if(!x) return;
		lzy[i] = (lzy[i]+x)%m;
		t[i] = (t[i]<<M-m+x>>M-m) ^ (t[i]>>m-x);
	}

	void ppg(int i){
		tag(2*i+1, lzy[i]);
		tag(2*i+2, lzy[i]);
		lzy[i] = 0;
	}

	void add(int l, int r, int x, int i=0, int b=0, int e=N){
		if(l <= b && e <= r) return tag(i,x);
		if(r <= b || e <= l) return;
		ppg(i);
		add(l,r,x,2*i+1,b,(b+e)/2);
		add(l,r,x,2*i+2,(b+e)/2,e);
		t[i]=t[2*i+1]|t[2*i+2];
	}

	bitset<M> get(int l, int r, int i=0, int b=0, int e=N){
		if(l <= b && e <= r) return t[i];
		if(r <= b || e <= l) return {};
		ppg(i);
		return get(l,r,2*i+1,b,(b+e)/2)|get(l,r,2*i+2,(b+e)/2,e);
	}

	void init(int i=0, int b=0, int e=N){
		if(e-b==1){t[i][a[b]]=1;return;}
		init(2*i+1,b,(b+e)/2);
		init(2*i+2,(b+e)/2,e);
		t[i]=t[2*i+1]|t[2*i+2];
	}
}

vector<int> A[N];
void dfs(int v, int p, int& t){
	st[v] = t++;
	a[st[v]] = b[v];
	for(int u : A[v])
		if(u!=p)
			dfs(u,v,t);
	ft[v] = t;
}

int main()
{
	prm.set(); prm[0]=prm[1]=0;
	for(int x = 2; x < M; ++x){
		if(!prm[x]) continue;
		for(int y = x*x; y < M; y += x)
			prm[y]=0;
	}

	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop(i,0,n) cin >> b[i], b[i]%=m;
	Loop(i,1,n){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	dfs(0,-1,*new int(0));
	seg::init();
	int q;
	cin >> q;
	while(q--)
	{
		int t, v;
		cin >> t >> v; --v;
		if(t==1){
			int x;
			cin >> x; x %= m;
			seg::add(st[v], ft[v], x);
		} else {
			cout << (seg::get(st[v], ft[v])&prm).count() << '\n';
		}
	}
}