#include<bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,sse4.1,sse4.2,popcnt,abm,mmx,avx,ssse3,f16c,fma,avx2,xop,fma4")
#pragma GCC optimize(2,3,"-fpeephole2,-ftree-vrp,-ftree-pre,-fipa-sra,Ofast,inline,-fgcse,-fgcse-lm,-ffast-math,-fsched-spec,unroll-loops,-falign-jumps,-falign-loops,-falign-labels,-fdevirtualize,-fcaller-saves,-fcrossjumping,-fthread-jumps,-funroll-loops,-fwhole-program,-freorder-blocks,-fschedule-insns,inline-functions,-ftree-tail-merge,-fschedule-insns2,-fstrict-aliasing,-fstrict-overflow,-falign-functions,-fcse-skip-blocks,-fcse-follow-jumps,-fsched-interblock,-fpartial-inlining,no-stack-protector,-freorder-functions,-findirect-inlining,-fhoist-adjacent-loads,-frerun-cse-after-loop,inline-small-functions,-finline-small-functions,-ftree-switch-conversion,-foptimize-sibling-calls,-fexpensive-optimizations,-funsafe-loop-optimizations,inline-functions-called-once,-fdelete-null-pointer-checks")
using namespace std;
const int N=21;
int n,a[N][N],b[N][N],ans,t;
bool c[N];
int lx[N],ly[N],w[N][N],sl[N],mt[N],p[N];
bool f[N];
void work(){
	int i,j,k,l,x,y,v,s=0;
	memset(lx,0,sizeof(lx)),memset(ly,0,sizeof(ly)),memset(mt,0,sizeof(mt)),memset(p,0,sizeof(p));
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)lx[i]=max(lx[i],w[i][j]);
	for(i=1;i<=n;++i){
		memset(sl,63,sizeof(sl)),memset(f,0,sizeof(f));
		for(mt[j=0]=i;mt[j];j=k){
			f[j]=1,l=1e9,x=mt[j];
			for(y=1;y<=n;++y)if(!f[y]){
				v=lx[x]+ly[y]-w[x][y];
				if(v<sl[y])sl[y]=v,p[y]=j;
				if(l>sl[y])l=sl[y],k=y;
			}
			for(y=0;y<=n;++y)if(f[y])lx[mt[y]]-=l,ly[y]+=l;else sl[y]-=l;
		}
		while(j)mt[j]=mt[p[j]],j=p[j];
	}
	for(i=1;i<=n;++i)s+=lx[i]+ly[i];
	ans=max(ans,s);
}
void dfs(int x,int y,int z){
	if(x>n){
		if(y==z){
			int i,j;
			for(i=1;i<=n;++i)
			if(c[i])for(j=1;j<=n;++j)w[i][j]=a[i][j];
			else for(j=1;j<=n;++j)w[i][j]=b[i][j];
			work();
			if((double)clock()/CLOCKS_PER_SEC>1.8)printf("%d",ans),exit(0);
		}
		return;
	}
	c[x]=0,dfs(x+1,y+1,z),c[x]=1,dfs(x+1,y,z+1);
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",&a[i][j]);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",&b[i][j]); 
	dfs(1,0,0),printf("%d",ans);
	return 0;
}