#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (300000+5)
#define M ((1<<16)+5)
#define K (1000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
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
using namespace std;vector<int> Id[N];
int T,n,m,A[N],Ns[N],H,Fs[N],x,y;ll Ans;map<int,int> Fl[N],Ps;
struct Ques{int w,id;};I bool cmp(Ques x,Ques y){return x.w<y.w;}I bool C2(int x,int y){return Ns[x]>Ns[y];}
I void Solve(){Ans=-1e18;
	int i,j,h;scanf("%d%d",&n,&m);H=0;for(i=1;i<=n;i++) Id[i].clear(),Fl[i].clear(),Id[i].clear(),Fs[i]=0;Ps.clear();
	for(i=1;i<=n;i++) scanf("%d",&A[i]),!Ps[A[i]]&&(Ns[Ps[A[i]]=++H]=A[i]),A[i]=Ps[A[i]],Fs[A[i]]++;
	for(i=1;i<=H;i++) Id[Fs[i]].PB(i);for(i=1;i<=n;i++) sort(Id[i].begin(),Id[i].end(),C2);
	for(i=1;i<=m;i++) scanf("%d%d",&x,&y),Fl[Ps[x]][Ps[y]]=Fl[Ps[y]][Ps[x]]=1;
	for(i=1;i<=H;i++){
		for(j=1;j<=Fs[i];j++) {
			for(int h:Id[j]) if(h^i&&!Fl[i].count(h)){Ans=max(Ans,1ll*(j+Fs[i])*(Ns[i]+Ns[h]));break;} 
		}
	}printf("%lld\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}