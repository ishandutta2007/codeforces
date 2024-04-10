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
const int N=1010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int T,n,m,r[N],c[N];
string s[N];
struct DSU{ //d[x]=d[y]d[x]==d[y]
	int a[N*N];
	void init(int n){iota(a,a+n+1,0);}
	int fa(int x){
		return a[x]==x?x:a[x]=fa(a[x]);
	}
	int &operator[](int x){
		return a[fa(x)];
	}
}d;
int f(int x,int y){return x*m+y;}
set<int> M;
signed main(){
	cin>>n>>m;
	repeat(i,0,n)cin>>s[i];
	d.init(n*m);
	repeat(i,0,n)
	repeat(j,0,m)
	if(s[i][j]=='#'){
		r[i]=1; c[j]=1;
		if(i!=n-1 && s[i+1][j]=='#')
			d[f(i,j)]=d[f(i+1,j)];
		if(j!=m-1 && s[i][j+1]=='#')
			d[f(i,j)]=d[f(i,j+1)];
	}
	bool flag=true;
	
	int aa=*min_element(r,r+n)==0;
	int bb=*min_element(c,c+m)==0;
	if(aa^bb)flag=false;
	
	repeat(i,0,n){
		int pre=-1;
		repeat(j,0,m)
		if(s[i][j]=='#'){
			if(pre==-1)
				pre=j;
			else{
				if(pre!=j-1)
					flag=false;
				pre=j;
			}
		}
	}
	repeat(j,0,m){
		int pre=-1;
		repeat(i,0,n)
		if(s[i][j]=='#'){
			if(pre==-1)
				pre=i;
			else{
				if(pre!=i-1)
					flag=false;
				pre=i;
			}
		}
	}
	
	repeat(i,0,n)
	repeat(j,0,m)
	if(s[i][j]=='#')
		M.insert(d[f(i,j)]);
	if(flag==false)cout<<-1<<endl;
	else cout<<M.size()<<endl;
	return 0;
}