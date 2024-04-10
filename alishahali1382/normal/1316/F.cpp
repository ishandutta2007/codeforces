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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 600010, LOG=20;

ll tav[MAXN];
struct Node{
	ll sum1=0, sum2=0, ans=0;
	int cnt=0;
};

Node combine(Node x, Node y){
	Node z;
	z.sum1=(x.sum1 + y.sum1*tav[x.cnt])%mod;
	z.sum2=(x.sum2*tav[y.cnt] + y.sum2)%mod;
	z.ans=(x.ans*tav[y.cnt] + y.ans*tav[x.cnt] + x.sum1*y.sum2)%mod;
	z.cnt=x.cnt+y.cnt;
	return z;
}

ll n, m, k, u, v, x, y, t, a, b;
ll A[MAXN];
Node seg[MAXN<<2];
ll lazy1[MAXN<<2], lazy2[MAXN<<2];
int Q[MAXN][2];
map<int, int> mp;
vector<int> comp;

void add_lazy(int id, ll val1, ll val2){
	lazy1[id]=lazy1[id]*val1%mod;
	lazy2[id]=lazy2[id]*val2%mod;
	seg[id].sum1=seg[id].sum1*val1%mod;
	seg[id].sum2=seg[id].sum2*val1%mod;
	seg[id].ans=seg[id].ans*val1*val2%mod;
}

void shift(int id){
	if (lazy1[id]==1 && lazy2[id]==1) return ;
	add_lazy(id<<1, lazy1[id], lazy2[id]);
	add_lazy(id<<1 | 1, lazy1[id], lazy2[id]);
	lazy1[id]=lazy2[id]=1;
}

void Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id].sum1=seg[id].sum2=val;
		seg[id].ans=0;
		seg[id].cnt=(val>0);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, pos, val);
	Set(id<<1 | 1, mid, tr, pos, val);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

void Mul(int id, int tl, int tr, int l, int r, ll val1, ll val2){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val1, val2);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Mul(id<<1, tl, mid, l, r, val1, val2);
	Mul(id<<1 | 1, mid, tr, l, r, val1, val2);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

void Add(int x){
	int pos=mp[x]++;
	//debug2(pos, x)
	//Mul(1, 0, MAXN, 0, pos, 1, 2);
	//Mul(1, 0, MAXN, pos, MAXN, 2, 1);
	Set(1, 0, MAXN, pos, x);
}

void Rem(int x){
	int pos=--mp[x];
	//debug(pos)
	Set(1, 0, MAXN, pos, 0);
	//Mul(1, 0, MAXN, 0, pos, 1, (mod+1)/2);
	//Mul(1, 0, MAXN, pos, MAXN, (mod+1)/2, 1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fill(lazy1, lazy1+MAXN*4, 1);
	fill(lazy2, lazy2+MAXN*4, 1);
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*2%mod;
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], comp.pb(A[i]);
	cin>>m;
	for (int i=1; i<=m; i++) cin>>Q[i][0]>>Q[i][1], comp.pb(Q[i][1]);
	sort(all(comp));
	for (int i=comp.size()-1; ~i; i--) mp[comp[i]]=i;
	
	for (int i=1; i<=n; i++) Add(A[i]);
	
	ll inv2=(mod+1)/2, inv2n=1;
	for (int i=0; i<n; i++) inv2n=inv2*inv2n%mod;
	/*
	debug(seg[1].ans)
	return 0;
	*/
	cout<<seg[1].ans*inv2n%mod<<'\n';
	for (int i=1; i<=m; i++){
		Rem(A[Q[i][0]]);
		A[Q[i][0]]=Q[i][1];
		Add(A[Q[i][0]]);
		cout<<seg[1].ans*inv2n%mod<<'\n';
	}
	
	return 0;
}