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
#define N 500
#define M 5
#define mod 1000000007
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,Ans,A[N+5][N+5],Q[N+5][N+5],ToT,Fl[N+5][N+5],fl;char C[N+5];
I void clear(int x,int y){for(int i=x;i<=n;i++) for(int j=y;j<=m;j++) A[i][j]=0;}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) for(scanf("%s",C+1),j=1;j<=m;j++) A[i][j]=(C[j]=='W'?0:1),ToT+=A[i][j];
	for(i=n;i;i--){
		for(j=m;j;j--){
			if(A[i][j]^Q[i][j])Q[i][j]^=1,Ans++,Fl[i][j]=1;//printf("%d %d %d\n",i,j,Ans);
			Q[i][j]&&(Q[i-1][j]^=1,Q[i][j-1]^=1,Q[i-1][j-1]^=1);
		}
	}
	if(Fl[n][m]){
		for(i=1;i<n&&!fl;i++) for(j=1;j<m;j++) if(Fl[i][m]&&Fl[n][j]&&Fl[i][j]){fl=1;Ans--;break;}
	}
	printf("%d\n",Ans);
}