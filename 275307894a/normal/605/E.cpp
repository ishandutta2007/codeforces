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
#define N 3000
#define M N*N+5
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-12)
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
int n,m,k,B[N+5],Id,Fl[N+5];db A[N+5][N+5],D[N+5],S[N+5];
I bool cmp(int x,int y){return D[x]<D[y];}
int main(){
//	freopen("trip.in","r",stdin);freopen("trip.out","w",stdout);
	RI i,j;scanf("%d",&n);for(i=1;i<=n;i++) for(S[i]=j=1;j<=n;j++) scanf("%lf",&A[i][j]),A[i][j]/=100;
	S[0]=1;D[0]=1e9;for(i=1;i<=n;i++)D[i]=1,S[i]=1-A[i][n];Fl[n]=1;D[n]=0;for(i=1;i<=n;i++){
		Id=0;for(j=1;j<=n;j++) D[Id]/(1-S[Id])>D[j]/(1-S[j])&&!Fl[j]&&(Id=j);Fl[Id]=1;
		for(j=1;j<=n;j++) !Fl[j]&&(D[j]+=S[j]*A[j][Id]*(D[Id]/(1-S[Id])),S[j]*=1-A[j][Id]);
	}printf("%.6lf\n",D[1]/(1-S[1]));
}