#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define K 150
#define mod 1000000000
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int T,n,x;ll Maxn,ToT;
int main(){
	scanf("%d",&T);while(T--){
		scanf("%d",&n);Maxn=-1e18;ToT=0;for(int i=1;i<=n;i++)scanf("%d",&x),Maxn=max(Maxn,x),ToT+=x;printf("%.8lf\n",Maxn+(ToT-Maxn)*1.0/(n-1));
	}
}