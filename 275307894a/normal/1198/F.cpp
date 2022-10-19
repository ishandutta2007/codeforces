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
#define N 200000
#define M 30000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,x,F[2],A[N+5],T,Fl,Ans[N+5];
struct Ques{int A,id;}S[N+5];
int main(){
	//freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&S[i].A),S[i].id=i;
	while((double) clock()/CLOCKS_PER_SEC<0.45){random_shuffle(S+1,S+n+1);
		F[0]=F[1]=0;for(i=1;i<=n;i++){
			if(!F[0]) {F[0]=S[i].A;Ans[S[i].id]=1;continue;}if(__gcd(F[0],S[i].A)==F[0]) {Ans[S[i].id]=2;if(!F[1]) F[1]=S[i].A;else F[1]=__gcd(F[1],S[i].A);}else F[0]=__gcd(F[0],S[i].A),Ans[S[i].id]=1;
		}if(F[0]==1&&F[1]==1) {Fl=1;break;}
	}if(Fl) {puts("YES");for(i=1;i<=n;i++) printf("%d ",Ans[i]);}else puts("NO");
}