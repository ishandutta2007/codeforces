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
#define M 10
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,x,Ro,cnt,La,T,Ts;const int INF=1e9;
namespace Tree{
	#define ls L[now]
	#define rs R[now]
	#define NN(now,l,r) (!now&&(now=++cnt,Rs[now]=r,Ls[now]=l))
	int L[N*200+5],R[N*200+5],Ls[N*200+5],Rs[N*200+5],Fl[N*200+5];
	I void PF(int &now,int l,int r,int w){NN(now,l,r);Ls[now]+=w;Rs[now]+=w;Fl[now]+=w;}
	I void P(int &now,int l,int r){int m=l+r>>1;PF(ls,l,m,Fl[now]);PF(rs,m+1,r,Fl[now]);Fl[now]=0;}I void Up(int now){Ls[now]=Ls[ls];Rs[now]=Rs[rs];}
	I int Find(int x,int &now,int l=0,int r=INF){NN(now,l,r);if(l==r) return Ls[now];int m=l+r>>1;P(now,l,r);x<=m?Find(x,ls,l,m):Find(x,rs,m+1,r);}
	I void Q1(int x,int &now,int l=0,int r=INF){NN(now,l,r);if(l==r) {Ls[now]<x&&(PF(now,l,r,1),0);return;}int m=l+r>>1;P(now,l,r);Rs[ls]<x?(PF(ls,l,m,1),Q1(x,rs,m+1,r)):Q1(x,ls,l,m);Up(now);}
	I void Q2(int x,int &now,int l=0,int r=INF){NN(now,l,r);if(l==r) {Ls[now]>x&&(PF(now,l,r,-1),0);return;}int m=l+r>>1;P(now,l,r);Ls[rs]>x?(PF(rs,m+1,r,-1),Q2(x,ls,l,m)):Q2(x,rs,m+1,r);Up(now);}
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&T);while(T--){
		scanf("%d",&Ts);Tree::Q1(Ts,Ro);Tree::Q2(Ts,Ro);
		scanf("%d",&n);while(n--)scanf("%d",&x),x=(x+La)%(INF+1),printf("%d\n",La=Tree::Find(x,Ro));
	}
}