#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 1000
#define K 400
#define mod 20170408
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Pc(x) putchar(x) 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
using namespace std;
int T,n;ll A[N+5],Ans,B[N+5],now,ToT,Minn;
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%lld",&A[i]),B[i]=B[i-1]+(i&1?A[i]:-A[i]);
	for(i=1;i<=n;i+=2){
		for(Minn=1e9,j=i+1;j<=n;j+=2){
			now=B[j]-B[i-1];if(now<0) Ans+=max(0,min(A[j]+now,A[i]+min(Minn+1,0)));else Ans+=max(0,min(A[i]-now+min(Minn+1,0),A[j]));Minn=min(Minn,B[j]-B[i]);
		}
	}printf("%lld\n",Ans);
}