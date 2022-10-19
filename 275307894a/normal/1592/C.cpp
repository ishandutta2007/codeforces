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
struct yyy{int to,z;};struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
int T,n,m,x,y,A[N+5],Ans,Fl;
I void dfs(int x,int last){yyy tmp;for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^last&&(dfs(tmp.to,x),A[x]^=A[tmp.to]);A[x]==Ans&&(Fl++,A[x]=0);}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&T);while(T--){
		Ans=0;s.head=0;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) s.h[i]=0,scanf("%d",&A[i]),Ans^=A[i];for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(y,x),s.add(x,y);
		Fl=0;if(!Ans){printf("YES\n");continue;}dfs(1,0);puts(m>2&&Fl>=2?"YES":"NO");
	}
}