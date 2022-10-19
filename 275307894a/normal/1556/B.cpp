#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 100000
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
int T,n,A[N+5],B[N+5],Bh;ll ToT,Ans;
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--){
		Bh=0;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]),A[i]&1&&(B[++Bh]=i);
		if(Bh<(n/2)||Bh>(n+1>>1)){puts("-1");continue;}sort(B+1,B+Bh+1);
		if(n&1){
			if(Bh==(n-1)/2){
				Ans=0;for(i=1;i<=Bh;i++)Ans+=abs(B[i]-(2*i));
			}else{
				Ans=0;for(i=1;i<=Bh;i++) Ans+=abs(B[i]-(2*i-1));
			}
		}else{
			Ans=0;ToT=0;for(i=1;i<=Bh;i++)Ans+=abs(B[i]-(2*i));for(i=1;i<=Bh;i++) ToT+=abs(B[i]-(2*i-1));Ans=min(Ans,ToT);
		}printf("%lld\n",Ans);
	}
}