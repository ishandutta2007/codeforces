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
#define K 30
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
int n,x,Ro;ll Ans;
namespace Tree{
	#define ls L[now]
	#define rs R[now]
	int L[N*K+5],R[N*K+5],cnt,F[N*K+5];vector<int> S[N*K+5];
	I void Ins(int x,int &now,int d=29){!now&&(now=++cnt);S[now].push_back(x);F[now]++;if(d==-1) return;x>>d&1?Ins(x,rs,d-1):Ins(x,ls,d-1);}
	I int Qry(int x,int now,int d){if(d==-1) return 0;return F[x>>d&1?rs:ls]?Qry(x,x>>d&1?rs:ls,d-1):Qry(x,x>>d&1?ls:rs,d-1)|(1<<d);}
	I void GA(int now,int d=29){
		if(!now) return;GA(ls,d-1);GA(rs,d-1);if(!ls||!rs) return;int un=(F[ls]<F[rs]?ls:rs),wn=ls+rs-un,P1=0,P2=2e9;
		for(RI i=0;i<S[un].size();i++) P1=Qry(S[un][i],wn,d-1),P2=min(P2,P1);Ans+=P2+(1<<d);
	}
}
int main(){
////	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++)scanf("%d",&x),Tree::Ins(x,Ro);Tree::GA(Ro);printf("%lld\n",Ans);
}