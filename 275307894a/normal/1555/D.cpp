#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 250000
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int T,n,m,Ans,A[N+5],Q[10][N+5],x,y; char S[N+5],S1[N+5],S2[N+5],S3[N+5];
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d%d",&n,&m);scanf("%s",S+1);
	for(i=1;i<=n/3+2;i++) S2[i*3-2]='a',S2[i*3-1]='b',S2[i*3]='c';
	for(i=1;i<=n;i++) Q[4][i]=Q[4][i-1]+(S2[i]==S[i]),Q[5][i]=Q[5][i-1]+(S2[i+1]==S[i]),Q[6][i]=Q[6][i-1]+(S2[i+2]==S[i]);
	for(i=1;i<=n/3+2;i++) S3[i*3-2]='c',S3[i*3-1]='b',S3[i*3]='a';
	for(i=1;i<=n;i++) Q[7][i]=Q[7][i-1]+(S3[i]==S[i]),Q[8][i]=Q[8][i-1]+(S3[i+1]==S[i]),Q[9][i]=Q[9][i-1]+(S3[i+2]==S[i]);
	while(m--){
		scanf("%d%d",&x,&y);Ans=0;for(i=4;i<10;i++) Ans=max(Ans,Q[i][y]-Q[i][x-1]);printf("%d\n",y-x+1-Ans);
	}
}