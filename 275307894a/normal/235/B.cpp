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
#define K 20
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n;db x,F1[N+5],F2[N+5],ToT; 
int main(){
//////	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++)scanf("%lf",&x),F1[i]=(F1[i-1]+1)*x,F2[i]=F2[i-1]+(2*F1[i-1]+1)*x;printf("%.9lf\n",F2[n]);
}