#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
#define vector basic_string
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=100010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
struct vec{
	int x,y,p;
}a[N];
__int128 dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
__int128 sqr2(__int128 a){
	if(a<0)return -a*a;
	return a*a;
}
int n,j=0;
signed main(){
	cin>>n;
	repeat(i,0,n){
		cin>>a[i].x>>a[i].y;
		a[i].p=i+1;
	}
	sort(a,a+n,[](const vec &a,const vec &b){
		return atan2(a.x,a.y)<atan2(b.x,b.y);
	});
	a[n]=a[0];
	//repeat(i,0,n)cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].p<<endl;
	repeat(i,0,n)
	if(sqr2(dot(a[j],a[j+1]))*(dot(a[i],a[i])*dot(a[i+1],a[i+1]))<sqr2(dot(a[i],a[i+1]))*(dot(a[j],a[j])*dot(a[j+1],a[j+1])))
		j=i;
	cout<<a[j].p<<' '<<a[j+1].p<<endl;
	return 0;
}