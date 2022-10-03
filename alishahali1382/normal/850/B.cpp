#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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

ll n, m, k, u, v, x, y, t, a, b; // a = delete   b = increase
int A[MAXN*2];
ll cnt[MAXN*2];
ll sum[MAXN*2];
bitset<MAXN> sieve;

int f(ll p){
	int res=p-(x+y-1)/y;
	if (res>=p) return p-1;
	if (res<0) return 0;
	return res;
}

ll calc(int p){
	ll res=0;
	for (ll i=0; i<MAXN; i+=p){
		ll l=i, r=i+p-1, mid=i+f(p);
		
		mid=max(l, mid);
		mid=min(r, mid);
		
		//if (p==2 && r<=100) cerr<<l<<' '<<mid<<' '<<r<<'\n';
		res+=(cnt[mid]-cnt[i])*x;
		res+=((i+p)*(cnt[r]-cnt[mid]) - (sum[r]-sum[mid]))*y;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i*i<MAXN; i++) if (!sieve[i]) for (int j=i*i; j<MAXN; j+=i) sieve.set(j);
	cin>>n>>x>>y;
	for (int i=1; i<=n; i++) cin>>A[i], cnt[A[i]]++;
	for (int i=1; i<MAXN*2; i++) sum[i]=sum[i-1]+cnt[i]*i, cnt[i]+=cnt[i-1];
	
	ll ans=x*n;
	for (int p=2; p<MAXN; p++) if (!sieve[p]) ans=min(ans, calc(p));
	cout<<ans<<'\n';
	
	//debug(calc(17))
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/