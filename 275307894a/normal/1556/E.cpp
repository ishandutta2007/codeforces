#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 300000
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
int n,m,k,x,y,xs,ys,lg[N+5],L[N+5],R[N+5],r;ll W[N+5],Q[N+5],A[N+5],B[N+5],S1[N+5][20],S2[N+5][20],Ans,S3[N+5][20],S4[N+5][20];
I ll F1(int x,int y){int p=lg[y-x+1];return min(S1[x][p],S1[y-(1<<p)+1][p]);}
I ll F2(int x,int y){int p=lg[y-x+1];return max(S2[x][p],S2[y-(1<<p)+1][p]);}
I ll F3(int x,int y){int p=lg[y-x+1];return max(S3[x][p],S3[y-(1<<p)+1][p]);}
I ll F4(int x,int y){int p=lg[y-x+1];return min(S4[x][p],S4[y-(1<<p)+1][p]);}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%lld",&A[i]);for(i=1;i<=n;i++) scanf("%lld",&B[i]),A[i]=B[i]-A[i];
	for(i=1;i<=n;i++) Q[i]=Q[i-1]+A[i];for(i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	for(i=n;i;i--){
		for(S1[i][0]=Q[i],j=1;i+(1<<j)-1<=n;j++) S1[i][j]=min(S1[i][j-1],S1[i+(1<<j-1)][j-1]);
	}for(i=n;i;i--){
		for(S2[i][0]=Q[i],j=1;i+(1<<j)-1<=n;j++) S2[i][j]=max(S2[i][j-1],S2[i+(1<<j-1)][j-1]);
	}//for(i=1;i<=n;i++) printf("%d ",A[i]);
	while(m--){
		scanf("%d%d",&x,&y);if(Q[y]-Q[x-1]||F1(x,y)<Q[x-1]){puts("-1");continue;}
		printf("%lld\n",F2(x,y)-Q[x-1]);
	}
}