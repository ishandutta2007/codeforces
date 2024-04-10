#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define U unsigned int
#define db double
#define lb long db
#define N (300000+5)
#define M (220+5)
#define K (650+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,k,x,y,z,p,cnt,A[N],f[N];char c;
I void Ins(int x,int y){if(x>n) return;cnt-=(A[x]!=0);A[x]=(A[x]+y)%p;cnt+=(A[x]!=0);}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d%d",&n,&m,&p);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&x),A[i]=(A[i]-x+p)%p;
	for(i=n;i;i--) A[i]=(A[i]-A[i-1]-(i^1?A[i-2]:0)+p*3ll)%p,cnt+=(A[i]!=0);for(f[1]=f[2]=1,i=3;i<=n;i++) f[i]=(f[i-1]+f[i-2])%p;
	while(m--){
		c=Gc();while(c<'A'||c>'B') c=Gc();scanf("%d%d",&x,&y);c^'B'?(Ins(x,1),Ins(y+1,(2*p-f[y-x+1]-f[y-x])%p),Ins(y+2,p-f[y-x+1]),0):(Ins(x,p-1),Ins(y+1,(f[y-x+1]+f[y-x])%p),Ins(y+2,f[y-x+1]),0);puts(!cnt?"YES":"NO");
	}
}