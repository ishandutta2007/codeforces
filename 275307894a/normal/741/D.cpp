#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 500000
#define M 50000
#define mod 1000000000
#define mod2 39989
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int d[N+5],n,m,st[N+5],sh,top[N+5],siz[N+5],son[N+5],fa[N+5],x,W[N+5],F[N+5<<4],Ans[N+5];char c;
struct yyy{int to,z;};
struct ljb{
	int head,h[N+5];yyy f[N+5];
	I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s;
I void Make(int x,int last){
	yyy tmp;d[x]=d[last]+1;fa[x]=last;siz[x]=1;W[x]^=W[last];for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],Make(tmp.to,x),siz[x]+=siz[tmp.to],siz[son[x]]<siz[tmp.to]&&(son[x]=tmp.to);
}
I void insert(int x){//printf("%d\n",x);
	yyy tmp;F[W[x]]=max(d[x],F[W[x]]);st[++sh]=W[x];for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],insert(tmp.to);
}
I void find(int x,int id){//printf("%d\n",x);
	yyy tmp;int i;for(i=0;i<=21;i++)Ans[id]=max(Ans[id],d[x]+F[W[x]^(1<<i)]-d[id]*2);Ans[id]=max(Ans[id],d[x]+F[W[x]]-d[id]*2);
	for(i=s.h[x];i;i=tmp.z) tmp=s.f[i],find(tmp.to,id);
}
I void dfs(int x){//printf("%d\n",x);
	yyy tmp;int i,lasttop=sh;for(i=s.h[x];i;i=tmp.z){
		tmp=s.f[i];lasttop=sh;if(tmp.to==son[x])continue;dfs(tmp.to),Ans[x]=max(Ans[x],Ans[tmp.to]); while(lasttop^sh) F[st[sh--]]=-1e9;
	}
	if(son[x])dfs(son[x]),Ans[x]=max(Ans[x],Ans[son[x]]);for(i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^son[x]&&(find(tmp.to,x),insert(tmp.to),0);
	for(i=0;i<=21;i++) Ans[x]=max(Ans[x],F[W[x]^(1<<i)]-d[x]);Ans[x]=max(Ans[x],F[W[x]]-d[x]);F[W[x]]=max(F[W[x]],d[x]);st[++sh]=W[x];
}
int main(){
// 	freopen("1.in","r",stdin);
	re int i;scanf("%d",&n);for(i=2;i<=n;i++) scanf("%d",&x),c=Gc(),c=Gc(),W[i]=1<<c-'a',s.add(x,i);Me(F,-0x3f);
	Make(1,0);dfs(1);for(i=1;i<=n;i++) printf("%d ",Ans[i]);
}