#include <bits/stdc++.h>
using namespace std; using namespace rel_ops;
/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
#define lll __int128
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
typedef double lf; typedef long double llf; const lf err=1e-11;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
inline ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
inline lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
template<typename _> inline _ sqr(_ x){return x*x;}
mt19937 rnd(time(0));
//tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t; //
const int N=810;
const int mod=(1?1000000007:998244353);
//#define int ll
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
vector<vec> st;
int judge(const vec &a,vec b,vec c){
	b=b-a; c=c-a;
	return b.y/b.x-b.x<=c.y/c.x-c.x+1e-7;
}
void push(vec &v,int b){
	while((int)st.size()>1
	&& judge(*++st.rbegin(),st.back(),v)) //
		st.pop_back();
	st.push_back(v);
}
map<int,int> Map;
void convex(){
	st.clear();
	for(auto i:Map){//orz(i.fi<<' '<<i.se);
		vec v=vec(i.fi,i.se);
		push(v,1);
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n=read();
	repeat(i,0,n){
		int x=read(),y=read();
		if(!Map.count(x))Map[x]=y;
		else Map[x]=max(Map[x],y);
	}
	//orz(Map.size());
	if(Map.size()<=1){cout<<0<<endl; exit(0);}
	convex();
	cout<<st.size()-1<<endl;
	return 0;
}
/*
3
-1 0
0 -10
1 0
*/