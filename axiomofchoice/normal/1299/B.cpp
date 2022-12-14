#include <bits/stdc++.h>
using namespace std; using namespace rel_ops;
/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
#define lll __int128
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
typedef double lf; typedef long double llf; const lf err=1e-7;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(_,0,n)cerr<<(a)[_]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto _:a)cerr<<_<<" "; cerr<<endl;}
#define fi first
#define se second
inline ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
inline lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
template<typename _> inline _ sqr(_ x){return x*x;}
mt19937 rnd(time(0));
//tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t; //
const int N=200010;
const int mod=(1?1000000007:998244353);
//#define int ll
int n;
struct vec{
	lf x,y;
	vec(lf x=0,lf y=0):x(x),y(y){}
	vec operator-(vec b){return vec(x-b.x,y-b.y);}
	vec operator+(vec b){return vec(x+b.x,y+b.y);}
	vec operator*(lf k){return vec(k*x,k*y);}
	bool operator<(vec b)const{return make_pair(x,y)<make_pair(b.x,b.y);}
	lf len(){return sqrt(x*x+y*y);}
	lf sqr(){return x*x+y*y;}
}a[N];
lf cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
lf cross(vec a,vec b,vec c){return cross(a-b,b-c);}
lf dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	if(n%2==1)cout<<"No",exit(0);
	repeat(i,0,n)cin>>a[i].x>>a[i].y,a[i+n]=a[i];
	bool f=1;
	repeat(i,0,n/2)
	if(((a[i]-a[i+1])+(a[i+n/2]-a[i+1+n/2])).len()<err)
		;
	else
		f=0;
	if(f)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}