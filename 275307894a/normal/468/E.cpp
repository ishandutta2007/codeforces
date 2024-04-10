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
#define N 200000
#define M 50
#define W (1<<20)
#define mod 1000000007
#define eps (1e-7)
#define U unsigned int
#define IT set<ques>::iterator
using namespace std;
int n,m,x,y,z,cntn,cntm,fl[N+5];ll G[M+5],F[M+5]={1},frc[N+5],Ans;
struct yyy{int to,w,z;}tmp;
struct ljb{
	int head=1,h[N+5];yyy f[M+5<<1];
	I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}
}s;
I void dfs(int x,int last){if(fl[x]) return;yyy tmp;cntn++;fl[x]=1;for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],cntm++,tmp.to^last&&(dfs(tmp.to,x),0);}
I void GetAns(){re int i,j;for(i=m;~i;i--) for(F[i]%=mod,j=m;j>i;j--) F[j]+=G[j-i]*F[i]%mod;}
struct Solve1{
	int A[N+5],B[N+5],C[N+5],Ah,Bh,bas[W+5],now,last,fl[N+5];ll dp[2][W+5];
	I void calc(){re int i;for(i=0;i<W;i++) {now=i;while(now) bas[i]++,now-=now&-now;}}
	I void dfs(int x){if(fl[x]) return;fl[x]=1;yyy tmp;(x>n?A[++Ah]:B[++Bh])=x;for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],dfs(tmp.to);}
	I void solve(int x){
		re int i,j,h;memset(C,0,sizeof(C));Ah=Bh=0;memset(dp,0,sizeof(dp));dp[0][0]=1;dfs(x);for(i=1;i<=Bh;i++) C[B[i]]=i;/*if(Bh>20){printf("1\n");exit(0);}*/
		for(i=1;i<=Ah;i++){
	    	now=i&1;last=now^1;for(j=0;j<(1<<Bh);j++){
    			dp[now][j]=dp[last][j];for(h=s.h[A[i]];h;h=tmp.z){
    				tmp=s.f[h];if(!((j>>C[tmp.to]-1)&1))continue;
    				dp[now][j]=(dp[now][j]+dp[last][j^(1<<C[tmp.to]-1)]*tmp.w)%mod;
    			}
    		}
    	}
    	memset(G,0,sizeof(G));for(i=0;i<(1<<Bh);i++) G[bas[i]]+=dp[Ah&1][i];for(i=1;i<=Bh;i++) G[i]%=mod;
	}
}S1;
struct Solve2{
	ljb Gs;yyy C[M+5],tmp;int fl[N+5],siz[N+5],Ch,flag,Ans,Fl[M+5<<1];ll dp[N+5][M+5][2],ToT;
	I void dfs(int x,int last){
	    yyy tmp;fl[x]=1;for(int i=s.h[x];i;i=tmp.z) {
	    	tmp=s.f[i];if(tmp.to==last) continue;
			fl[tmp.to]?(!Fl[i^1]&&!Fl[i]&&(C[++Ch]=(yyy){x,tmp.w,tmp.to},Fl[i]=1)):(Gs.add(x,tmp.to,tmp.w),Gs.add(tmp.to,x,tmp.w),Fl[i]=1,dfs(tmp.to,x),0);
		}
    }
    I void clear(int x){if(!fl[x]) return;fl[x]=0;yyy tmp;for(int i=s.h[x];i;i=tmp.z)tmp=s.f[i],clear(tmp.to);}
	I void Make(int x,int last){
		/*printf("%d\n",x);*/yyy tmp;memset(dp[x],0,sizeof(dp[x]));dp[x][0][0]=siz[x]=1;re int i,j,h;for(h=Gs.h[x];h;h=tmp.z){
			tmp=Gs.f[h];if(tmp.to==last) continue;Make(tmp.to,x);
			for(i=siz[x];~i;i--){
				for(j=0;j<=siz[tmp.to];j++){
					if(j)dp[x][i+j][0]=(dp[x][i+j][0]+dp[x][i][0]*(dp[tmp.to][j][0]+dp[tmp.to][j][1]))%mod;
					if(j)dp[x][i+j][1]=(dp[x][i+j][1]+dp[x][i][1]*(dp[tmp.to][j][0]+dp[tmp.to][j][1]))%mod;
					if(!fl[x]&&!fl[tmp.to]) dp[x][i+j+1][1]=(dp[x][i+j+1][1]+dp[x][i][0]*dp[tmp.to][j][0]%mod*tmp.w)%mod;
				} 
			}siz[x]+=siz[tmp.to];
		}
	}
	I void solve(int x){
		memset(G,0,sizeof(G));re int i,j,h;Ch=0;dfs(x,x);clear(x);for(i=0;i<(1<<Ch);i++){
			for(ToT=1,flag=Ans=0,j=1;j<=Ch;j++)((i>>j-1)&1)&&(Ans++,ToT=ToT*C[j].w%mod,flag|=fl[C[j].to]|fl[C[j].z],fl[C[j].to]=fl[C[j].z]=1);
			if(!flag) {Make(x,x);for(j=0;j<=siz[x];j++)G[j+Ans]=((dp[x][j][0]+dp[x][j][1])*ToT+G[j+Ans])%mod;}for(j=1;j<=Ch;j++) ((i>>j-1)&1)&&(fl[C[j].to]=fl[C[j].z]=0);
		}
	}
}S2;
int main(){
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	re int i,j,h;scanf("%d%d",&n,&m);for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),s.add(x,y+n,z-1),s.add(y+n,x,z-1);frc[0]=1;for(i=1;i<=n;i++)frc[i]=frc[i-1]*i%mod;
	S1.calc();for(i=1;i<=n;i++){
		if(fl[i]) continue;cntn=cntm=0;dfs(i,i);cntm>>=1;if(cntn<=cntm*2/3)S1.solve(i);
		else S2.solve(i);GetAns();
	} 
	for(i=0;i<=m;i++) Ans+=frc[n-i]*F[i]%mod;printf("%lld\n",Ans%mod);
}