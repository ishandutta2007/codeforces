#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (60+5)
#define M ((1<<15)+5)
#define K (700+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define ui unsigned int
#define ull unsigned ll
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,k,vis[N],Ct,In[N],Fl[N],fa[N],C[N],B[N],Bh,Ch,g[M],W[M],P[N],A[N];ll ToT=1,dp[M],frc[M],Inv[M];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
I ll Ps(int x,int y){return frc[x]*Inv[x-y]%mod*Inv[y]%mod;}
I int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}
int main(){
	//freopen("1.in","r",stdin);
	int i,j,h,x,y;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",A+i),Fl[A[i]]=1;sort(A+1,A+n+1);for(frc[0]=Inv[0]=i=1;i<=60;i++) frc[i]=frc[i-1]*i%mod,Inv[i]=mpow(frc[i]);
	for(i=1;i<=n;i++) fa[i]=i;for(i=1;i<=n;i++) for(j=1;j<=n;j++) i^j&&A[i]%A[j]==0&&(In[i]++,fa[GF(i)]=GF(j));
	for(i=1;i<=n;i++){if(vis[i]) break;Bh=Ch=0;for(j=1;j<=n;j++) GF(j)==GF(i)&&(vis[j]=1,(In[j]?C[++Ch]:B[++Bh])=A[j]);
		if(!Ch) continue;Me(g,0x3f);Me(dp,0);Me(W,0);dp[0]=1;g[0]=0;k=(1<<Bh)-1;
		for(j=0;j<=k;j++){Me(P,0);for(h=1;h<=Bh;h++) if(!(j>>(h-1)&1)) for(x=B[h]*2;x<=60;x+=B[h]) P[x]++;for(h=1;h<=Ch;h++) W[j]+=(P[C[h]]>0);}
		for(j=0;j<=k;j++){
			Me(P,0);for(h=1;h<=Bh;h++) if(!(j>>(h-1)&1)) for(x=B[h]*2;x<=60;x+=B[h]) P[x]++;for(x=1;x<=Ch;x++) if(P[C[x]]){
				int op=1;h=j;for(y=1;y<=Bh;y++) if(C[x]%B[y]==0&&!(j>>(y-1)&1)) h|=(1<<y-1);else if(C[x]%B[y]==0) op=0;g[h]>g[j]+op&&(g[h]=g[j]+op,dp[h]=0);
				(g[h]==g[j]+op)&&(dp[h]=(dp[j]*Ps(W[j]-1,W[h])%mod*frc[W[j]-1-W[h]]+dp[h])%mod);
			} 
		}ToT=ToT*dp[k]%mod*Ps(Ch-1+Ct,Ct)%mod;Ct+=Ch-1;cerr<<ToT<<' '<<Ct<<'\n';
	}printf("%lld\n",ToT);
}