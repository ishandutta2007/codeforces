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
#define N 1000000
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
string A[N+5],x;int n,m,Q,a1,a2,Fl[N+5];
int main(){
	//freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) A[i]+='.',cin>>x,A[i]+=x;
	for(i=2;i<=m;i++)for(j=2;j<=n;j++) Fl[i]|=(A[j][i-1]=='X'&&A[j-1][i]=='X');
	for(i=1;i<=m;i++) Fl[i]+=Fl[i-1];scanf("%d",&Q);while(Q--){
		scanf("%d%d",&a1,&a2);if(Fl[a2]-Fl[a1])printf("No\n");else puts("Yes");
	}
}