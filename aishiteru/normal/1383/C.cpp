#include<stdio.h>
#include<vector>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1050005,M=30,lim=1<<20;
#define P 1000000007
int T,ans,mx,n,f[N],o[N];
bool vs[N];
char a[N],b[N];
vector<int> g[M];
il void dfs(ct x){
	vs[x]=1,++ans;
	for(const int &j : g[x]) !vs[j]?dfs(j):void();
}
il void ckMax(it &p,ct q){p=(p>q?p:q);}
int main(){
	scanf("%d",&T);it i,s;
	while(T--){
		scanf("%d%s%s",&n,a+1,b+1),ans=mx=0;
		for(i=0;i<20;++i) g[i].clear(),o[i]=vs[i]=0;
		for(i=1;i<=n;++i) if(a[i]!=b[i]) a[i]-='a',b[i]-='a',g[a[i]].push_back(b[i]),g[b[i]].push_back(a[i]),o[a[i]]|=1<<b[i];
		for(i=0;i<20;++i) if(!vs[i]) dfs(i),--ans;
		for(s=0;s<lim;++s) f[s]=0;
		for(f[0]=s=1;s<lim;++s)
			for(i=0;i<20;++i)
				if(s>>i&1) f[s]|=f[s^(1<<i)]&&(!(s&o[i]));
		for(s=lim-1;~s;--s) f[s]?ckMax(mx,__builtin_popcount(s)):void();
		printf("%d\n",ans+20-mx);
	}
	return 0;
}