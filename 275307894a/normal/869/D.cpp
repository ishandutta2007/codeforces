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
#define N 4000
#define M 30000
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
ll n,X[10],Y[10],W[N+5],Ans;int cnt,m,vis[N+5];map<ll,int> Fl,Pl;I void Ins(ll x){while(x) Fl[x]++,x>>=1;}
struct yyy{int to,z;};struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
I ll Qsize(ll now){ll L=now,R=now,cnt=0;while(R<=n) cnt+=R-L+1,L=L<<1,R=R<<1|1;return cnt+(L<=n?n-L+1:0);}
I int BD(ll now=1){if(now>n) return 0;if(!Fl[now])return W[++cnt]=Qsize(now),Pl[now]=cnt,cnt;int Id=++cnt;Pl[now]=cnt;W[Id]=1;int L=BD(now<<1),R=BD(now<<1|1);L&&(s.add(Id,L),s.add(L,Id),0);R&&(s.add(Id,R),s.add(R,Id),0);return Id;}
I ll GetAns(int x){vis[x]=1;ll sum=W[x];yyy tmp;for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],!vis[tmp.to]&&(sum+=GetAns(tmp.to));vis[x]=0;return sum%mod;}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%lld%d",&n,&m);for(i=1;i<=m;i++) scanf("%lld%lld",&X[i],&Y[i]),Ins(X[i]>>1),Ins(Y[i]>>1);BD();
	for(i=1;i<=m;i++) X[i]=Pl[X[i]],Y[i]=Pl[Y[i]],s.add(X[i],Y[i]),s.add(Y[i],X[i]);for(i=1;i<=cnt;i++) Ans=(W[i]%mod*GetAns(i)+Ans)%mod;printf("%lld\n",Ans%mod);
}