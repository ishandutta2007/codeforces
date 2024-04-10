#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define U unsigned int
#define db double
#define lb long db
#define N (100000+5)
#define M ((N<<2)+5)
#define mod 1000000001
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,x;char S[N],c;const int INF=1000000000;
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	int A[M],B[M],C[M],AB[M],BC[M],ABC[M];I void Up(int now){
		A[now]=min(A[ls]+A[rs],INF);B[now]=min(B[ls]+B[rs],INF);C[now]=min(C[ls]+C[rs],INF);AB[now]=min(min(min(AB[ls]+B[rs],A[ls]+AB[rs]),A[ls]+B[rs]),INF);BC[now]=min(min(B[ls]+C[rs],min(BC[ls]+C[rs],B[ls]+BC[rs])),INF);
		ABC[now]=min(min(min(ABC[ls]+C[rs],A[ls]+ABC[rs]),min(AB[ls]+BC[rs],min(AB[ls]+C[rs],A[ls]+BC[rs]))),INF);
	}
	I void BD(int l=1,int r=n,int now=1){if(l==r){S[l]=='a'?(A[now]=1):(S[l]=='b'?(B[now]=1):(C[now]=1));return;}int m=l+r>>1;BD(l,m,ls);BD(m+1,r,rs);Up(now);}
	I void Ins(int x,int l=1,int r=n,int now=1){if(l==r){A[now]=B[now]=C[now]=0;S[l]=='a'?(A[now]=1):(S[l]=='b'?(B[now]=1):(C[now]=1));return;}int m=l+r>>1;x<=m?Ins(x,l,m,ls):Ins(x,m+1,r,rs);Up(now);}
	#undef ls
	#undef rs
}
int main(){
////	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&m);scanf("%s",S+1);Tree::BD();
	while(m--){
		scanf("%d",&x);c=Gc();while(c<'a'||c>'z') c=Gc();S[x]=c;Tree::Ins(x);printf("%d\n",min(Tree::ABC[1],min(Tree::AB[1],min(Tree::BC[1],min(Tree::A[1],min(Tree::B[1],Tree::C[1]))))));
	}
}