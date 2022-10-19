#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 900000
#define M 100000
#define mod 1000000007
#define eps (1e-7)
#define U unsigned int
#define IT set<ques>::iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
I void read(int &x){
	char s=getchar();x=0;while(s<'0'||s>'9') s=Gc(); 
	while(s>='0'&&s<='9') x=x*10+s-48,s=Gc();
}
int n,m,Maxn,x[M+5],y[M+5],c[M+5],t[M+5],dfn[N+5],low[N+5],vis[N+5],scc[N+5],st[N+5],sh,cnt,tot,dh,l,r,mid,pus,Gs[M+5];
struct yyy{int to,z;};map<int,int> G[M+5];vector<int>F[M+5];
struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;/*printf("%d %d\n",x,y);*/}}s,S;
I void tarjan(int x){
	dfn[x]=low[x]=++dh;vis[x]=1;st[++sh]=x;yyy tmp;for(int i=s.h[x];i;i=tmp.z){
		tmp=s.f[i];if(!dfn[tmp.to]) tarjan(tmp.to),low[x]=min(low[x],low[tmp.to]);
		else vis[tmp.to]&&(low[x]=min(low[x],low[tmp.to]));
	}
	if(low[x]==dfn[x]){++tot;while(st[sh+1]^x) scc[st[sh]]=tot,vis[st[sh--]]=0;}
}
I int check(int mid){
	re int i,j;s.head=S.head;Me(dfn,0);dh=tot=0;for(i=1;i<=m;i++) s.h[i+m]=S.h[i+m],t[i]>mid&&(s.add(i+m,i),0);
	for(i=1;i<=cnt;i++)!dfn[i]&&(tarjan(i),0);for(i=1;i<=m;i++) if(scc[i]==scc[i+m]) return 0;return 1; 
}
int main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	re int i,j;read(n);read(m);cnt=2*m+1;for(i=1;i<=m;i++) read(x[i]),read(y[i]),read(c[i]),read(t[i]),Maxn=max(Maxn,t[i]),F[x[i]].push_back(i),F[y[i]].push_back(i);l=-1;r=Maxn+1;
	for(i=1;i<=n;F[i].clear(),i++){
		for(j=0;j<F[i].size();j++) Gs[j]=cnt,S.add(cnt++,F[i][j]),S.add(F[i][j]+m,cnt++),S.add(cnt++,F[i][j]),S.add(F[i][j]+m,cnt++);
		for(j=1;j<F[i].size();j++) S.add(Gs[j],Gs[j-1]),S.add(Gs[j-1]+1,Gs[j]+1),S.add(Gs[j-1]+2,Gs[j]+2),S.add(Gs[j]+3,Gs[j-1]+3);
		for(j=0;j<F[i].size();j++) j&&(S.add(F[i][j]+m,Gs[j-1]),S.add(Gs[j-1]+1,F[i][j]),0),j<F[i].size()-1&&(S.add(F[i][j]+m,Gs[j+1]+2),S.add(Gs[j+1]+3,F[i][j]),0);
	}
	for(i=1;i<=m;i++)!G[x[i]][c[i]]&&(G[x[i]][c[i]]=++pus),F[G[x[i]][c[i]]].push_back(i)/*,printf("%d %d\n",x[i],c[i])*/,!G[y[i]][c[i]]&&(G[y[i]][c[i]]=++pus),F[G[y[i]][c[i]]].push_back(i);
	for(i=1;i<=pus;i++){
		for(j=0;j<F[i].size();j++) Gs[j]=cnt,S.add(cnt++,F[i][j]+m),S.add(F[i][j],cnt++),S.add(cnt++,F[i][j]+m),S.add(F[i][j],cnt++);
		for(j=1;j<F[i].size();j++) S.add(Gs[j],Gs[j-1]),S.add(Gs[j-1]+1,Gs[j]+1),S.add(Gs[j-1]+2,Gs[j]+2),S.add(Gs[j]+3,Gs[j-1]+3);
		for(j=0;j<F[i].size();j++) j&&(S.add(F[i][j],Gs[j-1]),S.add(Gs[j-1]+1,F[i][j]+m),0),j<F[i].size()-1&&(S.add(F[i][j],Gs[j+1]+2),S.add(Gs[j+1]+3,F[i][j]+m),0);
	}s=S;
	while(l+1<r) mid=l+r>>1,(check(mid)?r:l)=mid;if(l==Maxn){printf("No\n");return 0;}printf("Yes\n");printf("%d ",r);
	check(r);for(pus=0,i=1;i<=m;i++) scc[i]>scc[i+m]&&(pus++);printf("%d\n",pus);for(i=1;i<=m;i++) scc[i]>scc[i+m]&&(printf("%d ",i));
}