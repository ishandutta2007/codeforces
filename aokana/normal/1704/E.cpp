#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=1010,mod=998244353;
struct edge{
	int to,nxt;
}e[maxn<<1];
int deg[maxn],hd[maxn],len;
inline void addedge(int fr,int to){
	++deg[to];
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
ll a[maxn],b[maxn];
bool vis[maxn][maxn];
int m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i){
			deg[i]=hd[i]=0;
			clear(vis[i],n);
		}
		len=0;
		for(ri i=1;i<=n;++i){
			scanf("%lld",a+i),b[i]=a[i];
			fill(vis[i]+1,vis[i]+min(a[i],(ll)n)+1,1);
		}
		for(ri i=1,x,y;i<=m;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		vector<int>ord;
		queue<int>q;
		for(ri i=1;i<=n;++i)
			if(!deg[i])
				q.push(i);
		while(q.size()){
			ri p=q.front();q.pop();
			ord.push_back(p);
			for(ri i=hd[p];i;i=e[i].nxt)
				if(!--deg[e[i].to])
					q.push(e[i].to);
		}
		for(ri p:ord)
			for(ri i=hd[p];i;i=e[i].nxt){
				ll cur=0;
				for(ri j=1;j<n;++j)
					if(vis[p][j]){
						ckmax(cur,j+1ll);
						while(cur<=n&&vis[e[i].to][cur])++cur;
						if(cur<=n)ckmax(b[e[i].to],cur),vis[e[i].to][cur]=true;
						else ++b[e[i].to];
					}
				if(b[p]>=n-1){
					b[e[i].to]+=b[p]-n+1;
					while(b[e[i].to]>=mod<<1)b[e[i].to]-=mod;
				}
			}
		printf("%lld\n",b[ord.back()]%mod);
	}
	return 0;
}