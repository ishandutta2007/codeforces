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
#define N (200000+5)
#define M (1<<20)
#define mod 100003
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
int n,T,Ns,x,y;ll ToT,Ans;char A[N+5],B[N+5];queue<int> Q[27];
namespace Tree{
	int F[N+5];I void Ins(int x){while(x<=n) F[x]--,x+=x&-x;}I int Qry(int x){int Ans=0;while(x) Ans+=F[x],x-=x&-x;return Ans;}
}
I void Solve(){
	RI i,j;scanf("%d",&n);for(i=0;i<26;i++) while(!Q[i].empty())Q[i].pop();scanf("%s%s",A+1,B+1);for(i=1;i<=n;i++) Q[A[i]-'a'].push(i);
	ToT=1e18;Ans=0;for(i=1;i<=n;i++){
		Ns=1e9;for(j=0;j<B[i]-'a';j++) !Q[j].empty()&&(Ns=min(Ns,Q[j].front()));if(Ns<=n)x=Ns+Tree::Qry(Ns)+(i-1),ToT=min(ToT,Ans+abs(x-i));
		if(Q[B[i]-'a'].empty()) break;Ns=Q[B[i]-'a'].front();Q[B[i]-'a'].pop();x=Ns+Tree::Qry(Ns)+(i-1);Ans+=abs(x-i);Tree::Ins(Ns);
	}printf("%lld\n",ToT<1e18?ToT:-1ll);for(i=1;i<=n;i++) Tree::F[i]=0;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}