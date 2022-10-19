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
int C1,C2,Ans,n,T,A[N+5],B[N+5];char S[N+5];
I void Solve(){
	RI i;scanf("%d",&n);scanf("%s",S+1);for(i=1;i<=n;i++) A[i]=S[i]-'0';
	scanf("%s",S+1);for(i=1;i<=n;i++) B[i]=S[i]-'0';
	Ans=1e9;C1=C2=0;for(i=1;i<=n;i++) A[i]==B[i]&&(C1+=A[i],C2+=!A[i]);
	if(C1==C2+1) Ans=min(Ans,C1+C2);
	C1=C2=0;for(i=1;i<=n;i++) A[i]^B[i]&&(C1+=A[i],C2+=!A[i]);
	if(C1==C2) Ans=min(Ans,C1+C2);printf("%d\n",Ans<1e9?Ans:-1);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}