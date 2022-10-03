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
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll tav[MAXN], cnt[MAXN];
short mob[MAXN];
vector<int> D[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

ll Get(ll g, ll ab){
	ll res=0;
	for (ll d:D[ab/g]){
		ll lim=(n-1)/g/d;
		ll sum=ab/g/d;
		if (!lim) continue ;
		lim--;
		sum-=2;
		ll tmp=0;
		if (sum<0 || 2*lim<sum) continue ;
		if (sum>lim) sum=2*lim-sum;
		tmp=sum+1;
		
		res+=mob[d]*tmp;
		/*
		debug2(d, tmp)
		debug2(lim, sum)
		cerr<<'\n';
		*/
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	tav[0]=mob[1]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*k%mod;
	for (int i=1; i<MAXN; i++) for (int j=i+i; j<MAXN; j+=i) mob[j]-=mob[i];
	for (int i=1; i<MAXN; i++) for (int j=i; j<MAXN; j+=i) D[j].pb(i);
	/*
	debug(Get(1, 4))
	return 0;
	*/
	for (ll g=1; g<n; g++)
		for (ll ab=2*g; ab<=2*n-2; ab+=g)
			cnt[max(g, ab-n)]+=Get(g, ab);
	
	for (int i=1; i<n; i++) ans=(ans + tav[i]*cnt[i])%mod;
	ans=ans*powmod(k, mod-1-n)%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	
	return 0;
}