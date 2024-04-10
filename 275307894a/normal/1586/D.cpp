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
int n,L[N+5],R[N+5],Maxn,To[N+5],now,W[N+5];
int main(){
	RI i,j;scanf("%d",&n);for(i=1;i<=n;i++){
		printf("? ");for(j=1;j<=n;j++) printf("%d ",(j==i?2:1));
		cout<<endl;scanf("%d",&L[i]);
	}
	for(i=1;i<=n;i++){
		printf("? ");for(j=1;j<=n;j++) printf("%d ",(j==i?1:2));
		cout<<endl;scanf("%d",&R[i]);
	}
	for(i=1;i<=n;i++) !L[i]&&(Maxn=i);
	for(i=1;i<=n;i++) L[i]!=i&&L[i]&&(To[L[i]]=i),R[i]!=i&&R[i]&&(To[i]=R[i]);now=Maxn;
	for(i=n;i;i--) W[now]=i,now=To[now];printf("! ");for(i=1;i<=n;i++) printf("%d ",W[i]);cout<<endl;
}