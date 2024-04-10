#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 200000
#define M 500
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int T,n,m,un,wn,z,fa[N*2+5],X[N+5],Y[N+5],Z[N+5],Fl[N*2+5],L,R,W,Q[N+5];
I int GF(int x){return x^fa[x]?fa[x]=GF(fa[x]):x;}
I void Merge(int x,int y){fa[GF(x)]=GF(y);}
I int Size(int x){int cnt=0;while(x) cnt++,x-=x&-x;return cnt&1;}
struct yyy{int to,w,z;};struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}}s;
I void dfs(int x,int La,int W){
	if(~W){printf("%d %d %d\n",x,La,W);Q[x]=Q[La]^Size(W);}
	else {
		if(Fl[GF(x)]!=-1){
	    	Q[x]=Fl[GF(x)];if(x^1) printf("%d %d %d\n",x,La,Fl[GF(x)]^Q[La]);
	    } else Q[x]=Q[La],Fl[GF(x)]=Q[La],Fl[GF(x+n)]=Q[La]^1,x^1&&(printf("%d %d %d\n",x,La,0));
	}yyy tmp;for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^La&&(dfs(tmp.to,x,tmp.w),0);
}
I void Solve(){
	RI i;scanf("%d%d",&n,&m);for(i=1;i<=2*n;i++) fa[i]=i;
	for(i=1;i<n;i++)scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
	for(i=1;i<n;i++){
		if(Z[i]==-1) continue;z=Size(Z[i]);
		if(z)Merge(X[i],Y[i]+n),Merge(Y[i],X[i]+n);
		else Merge(X[i],Y[i]),Merge(X[i]+n,Y[i]+n);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&L,&R,&W);
		if(W)Merge(L,R+n),Merge(R,L+n);
		else Merge(L,R),Merge(L+n,R+n);
	}
	for(i=1;i<=n;i++) if(GF(i)==GF(i+n)){puts("NO");return;}
	puts("YES");for(i=1;i<=n;i++)s.h[i]=Q[i]=0;for(i=1;i<=2*n;i++)Fl[i]=-1;s.head=0;for(i=1;i<n;i++) s.add(X[i],Y[i],Z[i]),s.add(Y[i],X[i],Z[i]);dfs(1,0,-1);
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&T);while(T--) Solve();
}