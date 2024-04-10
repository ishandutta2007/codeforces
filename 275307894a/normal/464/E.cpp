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
#define N 101000
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
int n,m,k,x,y,z,Lp,S,T,Ro[N+5],Fl[N+5],Fss[N+5],Mx,La[N+5],Ns,B[N+5],Fs,Bh;ll Ans,O1[N+5],O2[N+5];const int P1=1004535809,B1=2,P2=998244353,B2=3;
struct yyy{int to,w,z;}tmp;struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}}s;
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
namespace Tree{
	int cnt,L[N*300+5],R[N*300+5],H[N*300+5],Ns,F1[N*300+5],F2[N*300+5];I void Up(int x,int l,int r){int m=l+r>>1;F1[x]=(F1[R[x]]*O1[m-l+1]+F1[L[x]])%P1;F2[x]=(F2[R[x]]*O2[m-l+1]+F2[L[x]])%P2;H[x]=H[L[x]]+H[R[x]];}
	I void MC(int &now){Ns=++cnt;F1[Ns]=F1[now];L[Ns]=L[now];R[Ns]=R[now];H[Ns]=H[now];now=Ns;}
	I int CK(int N1,int N2,int l=0,int r=Mx){if(l==r) return F1[N1]>F1[N2];int m=l+r>>1;return (F1[R[N1]]^F1[R[N2]]||F2[R[N1]]^F2[R[N2]])?CK(R[N1],R[N2],m+1,r):CK(L[N1],L[N2],l,m);}
	I void calc(int now,int l=0,int r=Mx){if(l==r) {F1[now]&&(Ans+=mpow(2,l));return;}int m=l+r>>1;calc(L[now],l,m);calc(R[now],m+1,r);}
	I void Qry(int &now,int l,int r){if(Fs) return;MC(now);if(H[now]==r-l+1) {now=0;return;}if(l==r) {Fs=1;F1[now]=F2[now]=H[now]=1;return;}int m=l+r>>1;Qry(L[now],l,m);Qry(R[now],m+1,r);Up(now,l,r);}
	I void Find(int x,int y,int &now,int l=0,int r=Mx){if(Fs) return;MC(now);if(x<=l&&r<=y) return Qry(now,l,r);int m=l+r>>1;x<=m&&(Find(x,y,L[now],l,m),0);y>m&&(Find(x,y,R[now],m+1,r),0);Up(now,l,r);}
}
struct Ques{int to,Ro;bool operator <(const Ques &B)const{return Tree::CK(Ro,B.Ro);};}now;priority_queue<Ques> Q;
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),s.add(x,y,z),s.add(y,x,z),Mx=max(Mx,z);Mx+=50;for(O1[0]=O2[0]=i=1;i<=Mx;i++) O1[i]=O1[i-1]*B1%P1,O2[i]=O2[i-1]*B2%P2;scanf("%d%d",&S,&T);
//	Tree::Find(0,Mx,Ro[0]);Fs=0;Tree::Find(1,Mx,Ro[0]);Ans=0;Tree::calc(Ro[0]);cerr<<Ans<<'\n';return 0;
	Q.push((Ques){S,0});Fl[S]=1;while(!Q.empty()) {
		/*cerr<<now.to<<'\n';*/now=Q.top();Q.pop();if(Fss[now.to]) continue;Fss[now.to]=1;
		for(i=s.h[now.to];i;i=tmp.z){tmp=s.f[i];if(Fss[tmp.to]) continue;Lp=Tree::cnt;Ro[n+1]=Ro[now.to];Fs=0;Tree::Find(tmp.w,Mx,Ro[n+1]);(!Fl[tmp.to]||Tree::CK(Ro[tmp.to],Ro[n+1]))?(Fl[tmp.to]=1,Q.push((Ques){tmp.to,Ro[n+1]}),Ro[tmp.to]=Ro[n+1],La[tmp.to]=now.to):(Tree::cnt=Lp);}
	}
	if(!Fl[T]){puts("-1");return 0;}
	Ans=0;Tree::calc(Ro[T]);printf("%lld\n",Ans%mod);Ns=T;while(Ns^S) B[++Bh]=Ns,Ns=La[Ns];B[++Bh]=Ns;printf("%d\n",Bh);for(i=Bh;i;i--) printf("%d ",B[i]);
}