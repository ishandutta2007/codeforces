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
#define K 1000
#define mod 998244353
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
int n,m,k,T,F[N+5],l,r,mid,G[N+5];map<int,int> A;
struct Ques{int a,b,id,Ans;}S[N+5],Q[N+5];I bool C1(Ques x,Ques y){return x.a<y.a;}I bool C2(Ques x,Ques y){return x.id<y.id;} I bool C3(Ques x,Ques y){return x.b<y.b;}
I void Solve(){
	A.clear();RI i;scanf("%d",&n);for(i=1;i<=n;i++)scanf("%d",&S[i].a);for(i=1;i<=n;i++) scanf("%d",&S[i].b),S[i].id=i;sort(S+1,S+n+1,C1);
	for(i=1;i<=n;i++) Q[i]=S[i];sort(Q+1,Q+n+1,C3);F[0]=-1e9;for(i=1;i<=n;i++) F[i]=max(F[i-1],Q[i].a); 
	G[0]=-1e9;for(i=1;i<=n;i++) G[i]=max(G[i-1],S[i].b),A[S[i].a]=i ,S[i].Ans=0; 
	S[n].Ans=1;for(i=n-1;i;i--){
		l=0;r=n;while(l+1<r) mid=l+r>>1,(Q[mid].b>G[i]?r:l)=mid;if(l==0) continue;S[i].Ans=S[A[F[l]]].Ans;
	}sort(S+1,S+n+1,C2);for(i=1;i<=n;i++) printf("%d",S[i].Ans);Pc('\n');return;
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--)Solve(); 
}