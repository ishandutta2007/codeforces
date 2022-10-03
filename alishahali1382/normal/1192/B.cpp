#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

struct Node{
	ll a, b, c, ab, bc, abc=0;
	Node(ll x=0) : a(x), b(-2*x), c(x), ab(-x), bc(-x){}
};

Node operator +(Node x, Node y){
	Node out;
	out.a=max(x.a, y.a);
	out.b=max(x.b, y.b);
	out.c=max(x.c, y.c);
	out.ab=max(max(x.ab, y.ab), x.a+y.b);
	out.bc=max(max(x.bc, y.bc), x.b+y.c);
	out.abc=max(max(x.abc, y.abc), max(x.ab+y.c, x.a+y.bc));
	return out;	
}

ll n, m, w, u, v, x, y, t, a, b, last;
ll W[MAXN];
int E[MAXN][2];
int id[MAXN];
int stt[MAXN], fnt[MAXN], timer=1;
Node seg[MAXN<<3];
ll lazy[MAXN<<3];
vector<pii> G[MAXN];

void add_lazy(int id, ll val){
	seg[id].a+=val;
	seg[id].b-=2*val;
	seg[id].c+=val;
	seg[id].ab-=val;
	seg[id].bc-=val;
	lazy[id]+=val;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void Add(int id, int tl, int tr, int l, int r, ll val){
	//if (id==1) cerr<<"Add "<<l<<' '<<r<<"  "<<val<<'\n';
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}

void dfs(int node, int par){
	stt[node]=timer++;
	for (pii p:G[node]) if (p.first!=par){
		dfs(p.first, node);
		Add(1, 1, 2*n, stt[p.first], fnt[p.first], W[p.second]);
		id[p.first]=p.second;
	}
	fnt[node]=timer++;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>w;
	for (int i=0; i<n-1; i++){
		cin>>E[i][0]>>E[i][1]>>W[i];
		G[E[i][0]].pb({E[i][1], i});
		G[E[i][1]].pb({E[i][0], i});
	}
	dfs(1, 1);
	for (int i=0; i<n-1; i++) if (stt[E[i][1]]<stt[E[i][0]]) swap(E[i][0], E[i][1]);
	
	while (m--){
		cin>>x>>y;
		x=(x+last)%(n-1);
		y=(y+last)%w;
		Add(1, 1, 2*n, stt[E[x][1]], fnt[E[x][1]], y-W[x]);
		W[x]=y;
		cout<<(last=seg[1].abc)<<'\n';
	}
	
	return 0;
}
/*
4 3 2000
1 2 100
2 3 1000
2 4 1000
2 1030
1 1020
1 890


4 3 2000
1 2 100
2 3 1030
2 4 1000
2 1030
1 1020
1 890


*/