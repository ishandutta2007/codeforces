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
const int MAXN = 1000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b;
ll A[MAXN];
ll ps[MAXN];
ll fen[MAXN];
ll ans[MAXN];
ll F[MAXN];
ll I[MAXN];
int sieve[MAXN];
int last[MAXN];
vector<pii> query[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll inv(ll x){
	if (x<MAXN) return I[x];
	return powmod(x, mod-2);
}

void update(int pos, ll val){
	if (!pos) return ;
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]=fen[pos]*val%mod;
}
ll get(int pos){
	ll res=1;
	for (; pos; pos-=pos&-pos) res=res*fen[pos]%mod;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i; j<MAXN; j+=i) sieve[j]=i;
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	for (int i=1; i<MAXN; i++) I[i]=I[i]*F[i-1]%mod;
	I[0]=0;
	
	cin>>n;
	ps[0]=1;
	for (int i=1; i<=n; i++) cin>>A[i], ps[i]=ps[i-1]*A[i]%mod;
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>x>>y;
		ans[i]=ps[y]*inv(ps[x-1])%mod;
		query[y].pb({x, i});
	}
	
	fill(fen, fen+MAXN, 1);
	for (int i=1; i<=n; i++){
		for (int tmp=A[i]; tmp>1;){
			int p=sieve[tmp];
			while (tmp%p==0) tmp/=p;
			update(last[p], p*inv(p-1)%mod);
			last[p]=i;
			update(i, (p-1)*inv(p)%mod);
		}
		ll tmp=get(i);
		for (pii p:query[i]) ans[p.second]*=tmp*inv(get(p.first-1))%mod;
	}
	for (int i=1; i<=m; i++) cout<<ans[i]%mod<<'\n';
	
	return 0;
}