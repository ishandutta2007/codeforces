#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (600000+5)
#define M (5000000-5)
#define K (1500+5)
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
int n,m,k,L,R,x,y,z,T,a,b,c,d,Nx,Ny,P1,B[N],C[N],Bh,Ch;char s[N];
I void Solve(){
	int i,j;scanf("%d%d%d%d",&a,&b,&c,&d);scanf("%s",s+1);n=strlen(s+1);
	Nx=Ny=0;for(i=1;i<=n;i++) Nx+=(s[i]=='A'),Ny+=(s[i]=='B');if(Nx!=a+c+d||Ny!=b+c+d) {puts("NO");return;}
	Bh=Ch=0;P1=0;for(i=1;i<=n;i=j){
		for(j=i+1;j<=n;j++) if(s[j]==s[j-1]) break;x=j-i;if(x&1) P1+=x/2;else if(s[i]=='A') B[++Bh]=x/2;else C[++Ch]=x/2;
	}
	sort(B+1,B+Bh+1);sort(C+1,C+Ch+1);
	L=1;R=1;while(c&&L<=Bh) {if(c<B[L]) B[L]-=c,c=0;else c-=B[L++];}
	while(d&&R<=Ch) {if(d<C[R]) C[R]-=d,d=0;else d-=C[R++];}
	if(c+d<=P1){puts("YES");return;}
	if(L==Bh+1&&R==Ch+1) {puts("NO");return;}
	if(L==Bh+1) {c-=P1;for(i=R;i<=Ch;i++) c-=(C[i]-1);if(c<=0) puts("YES");else puts("NO");return;}
	if(R==Ch+1) {d-=P1;for(i=L;i<=Bh;i++) d-=B[i]-1;if(d<=0) puts("YES");else puts("NO");return;}
}
int main(){
//	//freopen("1.in","r",stdin);
	int i,j;scanf("%d",&T);while(T--) Solve();
}