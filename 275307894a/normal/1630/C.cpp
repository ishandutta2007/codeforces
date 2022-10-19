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
#define N 200000
#define M 500000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound 
using namespace std;
int T,n,k,A[N+5],W[N+5],st[N+5][20],lg[N+5],Maxn[N+5],R,Ans;
I int calc(int x,int y){int d=lg[y-x+1];return W[st[x][d]]>W[st[y-(1<<d)+1][d]]?st[x][d]:st[y-(1<<d)+1][d];}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d",&n);Ans=n;for(i=1;i<=n;i++) scanf("%d",&A[i]),Maxn[A[i]]=max(Maxn[A[i]],i);
	for(i=1;i<=n;i++) W[i]=Maxn[A[i]];for(i=2;i<=n;i++) lg[i]=lg[i/2]+1;for(i=n;i;i--){
		for(st[i][0]=i,j=1;i+(1<<j)-1<=n;j++) st[i][j]=(W[st[i][j-1]]>W[st[i+(1<<j-1)][j-1]]?st[i][j-1]:st[i+(1<<j-1)][j-1]);
	}
	for(R=1;R<=n;R++){
		Ans--;
		while(1){
			if(R+1>=W[R]) {Ans-=W[R]-R;R=W[R];break;}
			if(W[calc(R+1,W[R]-1)]<=W[R]) {Ans--;R=W[R];break;}R=calc(R+1,W[R]-1); Ans--;
		}
	}printf("%d\n",Ans);
}