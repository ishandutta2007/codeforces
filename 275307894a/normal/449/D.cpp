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
#define K 90000
#define mod 1000000007
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Pc(x) putchar(x) 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) ((n-1)*(x)+(y))
using namespace std;
int Fl=1,n,m,k=1,A[N+5],x,Maxn,G[N+5];ll Ans,po[N+5];
I void AND(int *A,int n){
	RI i,j,h;for(i=2;i<=n;i<<=1){
		for(j=0;j<n;j+=i) for(h=j;h<j+i/2;h++) A[h]+=A[h+i/2];
	}
}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&n);for(po[0]=i=1;i<=n;i++) scanf("%d",&x),Fl&=!x,Maxn=max(Maxn,x),A[x]++,po[i]=po[i-1]*2%mod;while(k<=Maxn) k<<=1;AND(A,k);
	for(i=0;i<k;i++)G[i]=G[i>>1]^(i&1),Ans+=(G[i]?mod-po[A[i]]:po[A[i]]);printf("%lld\n",(Ans-Fl+mod)%mod);
}