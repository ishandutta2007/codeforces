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
#define N 1100000
#define M 300000
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,l,r,mid,S1h,S2h;ll A[N+5],B[N+5],x,F[N+5],Q1[N+5],Q2[N+5],Q3[N+5],Q4[N+5],Ans,ToT;
struct Ques{ll A,F,w;}S1[N+5],S2[N+5];I bool cmp(Ques x,Ques y){return x.w<y.w;}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%lld",&A[i]);for(i=1;i<=n;i++) scanf("%lld",&B[i]);
	for(i=2;i<=n;i++) F[i]=1;for(i=2;i<=n;i++) for(j=i*2;j<=n;j+=i) F[j]-=F[i];
	for(i=2;i<=n;i++) A[i]-=B[i];for(i=2;i<=n;i++) for(j=2*i;j<=n;j+=i) A[j]-=A[i];
	for(i=2;i<=n;i++) !F[i]?(Ans+=abs(A[i])):(F[i]>0?S1[++S1h]=(Ques){A[i],F[i],floor(A[i]*1.0/F[i])}:S2[++S2h]=(Ques){A[i],F[i],floor(A[i]*1.0/F[i])},0);sort(S1+1,S1+S1h+1,cmp);sort(S2+1,S2+S2h+1,cmp);
	for(i=1;i<=S1h;i++) Q1[i]=Q1[i-1]+S1[i].A,Q2[i]=Q2[i-1]+S1[i].F;for(i=1;i<=S2h;i++) Q3[i]=Q3[i-1]+S2[i].A,Q4[i]=Q4[i-1]+S2[i].F;
	scanf("%d",&m);while(m--){
		scanf("%lld",&x);x=x-A[1];l=0;r=S1h+1;while(l+1<r) mid=l+r>>1,(S1[mid].w<=-x?l:r)=mid;ToT=Ans-Q2[l]*x-Q1[l]+(Q1[S1h]-Q1[l])+x*(Q2[S1h]-Q2[l])+abs(x);
		l=0;r=S2h+1;while(l+1<r) mid=l+r>>1,(S2[mid].w<=-x?l:r)=mid;printf("%lld\n",ToT+Q4[l]*x+Q3[l]-(Q3[S2h]-Q3[l])-x*(Q4[S2h]-Q4[l]));
	}
}