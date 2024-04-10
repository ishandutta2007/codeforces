#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;}
	template <class I> 
	il I A(I x){return x<0?-x:x;}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
const int N=1000005;
int T,n,a[N],b[N],m,col[N],u,v,ans;
vector<int> g[N];
il void dfs(ct x,ct fa){
	for(const auto & i : g[x])
		if(i!=fa) col[i]=col[x]^1,dfs(i,x);
}
int main(){  
	scanf("%d",&n);it i;
	for(i=1;i<n;++i) scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	dfs(1,0);
	for(i=1;i<=n;++i) ans+=col[i];
	printf("%d\n",(ans<n-ans?ans:n-ans)-1);
	return 0;
}