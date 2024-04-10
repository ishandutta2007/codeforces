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
#define N 500000
#define M N*N+5
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound 
using namespace std;
int n,m,k,dp[N+5],Ans=1,N1,Ls,N2,Ns,Id[N+5],W[N+5<<1],Fl[N+5<<1];char S[N+5];
struct yyy{int to,z;};struct ljb{int head,h[N+5<<1];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
namespace SAM{
	int cnt=1,len[N+5<<1],Lk[N+5<<1],q,p,La=1,son[N+5<<1][26],fa[N+5<<1][11],d[N+5<<1],lg[N+5<<1],Fr[N+5<<1];I void Ins(int x){
		len[++cnt]=len[p=La]+1;La=cnt;while(p&&!son[p][x]) son[p][x]=La,p=Lk[p];if(!p){Lk[La]=1;return;}q=son[p][x];
		if(len[q]==len[p]+1) {Lk[La]=q;return;}len[Lk[La]=++cnt]=len[p]+1;Mc(son[cnt],son[q]);Lk[cnt]=Lk[q];Lk[q]=cnt;while(p&&son[p][x]==q) son[p][x]=cnt,p=Lk[p];
	}I void Make(int x,int La){RI i;Fr[x]=(len[La]<=k?x:Fr[La]);d[x]=d[La]+1;yyy tmp;if(len[La]<=k){for(fa[x][0]=La,i=1;fa[x][i-1];i++) fa[x][i]=fa[fa[x][i-1]][i-1];}for(i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^La&&(Make(tmp.to,x),0);}
	I int Jp(int x,int Len){x=Fr[x];for(RI i=lg[d[x]];~i;i--) fa[x][i]&&len[fa[x][i]]>=Len&&(x=fa[x][i]);return x;}I void BD(){for(RI i=2;i<=cnt;i++) s.add(Lk[i],i),lg[i]=lg[i/2]+1;Make(1,0);}
}
I void Ins(int x){Ns=SAM::Jp(Id[x],dp[x]);W[Ns]=max(W[Ns],dp[x]);Ns=SAM::Lk[Ns];while(!Fl[Ns]&&Ns) Fl[Ns]=1,Ns=SAM::Lk[Ns];}
I int CK(int x){N1=SAM::Jp(Id[x],dp[x]-1);if(Fl[N1]||W[N1]>=dp[x]-1)return 1;N2=SAM::Jp(Id[x-1],dp[x]-1);return Fl[N2]||W[N2]>=dp[x]-1;}
int main(){
//	freopen("substr.in","r",stdin);freopen("substr.out","w",stdout);
	RI i,j;scanf("%d%s",&n,S+1);k=sqrt(2*n)+5;for(i=1;i<=n/2;i++) swap(S[i],S[n-i+1]);for(i=1;i<=n;i++) SAM::Ins(S[i]-'a'),Id[i]=SAM::La;SAM::BD();
	for(dp[1]=1,i=2;i<=n;i++) {N1=N2=0;dp[i]=dp[i-1]+1;while(dp[i]^1&&!CK(i)) dp[i]--,Ins(i-dp[i]);Ans=max(Ans,dp[i]);}printf("%d\n",Ans);
}