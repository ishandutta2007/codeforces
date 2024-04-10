#include <vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200
#define M 1000
#define eps (1e-5)
#define mod (1<<31)
#define U unsigned int
using namespace std;
int n,m,x,y,z,d[N+5],nows[N+5],fr[N+5],en[N+5],A[N+5],S,T,fa[N+5],now,Bh,Ch,B[N+5],C[N+5],H,un,wn,ToT;
struct yyy{int to,w,z;}tmp;
struct ljb{
	int head,h[N+5];yyy f[M+5<<2];
	I void add(int x,int y,int z){f[head]=(yyy){y,z,h[x]};h[x]=head++;}
}s,G;queue<int> Q;
struct ques{int x,y,z;}F[N+5];
I bool cmp(ques x,ques y){return x.z>y.z;}
I void Get(int x,int y,int z){s.add(x,y,z);s.add(y,x,z);}
I int bfs(){
	while(!Q.empty()) Q.pop();memset(d,0x3f,sizeof(d));d[S]=0;Q.push(S);nows[S]=s.h[S];
	while(!Q.empty()){
		now=Q.front();Q.pop();for(int i=s.h[now];~i;i=tmp.z){
			tmp=s.f[i];if(!tmp.w||d[tmp.to]<1e9) continue;d[tmp.to]=d[now]+1;
			Q.push(tmp.to);nows[tmp.to]=s.h[tmp.to];if(tmp.to==T) return 1;
		}
	}
	return 0;
}
I int dfs(int x,int sum){
	if(x==T) return sum;int i,k,pus=0;yyy tmp;for(i=nows[x];~i;i=tmp.z){
		tmp=s.f[i];nows[x]=i;if(!tmp.w||d[tmp.to]!=d[x]+1) continue;k=dfs(tmp.to,min(sum,tmp.w));
		if(!k) d[tmp.to]=1e9;pus+=k;sum-=k;s.f[i].w-=k;s.f[i^1].w+=k;if(!sum) break;
	}
	return  pus;
}
I void build(int l,int r){
	if(l==r) return;int Ans=0,i;S=A[l];T=A[r];s=G;while(bfs()) Ans+=dfs(S,1e9);F[++H]=(ques){S,T,Ans};ToT+=Ans;//printf("%d %d %d %d %d\n",A[l],A[r],l,r,Ans);
	Bh=Ch=0;for(i=l;i<=r;i++) (d[A[i]]<1e9?B[++Bh]:C[++Ch])=A[i];for(i=l;i<=l+Bh-1;i++) A[i]=B[i-l+1];
	for(i=l+Bh;i<=r;i++) A[i]=C[i-l-Bh+1];Ans=Bh;build(l,l+Ans-1);build(l+Ans,r);
}
I int Getfa(int x){return x==fa[x]?x:fa[x]=Getfa(fa[x]);}
int main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	re int i;scanf("%d%d",&n,&m);memset(s.h,-1,sizeof(s.h));for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),Get(x,y,z);
	for(i=1;i<=n;i++) A[i]=i;G=s;build(1,n);sort(F+1,F+n,cmp);for(i=1;i<=n;i++) fa[i]=en[i]=fr[i]=i; 
	for(i=1;i<n;i++)un=Getfa(F[i].x),wn=Getfa(F[i].y),en[un]=fr[wn],fr[wn]=fr[un],fa[un]=wn;now=fr[Getfa(1)];
	printf("%d\n",ToT);while(en[now]^now) printf("%d ",now),now=en[now];printf("%d\n",now);
}