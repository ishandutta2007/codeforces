#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=998244353;
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN], cnt[MAXN];
int invec[MAXN];

int Main(){
	ans=0;
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	/*
	for (int r=1; r<=n; r++){
		ll x=A[r], val=0;
		for (int l=r; l; l--){
			ll k=(A[l]+x-1)/x;
			val+=k;
			x=A[l]/k;
			ans+=val;
		}
	}*/
	vector<int> vec;
	ll sum=0;
	for (int i=n; i; i--){
		
//		cerr<<"\n";
//		debug(i)
		
		ll s=A[i];
		cnt[s]++;
		if (!invec[s]){
			invec[s]=1;
			vec.pb(s);
		} 
		vector<pii> vec2;
		for (int x:vec){
			ll ted=cnt[x];
			invec[x]=0;
			cnt[x]=0;
			ll k=(s+x-1)/x;
			sum+=ted*k;
			x=s/k;
			vec2.pb({x, ted});
		}
		vec.clear();
		for (pii p:vec2){
//			debugp(p)
			cnt[p.first]+=p.second;
			if (!invec[p.first]){
				invec[p.first]=1;
				vec.pb(p.first);
			}
		}
//		debugv(vec)
		
		sum%=mod;
		ans+=sum;
	}
	for (int x:vec) invec[x]=cnt[x]=0;
	vec.clear();
	
	for (ll len=1; len<=n; len++) ans-=len*(n-len+1);
	
//	debug(ans)
	ans%=mod;
	if (ans<0) ans+=mod;
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
4
3 2 1 4

1
3
5 4 3

*/