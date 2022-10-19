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
#define N (300000+5)
#define M (400000+5)
#define mod 998244353
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
#define PB push_back
using namespace std;
int n,m,k,op,Hi,Hd,Io[20],Is[20],Do[20],Ds[20];char A[N];ll Ans;
namespace AC{
	int Len,Tp,x,FI[N],son[N][27],cnt,Val[N],F[N][27],S[N];queue<int> Q;I int Ins(char *s){x=Tp=++cnt;Len=strlen(s+1);for(RI i=1;i<=Len;i++) son[x][s[i]-'a']=++cnt,x=son[x][s[i]-'a'];Val[x]++;return Tp;}
	I void BFS(int x){RI i;S[x]=0;FI[x]=x;Mc(F[x],son[x]);for(i=0;i<26;i++) F[x][i]?(Q.push(F[x][i]),FI[F[x][i]]=x):(F[x][i]=x);
	while(!Q.empty()) for(x=Q.front(),Q.pop(),S[x]=S[FI[x]]+Val[x],Mc(F[x],son[x]),i=0;i<26;i++) F[x][i]?(Q.push(F[x][i]),FI[F[x][i]]=F[FI[x]][i]):(F[x][i]=F[FI[x]][i]);}
	I int ME(int x,int y){if(!x||!y) return x|y;Val[x]+=Val[y];for(RI i=0;i<26;i++) son[x][i]=ME(son[x][i],son[y][i]);return x;}
	I ll Qry(int x,char *A){ll Ans=0;Len=strlen(A+1);for(RI i=1;i<=Len;i++) x=F[x][A[i]-'a'],Ans+=S[x];return Ans;} 
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);while(n--){
		scanf("%d%s",&op,A+1);if(op==1){Io[++Hi]=AC::Ins(A);AC::BFS(Io[Hi]);Is[Hi]=1;while(Is[Hi]==Is[Hi-1]) Hi--,Is[Hi]<<=1,AC::ME(Io[Hi],Io[Hi+1]),AC::BFS(Io[Hi]);}
		else if(op==2){Do[++Hd]=AC::Ins(A);AC::BFS(Do[Hd]);Ds[Hd]=1;while(Ds[Hd]==Ds[Hd-1]) Hd--,Ds[Hd]<<=1,AC::ME(Do[Hd],Do[Hd+1]),AC::BFS(Do[Hd]);}
		else {Ans=0;for(i=1;i<=Hi;i++) Ans+=AC::Qry(Io[i],A);for(i=1;i<=Hd;i++) Ans-=AC::Qry(Do[i],A);printf("%lld\n",Ans);fflush(stdout);}
	}
}