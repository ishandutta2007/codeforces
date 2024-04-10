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
#define N 10000
#define M 1000000
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
int n,m,k,S,T,x,y,l,r,Pus,Ro;
struct yyy{int to,w,z;}tmp;struct ljb{int head=1,h[N*50+5];yyy f[N*200+5];I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}}s;I void con(int x,int y,int z){s.add(x,y,z);s.add(y,x,0);}
namespace Dicnic{
	int Ns[N*50+5],d[N*50+5];queue<int> Q;
	I int bfs(){
		RI i;while(!Q.empty()) Q.pop();Q.push(S);Me(d,0x3f);d[S]=0;Ns[S]=s.h[S];while(!Q.empty()) for(x=Q.front(),Q.pop(),i=s.h[x];i;i=tmp.z){
			tmp=s.f[i];if(!tmp.w||d[tmp.to]<=d[x]+1) continue;d[tmp.to]=d[x]+1;Q.push(tmp.to);Ns[tmp.to]=s.h[tmp.to];if(tmp.to==T) return 1;
		}return 0;
	}
	I int dfs(int x,int sum){
		if(x==T) return sum;yyy tmp;RI i,k,pus=0;for(i=Ns[x];i;i=tmp.z){
			tmp=s.f[i];Ns[x]=i;if(!tmp.w||d[tmp.to]!=d[x]+1) continue;k=dfs(tmp.to,min(tmp.w,sum));if(!k) d[tmp.to]=1e9;sum-=k;pus+=k;s.f[i].w-=k;s.f[i^1].w+=k;if(!sum) break;
		}return pus;
	}
	I int calc(){int Ans=0;while(bfs()) Ans+=dfs(S,1e9);return Ans;}
}
struct Ques{int l,r,w;};vector<Ques> G[N+5];
namespace Tree{
	#define ls L[now]
	#define rs R[now]
	int L[N*50+5],R[N*50+5],Fl[N*50+5];I void Up(int now){!Fl[ls]&&(con(now,ls,1e9),0);!Fl[rs]&&(con(now,rs,1e9),0);}
	I void BD(int &now,int l=1,int r=n){if(l==r) {now=n+l;return;}now=++Pus;int m=l+r>>1;BD(ls,l,m);BD(rs,m+1,r);Up(now);}
	I void Ins(int x,int y,int z,int &now,int l=1,int r=n){l^r&&(Fl[++Pus]=Fl[now],L[Pus]=ls,R[Pus]=rs,now=Pus);if(x<=l&&r<=y) {Fl[now]+=z;l^r&&(Up(now),0);return;}int m=l+r>>1;x<=m&&(Ins(x,y,z,ls,l,m),0);y>m&&(Ins(x,y,z,rs,m+1,r),0);Up(now);}
	#undef ls
	#undef rs
}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);S=0;Pus=T=2*n+1;for(i=1;i<=n;i++) con(S,i,1),con(i+n,T,1);while(m--){
		scanf("%d%d%d%d",&x,&l,&y,&r),G[x].push_back((Ques){l,r,1}),G[y+1].push_back((Ques){l,r,-1});
		//for(i=x;i<=y;i++) for(j=l;j<=r;j++) Fl[i][j]=1;
	} //for(i=1;i<=n;i++) for(j=1;j<=n;j++) !Fl[i][j]&&(con(i,j+n,1e9),0);
	Tree::BD(Ro);for(i=1;i<=n;i++){for(j=0;j<G[i].size();j++)  Tree::Ins(G[i][j].l,G[i][j].r,G[i][j].w,Ro);!Tree::Fl[Ro]&&(con(i,Ro,1e9),0);}
	printf("%d\n",Dicnic::calc());
}