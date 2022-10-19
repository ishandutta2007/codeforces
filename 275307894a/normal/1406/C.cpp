#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int t,n,m,k,x,y,z,dp[100039],siz[100039],ans,tot,nowx,nowy,cur,sx,sy;
struct yyy{int to,z;}tmp;
struct ljb{
	int head,h[100039];
	yyy f[200039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void dfs1(int x,int last){
	siz[x]=1;
	yyy tmp;
	for(int cur=s.h[x];~cur;cur=tmp.z){
		tmp=s.f[cur];
		if(tmp.to!=last){
			dfs1(tmp.to,x);
			siz[x]+=siz[tmp.to];
			dp[x]=max(dp[x],siz[tmp.to]);
		}
	}
	dp[x]=max(dp[x],n-siz[x]);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&t);
	register int i;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(s.h,-1,sizeof(s.h));
		s.head=0;
		scanf("%d",&n);
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			s.add(x,y);s.add(y,x);
		}
		dfs1(1,0);
		ans=1e9;tot=0;
		nowx=nowy=sx=sy=0;
		for(i=1;i<=n;i++) ans=min(ans,dp[i]);
		for(i=1;i<=n;i++){
			if(dp[i]==ans){
				tot++;
				nowy=nowx;
				nowx=i;
			} 
		} 
		cur=s.h[nowx];
		while(cur!=-1){
			tmp=s.f[cur];
			if(tmp.to!=nowy){
				sx=nowx;sy=tmp.to;
				break;
			}
			cur=tmp.z;
		}
		if(tot==1){
			printf("%d %d\n%d %d\n",sx,sy,sx,sy);
		}
		else{
			printf("%d %d\n%d %d\n",sx,sy,sy,nowy);
		}
	}
}