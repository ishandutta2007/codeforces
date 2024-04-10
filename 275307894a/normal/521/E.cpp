#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 200000
#define K 20
#define mod 998244353
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Pc(x) putchar(x) 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int Fl[N+5],F[N+5],x[N+5],y[N+5],n,m,k,lcax,lcay,lcas,d[N+5],un,wn,px[N+5],py[N+5],fa[N+5],A[N+5],Ah,B[N+5],Bh,Ansx,Ansy,cnt,C[N+5],Ch,M[N+5][2];
I void read(int &x){char s=Gc();while(s<'0'||s>'9') s=Gc();while(s>='0'&&s<='9') x=x*10+s-48,s=Gc();}I void print(int x){x>9&&(print(x/10),0);Pc(x%10+48);}
I int Getfa(int x){return x==F[x]?x:F[x]=Getfa(F[x]);}
struct yyy{int to,z;}tmp;I void swap(int &x,int &y){x^=y^=x^=y;}
struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s,G;
I void Make(int x,int last){d[x]=d[last]+1;fa[x]=last;yyy tmp;for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^last&&(Make(tmp.to,x),0);}
I int lca(int x,int y){d[x]<d[y]&&(swap(x,y),0);while(d[x]^d[y]) x=fa[x];while(x^y) x=fa[x],y=fa[y];return x;}
I void dfs(int x,int last){
	C[++Ch]=x;if(x==Ansy){
		printf("%d ",Ch);for(int i=1;i<=Ch;i++) print(C[i]),Pc(' ');puts("");Ch--;return;
	}yyy tmp;for(int i=G.h[x];i;i=tmp.z) tmp=G.f[i],tmp.to^last&&(dfs(tmp.to,x),0);Ch--;
}
I void calc(int nx,int ny,int mx,int my){
    re int i,j;puts("YES");Me(Fl,0);lcax=lca(nx,ny);lcay=lca(mx,my);un=nx;while(un^lcax) A[++Ah]=un,un=fa[un];A[++Ah]=lcax;
	for(i=1;i<=Ah/2;i++) swap(A[i],A[Ah-i+1]);un=ny;while(un^lcax) A[++Ah]=un,un=fa[un];
    un=mx;while(un^lcay) B[++Bh]=un,un=fa[un];B[++Bh]=lcay;for(i=1;i<=Bh/2;i++) swap(B[i],B[Bh-i+1]);un=my;while(un^lcay) B[++Bh]=un,un=fa[un];
    for(i=1;i<=Ah;i++)Fl[A[i]]++;for(i=1;i<=Bh;i++) Fl[B[i]]++; if(Ah<Bh) swap(Ah,Bh),swap(A,B);
    for(i=1;i<=Ah;i++) G.add(A[i],A[i%Ah+1]),G.add(A[i%Ah+1],A[i]),M[A[i%Ah+1]][0]=A[i],M[A[i]][1]=A[i%Ah+1];for(i=1;i<=Bh;i++) (M[B[i]][0]^B[i%Bh+1]&&M[B[i]][1]^B[i%Bh+1])&&(G.add(B[i],B[i%Bh+1]),G.add(B[i%Bh+1],B[i]),0);
    for(i=1;i<=n;i++){
    	if(Fl[i]<2) continue;if(Fl[M[i][0]]<2||Fl[M[i][1]]<2)(Ansx?Ansy:Ansx)=i;
	}Ch=0;dfs(Ansx,0);exit(0);
}
I void check(int x,int y){
	un=x;wn=y;d[un]<d[wn]&&(swap(un,wn),0);while(d[un]>d[wn])px[un]&&(calc(x,y,px[un],py[un]),0),px[un]=x,py[un]=y,un=fa[un];
	while(un^wn) px[un]&&(calc(x,y,px[un],py[un]),0),px[wn]&&(calc(x,y,px[wn],py[wn]),0),px[un]=px[wn]=x,py[un]=py[wn]=y,un=fa[un],wn=fa[wn];
}
int main(){
//	freopen("vajrapani.in","r",stdin);freopen("vajrapani.out","w",stdout);
	re int i;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) F[i]=i;for(i=1;i<=m;i++) read(x[i]),read(y[i]),un=Getfa(x[i]),wn=Getfa(y[i]),un^wn&&(F[un]=wn,s.add(x[i],y[i]),s.add(y[i],x[i]),Fl[i]=1);
	for(i=1;i<=n;i++) (F[i]==i)&&(Make(i,0),0);for(i=1;i<=m;i++)!Fl[i]&&(check(x[i],y[i]),0);puts("NO");
}