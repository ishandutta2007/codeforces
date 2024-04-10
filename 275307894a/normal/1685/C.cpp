#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M (400+5)
#define K (3000000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int T,n,Mx,Q[N],W[N],m,L,R;char s[N],p[N];
I void Solve(){
	int i,j;scanf("%d",&n);m=2*n;scanf("%s",s+1);for(i=1;i<=m;i++) Q[i]=Q[i-1]+(s[i]^'('?-1:1);
	L=1;R=m;while(L<=m&&Q[L]>=0) L++;while(R&&Q[R]>=0) R--;if(L>R){puts("0");return;}for(i=L;i;i--) Q[i]>Q[L-1]&&(L=i+1);for(i=R;i<=m;i++) Q[i]>Q[R]&&(R=i);Mc(p,s);reverse(p+L,p+R+1);
	Mx=1;for(i=2;i<=m;i++) Q[i]>Q[Mx]&&(Mx=i);for(i=1;i<=m;i++) W[i]=W[i-1]+(p[i]^'('?-1:1);for(i=1;i<=m;i++) if(W[i]<0) {printf("2\n%d %d\n%d %d\n",1,Mx,Mx+1,m);return;}
	printf("1\n%d %d\n",L,R);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}