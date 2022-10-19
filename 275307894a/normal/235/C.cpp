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
#define N 2000000
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
int n,m,k,Q;char S[N+5],T[N+5<<1];ll Ans;
struct yyy{int to,z;};struct ljb{int head,h[N+5];yyy f[N+5];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
namespace SAM{
	int Len,c,son[N+5][26],cnt=1,La=1,p,q,Lk[N+5],len[N+5],si[N+5],Ns,Fl[N+5];I void Ins(int x){
		len[++cnt]=len[p=La]+1;si[La=cnt]=1;while(p&&!son[p][x]) son[p][x]=La,p=Lk[p];if(!p){Lk[La]=1;return;}q=son[p][x];
		if(len[q]==len[p]+1) {Lk[La]=q;return;}len[Lk[La]=++cnt]=len[p]+1;Mc(son[cnt],son[q]);Lk[cnt]=Lk[q];Lk[q]=cnt;while(p&&son[p][x]==q) son[p][x]=cnt,p=Lk[p];
	}I void dfs(int x){yyy tmp;for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],dfs(tmp.to),si[x]+=si[tmp.to];}I void BD(){for(RI i=2;i<=cnt;i++) s.add(Lk[i],i);dfs(1);}
	I void Qry(int ti){
	    RI i;for(i=m+1;i<2*m;i++) T[i]=T[i-m];m=2*m;Ns=1;Len=0;for(i=1;i<m;i++){c=T[i]-'a';while(Ns^1&&!son[Ns][c]) Len=len[Ns=Lk[Ns]];if(son[Ns][c]) Ns=son[Ns][c],Len++;else Ns=1,Len=0;if(Len>m/2)while(len[Lk[Ns]]>=m/2) Len=len[Ns=Lk[Ns]];Len>=m/2&&Fl[Ns]^ti&&(Ans+=si[Ns],Fl[Ns]=ti);}
	}
}
int main(){
//	freopen("tle.in","r",stdin);freopen("tle.out","w",stdout);
	RI i;scanf("%s",S+1);n=strlen(S+1);for(i=1;i<=n;i++) SAM::Ins(S[i]-'a');SAM::BD();scanf("%d",&Q);while(Q--)scanf("%s",T+1),m=strlen(T+1),Ans=0,SAM::Qry(Q+1),printf("%lld\n",Ans);
}