#include<stdio.h>
#include<vector>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
int T,n,ans,o;
char a[N],b[N];
bool vs[N];
vector<int> g[N];
il void dfs(ct x){
	++o,vs[x]=1;
	for(const int &j : g[x]) !vs[j]?dfs(j):void();
}
int main(){ 
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d%s%s",&n,a+1,b+1);
		for(i=1;i<=n;a[i]-='a',b[i]-='a',++i) if(a[i]>b[i]) break;
		if(i<=n){puts("-1");continue;}
		for(i=0;i<26;++i) g[i].clear(),vs[i]=0;ans=0;
		for(i=1;i<=n;++i) g[b[i]].push_back(a[i]),g[a[i]].push_back(b[i]);
		for(i=0;i<26;++i) if(!vs[i]) o=0,dfs(i),ans+=o-1;
		printf("%d\n",ans);
	}
	return 0;
}