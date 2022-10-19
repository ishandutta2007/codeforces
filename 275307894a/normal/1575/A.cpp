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
#define M 5
#define mod 1000000007
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,now,R[N+5];string A[N+5];
struct yyy{int id,rk;char c;}S[N+5];I bool cmp1(yyy x,yyy y) {return x.rk==y.rk?x.c<y.c:x.rk<y.rk;}I bool cmp2(yyy x,yyy y){return x.rk==y.rk?x.c>y.c:x.rk<y.rk;}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) cin>>A[i],S[i].rk=1,S[i].id=i;
 	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++) S[j].c=A[S[j].id][i-1];sort(S+1,S+n+1,i&1?cmp1:cmp2);
		for(j=1;j<=n;j++) R[j]=R[j-1]+(S[j].rk^S[j-1].rk||S[j].c^S[j-1].c);for(j=1;j<=n;j++) S[j].rk=R[j];
	}for(i=1;i<=n;i++) printf("%d ",S[i].id);
}