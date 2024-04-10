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
const int MAXN=100010, LOG=20;

ll mod, phi;

struct Segment{
	ll seg[MAXN<<2], lazy[MAXN<<2];
	Segment(){
		memset(seg, 0, sizeof(seg));
		fill(lazy, lazy+4*MAXN, 1);
	}
	void add_lazy(int id, ll val){
		lazy[id]=lazy[id]*val%mod;
		seg[id]=seg[id]*val%mod;
	}
	void shift(int id){
		if (lazy[id]==1) return ;
		add_lazy(id<<1, lazy[id]);
		add_lazy(id<<1 | 1, lazy[id]);
		lazy[id]=1;
	}
	void Set(int id, int tl, int tr, int pos, ll val){
		if (pos<tl || tr<=pos) return ;
		if (tr-tl==1){
			seg[id]=val;
			return ;
		}
		shift(id);
		int mid=(tl+tr)>>1;
		Set(id<<1, tl, mid, pos, val);
		Set(id<<1 | 1, mid, tr, pos, val);
		seg[id]=(seg[id<<1] + seg[id<<1 | 1])%mod;
	}
	void Mul(int id, int tl, int tr, int l, int r, ll val){
		if (r<=tl || tr<=l) return ;
		if (l<=tl && tr<=r){
			add_lazy(id, val);
			return ;
		}
		shift(id);
		int mid=(tl+tr)>>1;
		Mul(id<<1, tl, mid, l, r, val);
		Mul(id<<1 | 1, mid, tr, l, r, val);
		seg[id]=(seg[id<<1] + seg[id<<1 | 1])%mod;
	}
	ll Get(int id, int tl, int tr, int l, int r){
		if (r<=tl || tr<=l) return 0;
		if (l<=tl && tr<=r) return seg[id];
		shift(id);
		int mid=(tl+tr)>>1;
		return Get(id<<1, tl, mid, l, r) + Get(id<<1 | 1, mid, tr, l, r);
	}
} seg1, seg2;

struct Fenwick{
	int fen[MAXN];
	Fenwick(){
		memset(fen, 0, sizeof(fen));
	}
	void add(int pos, int val){
		for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
	}
	void Add(int l, int r, int val){
		add(l, +val);
		add(r, -val);
	}
	int get(int pos){
		int res=0;
		for (; pos; pos-=pos&-pos) res+=fen[pos];
		return res;
	}
} fen[9];

ll n, m, q, u, v, x, y, t, l, r;
ll A[MAXN];
vector<int> prime;

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

int get(int x, int p){
	if (x%p) return 0;
	return 1 + get(x/p, p);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i; j<MAXN; j+=i) sieve[j]=i;
	cin>>n>>mod;
	ll tmp=phi=mod;
	for (int i=2; i*i<=mod; i++) if (tmp%i==0){
		prime.pb(i);
		while (tmp%i==0) tmp/=i;
	}
	if (tmp>1) prime.pb(tmp);
	for (int p:prime) phi=phi/p*(p-1);
	m=prime.size();
	
	for (int i=1; i<=n; i++){
		cin>>A[i];
		tmp=A[i];
		for (int j=0; j<m; j++){
			int p=prime[j], t=0;
			while (tmp%p==0) tmp/=p, t++;
			fen[j].Add(i, i+1, t);
		}
		seg1.Set(1, 1, n+1, i, A[i]);
		seg2.Set(1, 1, n+1, i, tmp);
	}
	cin>>q;
	while (q--){
		cin>>t;
		if (t==3){
			cin>>l>>r;
			ll res=seg1.Get(1, 1, n+1, l, r+1)%mod;
			if (res<0) res+=mod; // :)
			cout<<res<<'\n';
			continue ;
		}
		if (t==2){
			cin>>x>>y;
			for (int j=0; j<m; j++){
				int p=prime[j], t=0;
				while (y%p==0) y/=p, t++;
				fen[j].Add(x, x+1, -t);
			}
			y=seg2.Get(1, 1, n+1, x, x+1)*powmod(y, phi-1)%mod;
			seg2.Set(1, 1, n+1, x, y);
			
			for (int j=0; j<m; j++) y=y*powmod(prime[j], fen[j].get(x))%mod;
			seg1.Set(1, 1, n+1, x, y);
			continue ;
		}
		
		cin>>l>>r>>x;
		r++;
		seg1.Mul(1, 1, n+1, l, r, x);
		for (int j=0; j<m; j++){
			int p=prime[j], t=0;
			while (x%p==0) x/=p, t++;
			fen[j].Add(l, r, t);
		}
		seg2.Mul(1, 1, n+1, l, r, x);
	}
	
	return 0;
}