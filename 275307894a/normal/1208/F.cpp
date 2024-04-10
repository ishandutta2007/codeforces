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
#define N 2000000
#define K 5
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,A[N+5],Ans,ToT,Fl[N+5],st[N+5],sh;
namespace Tree{
	int F[N+5<<2];I void Ins(int x){if(F[x]>=2||Fl[x]) return;Fl[x]=1;st[++sh]=x;F[x]++;for(RI i=22;~i;i--) (x>>i&1)&&(Ins(x^(1<<i)),0);}
	I int Find(int x){int now=0;for(RI i=22;~i;i--) !(x>>i&1)&&F[now^(1<<i)]>=2&&(now+=(1<<i));return now;}
}
I void Cl(){while(sh) Fl[st[sh--]]=0;}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);
	Tree::Ins(A[n]);Cl();for(i=n-1;i>=2;i--) Tree::Ins(A[i]),ToT=Tree::Find(A[i-1]),Ans=max(Ans,ToT+A[i-1]),Cl();printf("%d\n",Ans);
}