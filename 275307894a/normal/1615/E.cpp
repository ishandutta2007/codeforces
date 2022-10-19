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
#define M 500
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,d[N+5],G[N+5],F[N+5],k,Id[N+5],R,B,W,x,y,fa[N+5];
struct yyy{int to,z;}tmp;struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
struct Ques{int id,w;bool operator <(const Ques &B)const{return w<B.w;};}now;priority_queue<Ques> Q;
I void dfs(int x,int La){d[x]=d[La]+1;fa[x]=La;yyy tmp;Id[x]=x;F[x]=d[x];for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^La&&(dfs(tmp.to,x),F[tmp.to]>F[x]&&(F[x]=F[tmp.to],Id[x]=Id[tmp.to]));}
I ll calc(int W,int R,int B){return 1ll*W*(R-B);}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&k);for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);dfs(1,0);
	Q.push((Ques){1,F[1]});while(R<k){
		if(Q.empty())break;now=Q.top();Q.pop();/*printf("%d %d\n",now.id,now.w);*/W+=now.w-1;R++;x=Id[now.id];y=0;
		while(y^now.id){
			for(j=s.h[x];j;j=tmp.z) tmp=s.f[j],tmp.to^y&&tmp.to^fa[x]&&(Q.push((Ques){tmp.to,F[tmp.to]-d[x]}),0);y=x;x=fa[x];
		}
	}B=n-W-R;
	while(R<k&&calc(W,R,B)<calc(W-1,R+1,B)) W--,R++;while(B&&calc(W,R,B)>calc(W+1,R,B-1)) B--,W++;printf("%lld\n",calc(W,R,B));
}