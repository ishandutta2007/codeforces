#include<bits/stdc++.h>
#define I inline
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 200000
#define M 60
#define mod 20170408
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Pc(x) putchar(x) 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
using namespace std;
int n,m,p,Ans,Fl[M+5],ToT[M+5],cnt[M+5],Cnt;bitset<N+5> F[M+5],G;char c;
I void dfs(int x,int w){
	if(Ans==Cnt) return;if(w>Ans){Ans=w;memcpy(ToT,Fl,sizeof(Fl));}if(x==m+1) return;
	if(cnt[x]>=(n+1>>1)){bitset<N+5> las=G;G&=F[x];if(G.count()>=(n+1>>1)) Fl[x]=1,dfs(x+1,w+1),Fl[x]=0;G=las;}dfs(x+1,w);
}
int main(){
	//freopen("1.in","r",stdin);
	re int i,j;scanf("%d%d%d",&n,&m,&p);for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++){c=Gc();while(c<'0'||c>'1') c=Gc();F[j][i]=c-'0';cnt[j]+=c-'0';}
	}for(i=1;i<=m;i++) Cnt+=(cnt[i]>=(n+1>>1));for(i=1;i<=n;i++)G[i]=1;dfs(1,0);for(i=1;i<=m;i++)printf("%d",ToT[i]);
}