#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200+5)
#define M (100+5)
#define K (1000+5)
#define mod 998244353
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
int T,n,m,H1,H2;char S1[N],S2[N],S3[N],S4[N];
I void Solve(){
	int i,j;scanf("%s%s",S1+1,S2+1);H1=H2=0;n=strlen(S1+1);m=strlen(S2+1);
	for(i=1;i<=n;i++) {if(S1[i]^'B') continue;for(j=i;S1[j-1]^'B'&&j>1;j--)swap(S1[j],S1[j-1]);}
	for(i=1;i<=n;i++) {S3[++H1]=S1[i];while(H1>1&&S3[H1]==S3[H1-1]) H1-=2;}
	for(i=1;i<=m;i++) {if(S2[i]^'B') continue;for(j=i;S2[j-1]^'B'&&j>1;j--)swap(S2[j],S2[j-1]);}
	for(i=1;i<=m;i++) {S4[++H2]=S2[i];while(H2>1&&S4[H2]==S4[H2-1]) H2-=2;}
	if(H1^H2){puts("NO");return;}for(i=1;i<=H1;i++) if(S3[i]^S4[i]) {puts("NO");return;}puts("YES");
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}