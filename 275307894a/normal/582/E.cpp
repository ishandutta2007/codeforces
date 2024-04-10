#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=5e2+5,M=1<<16|5,K=400,mod=1e9+7,Mod=mod-1;const db eps=1e-5;
int n,m,k,x,y,z,A,B,C,D,E;ll f[N][M],g1[M],g2[M];char S[N];
void OR(ll *A,int n,int Fl){int i,j,h;for(i=2;i<=n;i<<=1) for(j=0;j<n;j+=i) for(h=j;h<j+i/2;h++) A[h+i/2]+=Fl*A[h];for(i=0;i<n;i++) A[i]=(A[i]%mod+mod)%mod;}
void AND(ll *A,int n,int Fl){int i,j,h;for(i=2;i<=n;i<<=1) for(j=0;j<n;j+=i) for(h=j;h<j+i/2;h++) A[h]+=A[h+i/2]*Fl;for(i=0;i<n;i++) A[i]=(A[i]%mod+mod)%mod;}
int dfs(int l,int r){
	if(l==r){
		if(S[l]=='A'||S[l]=='?') f[l][A]++;if(S[l]=='B'||S[l]=='?') f[l][B]++;if(S[l]=='C'||S[l]=='?') f[l][C]++;if(S[l]=='D'||S[l]=='?') f[l][D]++;
		if(S[l]=='a'||S[l]=='?') f[l][(k-1)^A]++;if(S[l]=='b'||S[l]=='?') f[l][(k-1)^B]++;if(S[l]=='c'||S[l]=='?') f[l][(k-1)^C]++;if(S[l]=='d'||S[l]=='?') f[l][(k-1)^D]++;return l;
	}int i,p=0,L,R;for(i=l;i<=r;i++) {p+=(S[i]=='(')-(S[i]==')');if(!p&&S[i]^')'){p=i;break;}}L=dfs(l+1,p-2);R=dfs(p+2,r-1);
	if(S[p]^'&'){for(Mc(g1,f[L]),Mc(g2,f[R]),OR(g1,k,1),OR(g2,k,1),i=0;i<k;i++) g1[i]=g1[i]*g2[i]%mod;OR(g1,k,-1);Mc(f[p],g1);}
	if(S[p]^'|'){for(Mc(g1,f[L]),Mc(g2,f[R]),AND(g1,k,1),AND(g2,k,1),i=0;i<k;i++) g1[i]=g1[i]*g2[i]%mod;AND(g1,k,-1);for(i=0;i<k;i++) f[p][i]=(f[p][i]+g1[i])%mod;}return p;
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%s",S+1);n=strlen(S+1);scanf("%d",&m);k=(1<<m);
	for(i=0;i<m;i++) cin>>x,A|=x<<i,cin>>x,B|=x<<i,cin>>x,C|=x<<i,cin>>x,D|=x<<i,cin>>x,E|=x<<i;printf("%lld\n",f[dfs(1,n)][E]);
}