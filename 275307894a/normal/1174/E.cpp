#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (500000+5)
#define M ((1<<14)+5)
#define K (700+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define ui unsigned int
#define ull unsigned ll
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,x,y,z,Po[50];ll g[25][2],f[25][2],ToT;
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h;scanf("%d",&n);x=n;while(x^1) y++,x/=2;for(Po[0]=i=1;i<=y;i++) Po[i]=Po[i-1]*2;
	f[y][0]=1;f[y-1][1]=(Po[y]/2*3<=n);for(i=2;i<=n;i++){
		Mc(g,f);Me(f,0);for(j=0;j<=y;j++){
			f[j][1]=(f[j][1]+g[j][1]*(n/Po[j]/3-i+1))%mod;j&&(f[j-1][1]=(f[j-1][1]+g[j][1]*(n/Po[j-1]/3-n/Po[j]/3))%mod);f[j][0]=(f[j][0]+g[j][1]*(n/Po[j]-n/Po[j]/3))%mod;
			f[j][0]=(f[j][0]+g[j][0]*(n/Po[j]-i+1))%mod;j&&(f[j-1][0]=(f[j-1][0]+g[j][0]*(n/Po[j-1]-n/Po[j]))%mod);
		}
	}printf("%lld\n",f[0][0]%mod);
}