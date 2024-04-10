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
#define N 4000000
#define M 500000
#define mod 51123987
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound 
using namespace std;
int F[N+5],R,n,H,Mi,Len;ll Ans,ToT,Pus,x,y,Q1[N+5],Q2[N+5],Q3[N+5];char S[N+5],c;
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);S[H=1]='$';for(i=1;i<=n;i++){c=Gc();while(c<'a'||c>'z') c=Gc();S[++H]='#';S[++H]=c;}S[++H]='#';S[++H]='&';
	for(Mi=1,Len=F[1]=1,i=2;i<H;i++){F[i]=max(min(F[2*Mi-i],Mi+Len-i),1);while(S[i+F[i]]==S[i-F[i]]) F[i]++;i+F[i]>Mi+Len&&(Mi=i,Len=F[i]);}
	for(i=1;i<=H;i++) Ans+=F[i]/2;for(i=2;i<H;i++){
		x=F[i];i>3&&!(i&1)&&(Q1[i/2-1]+=Q1[i/2-2],Q2[i/2-1]=(Q2[i/2-2]+Q1[i/2-1])%mod,Q3[i/2-1]=(Q3[i/2-2]+Q2[i/2-1])%mod);
		ToT+=Q3[(i-1)/2-1]-((i-x+1)/2>=2?Q3[(i-x+1)/2-2]:0);Q1[i/2]++;Q1[(i+x)/2]--; //printf("%lld\n",ToT);
	}Ans%=mod;printf("%lld\n",((Ans*(Ans-1)/2-ToT)%mod+mod)%mod);
}