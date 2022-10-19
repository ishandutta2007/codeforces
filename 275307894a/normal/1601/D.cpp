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
#define N (1000000+5)
#define M (N*50+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
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
int n,m,k,cnt,d;
struct Ques{int x,y;}S[N+5];I bool cmp(Ques x,Ques y){return max(x.x,x.y)^max(y.x,y.y)?(max(x.x,x.y)<max(y.x,y.y)):(min(x.x,x.y)<min(y.x,y.y));}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%d",&n,&d);for(i=1;i<=n;i++) scanf("%d%d",&S[i].x,&S[i].y);sort(S+1,S+n+1,cmp);
	for(i=1;i<=n;i++) S[i].x>=d&&(cnt++,d=max(d,S[i].y));printf("%d\n",cnt);
}