#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M (100+5)
#define K (20+5)
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
int n,m,Maxn=2,k,x,y,z,A[N],B[N];ll Ans[N],S[N];
namespace Tree{ll F[N],G[N];I void Ins(int x,int y,int z){while(x<=Maxn) F[x]+=y,G[x]+=z,x+=x&-x;}I ll Q1(int x){ll Ans=0;while(x) Ans+=F[x],x-=x&-x;return Ans;}I ll Q2(int x){ll Ans=0;while(x) Ans+=G[x],x-=x&-x;return Ans;}}
struct Line{int l,r,t,w;bool operator <(const Line &B)const{return l^B.l?l<B.l:r<B.r;};}P1;set<Line> F;set<Line>::it I1;
I void SP(int x){I1=F.lower_bound((Line){x+1,0,0,0});I1--;P1=*I1;F.erase(I1);F.insert((Line){P1.l,x,P1.t,P1.w});x^P1.r&&(F.insert((Line){x+1,P1.r,P1.t,P1.w}),0);}
struct Ques{int x,id,Fl;};vector<Ques> Q[N];
int main(){
//	freopen("1.in","r",stdin);
	int i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d%d%d",&x,&A[i],&B[i]),S[i]=S[i-1]+B[i],F.insert((Line){i,i,0,x}),B[i]&&(Maxn=max(Maxn,A[i]/B[i]+2),0);
	scanf("%d",&m);for(i=1;i<=m;i++){
		scanf("%d%d%d",&z,&x,&y);x^1&&(SP(x-1),0);SP(y);while(1){
			I1=F.lower_bound((Line){x,0,0,0});if(I1==F.end()) break;P1=*I1;if(P1.l>y) break;if(P1.w) Ans[i]+=min(1ll*(z-P1.t)*B[P1.l]+P1.w,A[P1.l]);
			else Ans[i]+=1ll*(S[P1.r]-S[P1.l-1])*(z-P1.t),Q[P1.r].PB((Ques){z-P1.t,i,1}),Q[P1.l-1].PB((Ques){z-P1.t,i,-1});F.erase(I1);
		}F.insert((Line){x,y,z,0});
	}for(i=1;i<=n;i++) {B[i]&&(Tree::Ins((A[i]+B[i]-1)/B[i]+1,A[i],B[i]),0);for(Ques d:Q[i]) Ans[d.id]+=d.Fl*Tree::Q1(min(d.x+1,Maxn))-d.x*Tree::Q2(min(d.x+1,Maxn))*d.Fl;}for(i=1;i<=m;i++) printf("%lld\n",Ans[i]);
}