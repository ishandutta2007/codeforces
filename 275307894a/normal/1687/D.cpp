#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (2000000+5)
#define M (N-5)
#define K (1500+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#include <vector>
using namespace std;
int n,A[N],Fl[N],Pa[N],x,y,z,La;ll L,R; 
int main(){
////	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]),Fl[A[i]]++;for(i=1;i<=A[n];i++) Fl[i]+=Fl[i-1];
	for(i=1;i<=A[n];i++){
		x=1;y=A[1];L=max(1ll*i*i-A[1],0);R=1ll*i*i+i-A[1];if(L>R) continue;
		for(j=i;j<=A[n];j++){
			y+=j;La=x+1;x=Fl[min(y,A[n])];if(La<=x) L=max(1ll*j*j-A[La],L);R=min(R,1ll*j*j+j-A[x]);if(L>R) break;
			if(x==n) break;y+=j+1;
		}if(L<=R&&x==n) {printf("%lld\n",L);return 0;}
	} 
}