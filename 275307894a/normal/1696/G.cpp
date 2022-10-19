#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (300000+5)
#define M (6000000+5)
#define K (1500+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,X,Y,x,y,z,op,A[N];
struct MaT{db A[3][3];MaT(){for(int i=0;i<3;i++) for(int j=0;j<3;j++) A[i][j]=-1e9;}MaT operator *(const MaT B)const{int i,j,h;MaT C;for(h=0;h<3;h++) for(i=0;i<3;i++) for(j=0;j<3;j++) C.A[i][j]=max(C.A[i][j],A[i][h]+B.A[h][j]);return C;}}Ps;
I void Make(int x,MaT &B){B.A[0][0]=0;B.A[0][1]=x*1.0/(X+Y);B.A[0][2]=x*1.0/Y;B.A[1][0]=0;B.A[1][1]=x*1.0/(X+Y);B.A[2][0]=0;}
namespace Tree{
	#define ls v<<1
	#define rs v<<1|1
	MaT F[N<<2];I void Up(int v){F[v]=F[ls]*F[rs];}I void BD(int l=1,int r=n,int v=1){if(l==r)return Make(A[l],F[v]);int m=l+r>>1;BD(l,m,ls);BD(m+1,r,rs);Up(v);}
	I void Ins(int x,int l=1,int r=n,int v=1){if(l==r) return Make(A[l],F[v]);int m=l+r>>1;x<=m?Ins(x,l,m,ls):Ins(x,m+1,r,rs);Up(v);}
	I MaT Qry(int x,int y,int l=1,int r=n,int v=1){if(x<=l&&r<=y) return F[v];int m=l+r>>1;if(y<=m) return Qry(x,y,l,m,ls);if(x>m) return Qry(x,y,m+1,r,rs);return Qry(x,y,l,m,ls)*Qry(x,y,m+1,r,rs);}
	#undef ls
	#undef rs
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d%d%d",&n,&m,&X,&Y);X>Y&&(swap(X,Y),0);for(i=1;i<=n;i++) scanf("%d",&A[i]);Tree::BD();
	while(m--) scanf("%d%d%d",&op,&x,&y),op^2?(A[x]=y,Tree::Ins(x),0):(Ps=Tree::Qry(x,y),printf("%.9lf\n",max(Ps.A[0][0],max(Ps.A[0][1],Ps.A[0][2]))));
}