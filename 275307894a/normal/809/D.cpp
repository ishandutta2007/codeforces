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
#define N 300000
#define M N*N+5
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
#define LB lower_bound
#define UB upper_bound  
using namespace std;
int n,m,k,x,y;
namespace FT{
	#define ls son[now][0]
	#define rs son[now][1]
	int cnt,F[N+5],si[N+5],Fl[N+5],rk[N+5],son[N+5][2],Ro,R1,R2,R3,R4;I void Up(int now){si[now]=si[ls]+si[rs]+1;}
	I void PF(int now,int w){now&&(F[now]+=w,Fl[now]+=w);}I void P(int now){Fl[now]&&(PF(ls,Fl[now]),PF(rs,Fl[now]),Fl[now]=0);}I int NN(int x){F[++cnt]=x;rk[cnt]=rand();si[cnt]=1;return cnt;}
	I void SP(int x,int now,int &a,int &b){if(!now) {a=b=0;return;}P(now);x>=F[now]?(a=now,SP(x,rs,rs,b)):(b=now,SP(x,ls,a,ls));Up(now);}
	I void CT(int x,int now,int &a,int &b){if(!now) {a=b=0;return;}P(now);x>si[ls]?(a=now,CT(x-si[ls]-1,rs,rs,b)):(b=now,CT(x,ls,a,ls));Up(now);}
	I int ME(int x,int y){if(!x||!y) return x|y;P(x);P(y);return rk[x]<rk[y]?(son[x][1]=ME(son[x][1],y),Up(x),x):(son[y][0]=ME(x,son[y][0]),Up(y),y);}
	I void dfs(int x){if(!x) return;P(x);dfs(son[x][0]);cerr<<F[x]<<' ';dfs(son[x][1]);}
	I void Ins(int l,int r){SP(l-1,Ro,R1,R2);SP(r-1,R2,R2,R3);R3?(CT(1,R3,R3,R4),0):(R4=R3);PF(R2,1);Ro=ME(R1,NN(l)),Ro=ME(Ro,R2),Ro=ME(Ro,R4);}
} 
int main(){
//	freopen("vague.in","r",stdin);freopen("vague.out","w",stdout);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d%d",&x,&y),FT::Ins(x,y);printf("%d\n",FT::si[FT::Ro]);
}