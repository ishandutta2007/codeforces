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
#define K 50
#define mod 998244353
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int n,m,k,W[N+5],Ans=1e9;ll A[N+5],B[N+5];char c[N+5];
I void XOR(ll *A,int n,int Fl){
	RI i,j,h;for(i=2;i<=n;i<<=1){
		for(j=0;j<n;j+=i)for(h=j;h<j+i/2;h++) ~Fl?(A[h]+=A[h+i/2],A[h+i/2]=A[h]-A[h+i/2]*2):(A[h]=(A[h]+A[h+i/2])/2,A[h+i/2]=A[h]-A[h+i/2]);
	}
}
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d%d",&n,&m);k=1<<n;for(i=1;i<=n;i++) for(scanf("%s",c),j=0;j<m;j++)W[j]=(W[j]<<1)+c[j]-'0';for(i=0;i<m;i++) B[W[i]]++;for(i=0;i<k;i++) A[i]=A[i>>1]+(i&1);for(i=0;i<k;i++)A[i]=min(A[i],n-A[i]);
	XOR(A,k,1);XOR(B,k,1);for(i=0;i<k;i++) A[i]=A[i]*B[i];XOR(A,k,-1);for(i=0;i<k;i++)Ans=min(Ans,A[i]);printf("%d\n",Ans);
}