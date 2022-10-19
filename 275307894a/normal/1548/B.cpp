#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define M 1000000
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using  namespace std;
int T,n,lg[N+5],Ans,pus,now;ll A[N+5],st[N+5][20],ToT;
I ll find(int x,int y){int k=lg[y-x+1];return __gcd(st[x][k],st[y-(1<<k)+1][k]);}
int main(){
	//freopen("1.in","r",stdin);
	re int i,j;scanf("%d",&T);for(i=2;i<=N;i++) lg[i]=lg[i/2]+1;while(T--){
		scanf("%d",&n);Ans=0;for(i=1;i<=n;i++) scanf("%lld",&A[i]);n--;for(i=1;i<=n;i++) A[i]=abs(A[i]-A[i+1]),Me(st[i],0);
		for(i=n;i;i--){
			for(st[i][0]=A[i],j=1;i+(1<<j)-1<=n;j++) st[i][j]=__gcd(st[i][j-1],st[i+(1<<j-1)][j-1]);
		}
		for(i=j=1;i<=n;i++){
			j=max(i,j);while(j<=n&&find(i,j)>1) j++;Ans=max(Ans,j-i);
		}
		printf("%d\n",Ans+1);
	}
}