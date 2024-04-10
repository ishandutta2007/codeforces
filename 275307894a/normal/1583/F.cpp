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
#define N 1000
#define M 30
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,k,m,cnt,now,A[N+5][N+5],La;
int main(){
///////	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&k);
	now=1;while(now<n){
		La=now;now*=k;cnt++;for(i=1;i<=n;i++){
			for(j=(i-1)/La*La+La+1;j<=min((i-1)/now*now+now,n);j++) A[i][j]=cnt;
		}
	}printf("%d\n",cnt);for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) printf("%d ",A[i][j]);
}