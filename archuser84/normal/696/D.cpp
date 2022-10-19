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

const int N = 208;

struct node{
	ll cnt=0;
	int c[26]={};
	int f=0;
	int e[26]={};
} t[(1<<27)/sizeof(node)]; int ts = 1;

void add(string s, int x){
	int i = 0;
	for(char c : s){
		if(!t[i].c[c-'a']) t[i].c[c-'a'] = ts++;
		i = t[i].c[c-'a'];
	}
	t[i].cnt += x;
}

void make_dfa(){
	t[0].f = -1;
	queue<tuple<int,int,int>> q;
	Loop(i,0,26) if(t[0].c[i]){
		t[0].e[i] = t[0].c[i];
		q.emplace(0, i, t[0].c[i]);
	}
	while(q.size()){
		auto [p, c, v] = q.front(); q.pop();
		t[v].f = p? t[t[p].f].e[c]: 0;
		 t[v].cnt += t[t[v].f].cnt;
		Loop(i,0,26) t[v].e[i] = t[v].c[i]? t[v].c[i]: t[t[v].f].e[i];
		Loop(i,0,26) if(t[v].c[i]) q.emplace(v, i, t[v].c[i]);
	}
}

ll a[N];
ll n, l;

ll A[N][N];
ll B[N][N];
ll C[N][N];
ll Tmp[N][N];

const ll inf = 1e17;

void mul(ll A[N][N], ll B[N][N], ll C[N][N], int n, int k, int m){
	Loop(i,0,n) Loop(j,0,m) Tmp[i][j]=-inf;
	Loop(i,0,n) Loop(z,0,k) Loop(j,0,m)
		Tmp[i][j] = max(Tmp[i][j], B[i][z]+C[z][j]);
	Loop(i,0,n) Loop(j,0,m) A[i][j] = Tmp[i][j];
}

void mpow(ll e){
	Loop(i,0,N) Loop(j,0,N)  C[i][j]=i==j?0:-inf;
	while(e){
		if(e&1) mul(C,C,A,ts,ts,ts);
		mul(A,A,A,ts,ts,ts);
		e>>=1;
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> l;
	Loop(i,0,n) cin >> a[i];
	Loop(i,0,n){string s; cin>>s; add(s,a[i]);}
	make_dfa();
	Loop(i,1,N) B[i][0] = -inf;
	Loop(i,0,N) Loop(j,0,N) A[i][j] = -inf;
	Loop(i,0,ts) Loop(j,0,26) A[t[i].e[j]][i] = t[t[i].e[j]].cnt;
	mpow(l);
	mul(B,C,B,ts,ts,1);
	ll ans = 0;
	Loop(i,0,ts) ans=max(ans,B[i][0]);
	cout << ans << '\n';
}