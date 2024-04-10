#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int a[maxn],b[maxn],cnt[maxn],m,n,t_case;
bool cur[maxn],flag,vis[maxn];
void dfs(int p){
	cur[p]=vis[p]=true;
	for(ri i=hd[p];i;i=e[i].nxt){
		if(!vis[e[i].to])dfs(e[i].to);
		else if(cur[e[i].to])flag=true;
	}
	cur[p]=false;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		clear(cnt,n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),++cnt[a[i]];
		ri mx=max_element(cnt+1,cnt+n+1)-cnt;
		clear(hd,n),len=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",b+i);
			if(a[i]!=mx&&b[i]!=mx)addedge(b[i],a[i]);
		}
		flag=0;
		clear(vis,n);
		for(ri i=1;i<=n;++i)
			if(!vis[i])
				dfs(i);
		puts(flag?"WA":"AC");
	}
	return 0;
}