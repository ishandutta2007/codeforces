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
#define N (100000+5)
#define M (2500000+5)
#define K (200000+5)
#define mod 998244353
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
int n,m,k,x,y,z,Ans=2e9+7,cnt,Ns[N*5],R;map<int,int> F;
struct Ques{int w,A[6];}S[N];I bool cmp(Ques x,Ques y){return x.w<y.w;}
I void Ins(int x,int z,int w,int *A){if(x==m+1){F[z]+=w;return;}Ins(x+1,z^Ns[A[x]],w,A);Ins(x+1,z,w,A);}
I int calc(int x,int z,int *A){if(x==m+1) return F[z];return calc(x+1,z,A)-calc(x+1,z^Ns[A[x]],A);}
int main(){
//	freopen("1.in","r",stdin);
	srand((unsigned int)time(0));RI i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++){for(j=1;j<=m;j++) scanf("%d",&S[i].A[j]),!F[S[i].A[j]]&&(F[S[i].A[j]]=++cnt),S[i].A[j]=F[S[i].A[j]];scanf("%d",&S[i].w);}sort(S+1,S+n+1,cmp);
	F.clear();for(i=1;i<=cnt;i++) Ns[i]=rand();for(i=1;i<=n;i++) Ins(1,0,1,S[i].A);R=n;for(i=1;i<=n;i++){while(R&&calc(1,0,S[i].A)) Ans=min(Ans,S[R].w+S[i].w),Ins(1,0,-1,S[R--].A);}printf("%d\n",Ans>2e9?-1:Ans); 
}