#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
#define lll __int128
typedef long long ll; const int inf=~0u>>1; const ll INF=~0ull>>1;
typedef double lf; typedef long double llf; const lf err=1e-11;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),__=(b);i<__;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,__=(a);i>=__;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(I,0,n)cerr<<(a)[I]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto I:a)cerr<<I<<" "; cerr<<endl;}
#define fi first
#define se second
inline ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
inline lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
template<typename T> inline T sqr(T x){return x*x;}
mt19937 rnd(time(0));
//tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t; //
const int N=100010;
const int mod=(1?1000000007:998244353);
//#define int ll
int n,m;
int a[N],b[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	repeat(i,0,n)cin>>a[i];
	repeat(i,0,m)cin>>b[i];
	sort(a,a+n,greater<int>()),sort(b,b+m);
	ll ans=0;
	if(a[0]>b[0])cout<<-1<<endl,exit(0);
	repeat(i,0,n)ans+=(ll)a[i]*m;
	if(a[0]==b[0]){
		repeat(i,0,m)ans+=b[i]-a[0];
		cout<<ans<<endl;
		exit(0);
	}
	repeat(i,0,m-1)ans+=b[i]-a[0];
	ans+=b[m-1]-a[1];
	cout<<ans<<endl;
	exit(0);
	return 0;
}