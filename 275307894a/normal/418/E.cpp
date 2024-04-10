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
#define N 100000
#define M 100000
#define K 100
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound 
using namespace std;map<int,int> F;
int n,m,k,op,x,y,A[N+5],Ns[N+5<<1],cnt;
namespace FK{
	int Si,F1[K+5][M+5<<1],F2[K+5][N+5<<1],Fr[K+5],En[K+5];
	I void BD(){
		RI i,j;k=sqrt(32*n);for(i=1;i<=n/k+1;i++){
			Fr[i]=max((i-1)*k,1),En[i]=min(i*k-1,n);memcpy(F1[i],F1[i-1],sizeof(F1[i]));memcpy(F2[i],F2[i-1],sizeof(F2[i]));
			for(j=Fr[i];j<=En[i];j++) assert(A[j]<=M),F2[i][++F1[i][A[j]]]++;
		} 
	}
	I void Ins(int x){RI i,Ns=x/k+1;F2[Ns][++F1[Ns][A[x]]]++;for(i=Ns+1;i<=n/k+1;i++)F2[i][++F1[i][A[x]]]++;}
	I void Del(int x){RI i,Ns=x/k+1;F2[Ns][F1[Ns][A[x]]--]--;for(i=Ns+1;i<=n/k+1;i++)F2[i][F1[i][A[x]]--]--;}
	I int Q1(int x){RI i,Ns=x/k+1,Len=F1[Ns-1][A[x]];for(i=Fr[Ns];i<=x;i++) Len+=(A[i]==A[x]);return Len;}
	I int Q2(int x){RI i,Ns=x/k+1,Len=F2[Ns-1][Si=Q1(x)];for(i=Fr[Ns];i<=x;i++) F1[Ns-1][A[i]]++,Len+=(F1[Ns-1][A[i]]==Si);for(i=Fr[Ns];i<=x;i++) F1[Ns-1][A[i]]--;return Len;}
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&n);for(RI i=1;i<=n;i++) scanf("%d",&A[i]),!F[A[i]]&&(Ns[F[A[i]]=++cnt]=A[i]),A[i]=F[A[i]];FK::BD();scanf("%d",&m);while(m--) scanf("%d%d%d",&op,&x,&y),op^2?(FK::Del(y),!F[x]&&(Ns[F[x]=++cnt]=x),x=F[x],A[y]=x,FK::Ins(y),0):(printf("%d\n",x^1?(x&1?FK::Q2(y):FK::Q1(y)):Ns[A[y]]));
}