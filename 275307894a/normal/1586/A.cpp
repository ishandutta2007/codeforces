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
#define N 100000
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
int n,m,k,T,A[N+5],Fl,ToT;
I int check(int x){
	RI i;for(i=2;i*i<=x;i++)if(x%i==0) return 1;return 0;
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&T);while(T--){
		scanf("%d",&n);ToT=0;Fl=0;for(i=1;i<=n;i++) scanf("%d",&A[i]),ToT+=A[i];
		if(!check(ToT)){printf("%d\n",n-1),Fl=1;for(i=1;i<=n;i++)(!Fl||A[i]%2==0)&&(printf("%d ",i),A[i]&1),A[i]&1&&(Fl=0);}
		else for(printf("%d\n",n),i=1;i<=n;i++) printf("%d ",i);puts("");
	}
}