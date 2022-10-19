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
#define N (300000+5)
#define M (500000+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
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
int n,x,A[N+5],Rt,cnt;ll Ans,T1[50],T2[50];
struct Ques{int w,Id,A;}B[N+5];I bool cmp(Ques x,Ques y){return x.w^y.w?x.w<y.w:x.Id<y.Id;}
I void Solve(int d){
	RI i,j,h;for(i=1;i<=n;i=j+1){
		for(j=i;j<=n;j++) if(B[j].w^B[i].w) break;j--;
		cnt=0;for(h=i;h<=j;h++) !B[h].A?(T1[d]+=cnt):(cnt++);
		cnt=0;for(h=i;h<=j;h++) B[h].A?(T2[d]+=cnt):(cnt++);
	}
}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);
	for(i=0;i<=30;i++){
		for(j=1;j<=n;j++) B[j]=(Ques){A[j]>>i+1,j,A[j]>>i&1};sort(B+1,B+n+1,cmp);
		Solve(i);
	}
	for(i=0;i<=30;i++) T1[i]<=T2[i]?(Ans+=T1[i]):(Ans+=T2[i],x|=(1<<i));printf("%lld %d\n",Ans,x);
}