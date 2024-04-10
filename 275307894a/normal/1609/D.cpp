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
#define M ((1<<11)+5)
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
int n,m,B[N],Bh,x,y,X[N],Y[N],fa[N],Si[N],Ans,Mx,cnt;
I int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}
int main(){
////	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&X[i],&Y[i]);for(j=1;j<=n;j++) fa[j]=j,Si[j]=1;cnt=0;for(j=1;j<=i;j++) GF(X[j])^GF(Y[j])?(Si[GF(Y[j])]+=Si[GF(X[j])],fa[GF(X[j])]=GF(Y[j])):(cnt++);
		Bh=0;for(j=1;j<=n;j++) fa[j]==j&&(B[++Bh]=Si[j]);sort(B+1,B+Bh+1);Ans=0;for(j=Bh;j&&cnt>=0;j--) Ans+=B[j],cnt--;printf("%d\n",Ans-1);
	}
}