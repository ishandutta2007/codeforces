#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define M 50000
#define mod 1000000000
#define mod2 39989
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define R(x) (rand()*rand()%x+1)
using namespace std;
int n,m,k,x,y,fl[N+5],Id[N+5],Ih,Ids[N+5],Is,W[N+5],now,tot,fa[N+5],lcas,nowx,nowy;ll pus,ans,d[N+5],de[N+5],Maxn[N+5],Q[N+5];
struct yyy{int to,z;}tmp;
struct ljb{
	int head,h[N+5];yyy f[N+5<<1];
	I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s;
I void dfs(int x,int last){
	yyy tmp;fa[x]=last;d[x]=d[last]+W[x];de[x]=de[last]+1;d[x]>=d[tot]&&(tot=x);for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^last&&!fl[tmp.to]&&(dfs(tmp.to,x),0);
}
I void swap(int &x,int &y){x^=y^=x^=y;}
int main(){
//	freopen("attack.in","r",stdin);freopen("attack.out","w",stdout);
	re int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&W[i]);for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);
	dfs(1,0);now=tot;d[tot]=0;dfs(tot,0);ans=d[tot];nowx=now;nowy=tot;de[nowx]<de[nowy]&&(swap(nowx,nowy),0);while(de[nowx]^de[nowy]) nowx=fa[nowx];
	while(nowx^nowy) nowx=fa[nowx],nowy=fa[nowy];lcas=nowx;nowx=now;while(nowx^lcas) Id[++Ih]=nowx,nowx=fa[nowx];Id[++Ih]=lcas;
	nowx=tot;while(nowx^lcas) Ids[++Is]=nowx,nowx=fa[nowx];for(i=Is;i;i--) Id[++Ih]=Ids[i];
	for(i=1;i<=Ih;i++) fl[Id[i]]=1;
	for(i=1;i<=Ih;i++){
		for(j=s.h[Id[i]];j;j=tmp.z){
			tmp=s.f[j];if(fl[tmp.to]) continue;tot=tmp.to;d[tot]=0;dfs(tot,0);Maxn[i]=max(Maxn[i],d[tot]);
			now=tot;d[tot]=0;dfs(tot,0);pus=max(pus,d[tot]+ans);
		}Q[i]=Maxn[i]+d[Id[i]];
	}
	for(i=1;i<=Ih;i++) Q[i]=max(Q[i-1],Q[i]),pus=max(pus,Q[i-1]+Maxn[i]+ans-d[Id[i-1]]);printf("%lld\n",pus);
}