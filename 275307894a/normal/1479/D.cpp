#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 300000
#define M 20000
#define mod 1000000007
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
I void read(int &x){char s=Gc();x=0;while(s<'0'||s>'9') s=Gc();while(s>='0'&&s<='9') x=x*10+s-48,s=Gc();}
int n,m,k,ks,x,y,dfn[N+5<<1],dh,bg[N+5],en[N+5],W[N+5],Ans[N+5],l,r,fa[N+5][20],lg[N+5],d[N+5];
struct yyy{int to,z;};
struct ljb{
	int head,h[N+5];yyy f[N+5<<1];
	I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s;
struct Count_col{
	int F[N+5],Fs[N+5];
	I void insert(int x){Fs[x/ks]-=F[x];Fs[x/ks]+=(F[x]^=1);}
	I int find(int l,int r){
		re int i,j;if(l/ks==r/ks){for(i=l;i<=r;i++) if(F[i]) return i;return -1;}for(i=l;i<l/ks*ks+ks;i++) if(F[i]) return i;for(i=r/ks*ks;i<=r;i++) if(F[i]) return i;
		for(i=l/ks+1;i<r/ks;i++){if(!Fs[i]) continue;for(j=i*ks;j<i*ks+ks;j++) if(F[j]) return j;}return -1;
	}
}S;
I void Make(int x,int last){
	yyy tmp;dfn[bg[x]=++dh]=x;d[x]=d[last]+1;fa[x][0]=last;for(int i=1;i<=lg[d[x]];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^last&&(Make(tmp.to,x),0);dfn[en[x]=++dh]=x; 
}
I void swap(int &x,int &y){x^=y^=x^=y;}
I int lca(int x,int y){
    d[x]<d[y]&&(swap(x,y),0);while(d[x]^d[y]) x=fa[x][lg[d[x]-d[y]]];if(x==y)return x;for(int i=lg[d[x]];~i;i--) fa[x][i]^fa[y][i]&&fa[x][i]&&fa[y][i]&&(x=fa[x][i],y=fa[y][i]);return fa[x][0];
}
struct ques{int l,r,x,y,id,lcas;}Q[N+5];I bool cmp(ques x,ques y){return x.l/k==y.l/k?(((x.l/k)&1)?x.r<y.r:x.r>y.r):x.l<y.l;}
int main(){
//	freopen("1.in","r",stdin);
	re int i;read(n);read(m);k=max(n/sqrt(m),1);ks=sqrt(n);for(i=1;i<=n;i++) read(W[i]);for(i=1;i<n;i++) read(x),read(y),s.add(x,y),s.add(y,x);
	for(i=2;i<=n;i++)lg[i]=lg[i/2]+1;Make(1,1);for(i=1;i<=m;i++){
		read(x),read(y);bg[x]>bg[y]&&(swap(x,y),0);Q[i].lcas=lca(x,y);Q[i].l=((Q[i].lcas==x)?bg[x]+1:en[x]),Q[i].r=bg[y];read(Q[i].x);read(Q[i].y),Q[i].id=i;
	}sort(Q+1,Q+m+1,cmp);l=1;r=0;for(i=1;i<=m;i++){
		while(l<Q[i].l) S.insert(W[dfn[l++]]);while(l>Q[i].l) S.insert(W[dfn[--l]]);while(r<Q[i].r) S.insert(W[dfn[++r]]);while(r>Q[i].r) S.insert(W[dfn[r--]]);S.insert(W[Q[i].lcas]);Ans[Q[i].id]=S.find(Q[i].x,Q[i].y);S.insert(W[Q[i].lcas]);
	}for(i=1;i<=m;i++) printf("%d\n",Ans[i]);
}