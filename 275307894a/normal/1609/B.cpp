#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define U unsigned int
#define db double
#define lb long db
#define N (100000+5)
#define M ((1<<11)+5)
#define mod 1000000001
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
int T,n,Mx,m,x,Cnt;char s,C[N];
int main(){
////	freopen("1.in","r",stdin);
	int i;scanf("%d%d",&n,&m);scanf("%s",C+1);for(i=1;i<=n-2;i++)Cnt+=(C[i]=='a'&&C[i+1]=='b'&&C[i+2]=='c');
	while(m--){
		scanf("%d",&x);s=Gc();while(s<'a'||s>'z') s=Gc();for(i=max(x-2,1);i<=min(x,n-2);i++) Cnt-=(C[i]=='a'&&C[i+1]=='b'&&C[i+2]=='c');
		C[x]=s;for(i=max(x-2,1);i<=min(x,n-2);i++) Cnt+=(C[i]=='a'&&C[i+1]=='b'&&C[i+2]=='c');printf("%d\n",Cnt);
	}
}