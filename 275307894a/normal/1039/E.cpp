#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M (1000000+5)
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
int n,m,x,k,B,A[N],lg[N],Mx[N][20],R[N],Mi[N][20],Ans[N],ToT,H[N];
I int Qry(int P,int w){int x=-1e9,y=1e9;for(int i=18;~i;i--) P+(1<<i)-1<=n&&max(x,Mx[P][i])-min(y,Mi[P][i])<=w&&(x=max(x,Mx[P][i]),y=min(y,Mi[P][i]),P+=(1<<i));return P-1;}
I int Qx(int x,int y){int d=lg[y-x+1];return max(Mx[x][d],Mx[y-(1<<d)+1][d]);}I int Qi(int x,int y){int d=lg[y-x+1];return min(Mi[x][d],Mi[y-(1<<d)+1][d]);}
struct Ques{int w,id;}S[N];I bool cmp(Ques x,Ques y){return x.w<y.w;}
namespace LCT{
	int l[N],r[N],Si[N],fa[N];I void Up(int now){Si[now]=Si[l[now]]+Si[r[now]]+1;}I int CD(int x){return l[fa[x]]==x||r[fa[x]]==x;}I int LS(int x){return l[fa[x]]==x;}
	I void RO(int x){int y=fa[x],z=fa[y],b=(LS(x)?r[x]:l[x]);CD(y)&&((LS(y)?l[z]:r[z])=x);LS(x)?(r[x]=y,l[y]=b):(l[x]=y,r[y]=b);fa[x]=z;fa[y]=x;b&&(fa[b]=y);Up(y);Up(x);}
	I void SP(int x){while(CD(x)) CD(fa[x])&&(RO(LS(x)^LS(fa[x])?x:fa[x]),0),RO(x);}I void AC(int x){for(int y=0;x;x=fa[y=x]) SP(x),r[x]=y,Up(x);}
	I int FR(int x){while(l[x]) x=l[x];return SP(x),x;}I void LK(int x,int y){AC(x);SP(x);fa[x]=y;}I void CT(int x,int y){AC(x);SP(y);r[y]=fa[x]=0;Up(y);}
	I int Qry(int &x){AC(x);SP(x);int d=Si[x];x=FR(x);return d;}
}
struct Pa{int w,id;bool operator <(const Pa &B)const{return w>B.w;}}Pus;priority_queue<Pa> Q;
int main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	int i,j;scanf("%d%d%d",&n,&m,&k);B=sqrt(n/64);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	for(i=n;i;i--){
		for(Mx[i][0]=Mi[i][0]=A[i],j=1;i+(1<<j)-1<=n;j++) Mx[i][j]=max(Mx[i][j-1],Mx[i+(1<<j-1)][j-1]),Mi[i][j]=min(Mi[i][j-1],Mi[i+(1<<j-1)][j-1]);
	}for(i=1;i<=k;i++) scanf("%d",&S[i].w),S[i].w=m-S[i].w,S[i].id=i;sort(S+1,S+k+1,cmp);for(i=1;i<=n+1;i++) LCT::Si[i]=1;
	for(i=1;i<=n;i++) R[i]=Qry(i,0),R[i]<min(n,i+B)&&(LCT::LK(i,R[i]+1),Q.push((Pa){Qx(i,R[i]+1)-Qi(i,R[i]+1),i}),0);
	for(i=1;i<=k;i++){while(!Q.empty()&&Q.top().w<=S[i].w) Pus=Q.top(),Q.pop(),LCT::CT(Pus.id,R[Pus.id]+1),R[Pus.id]=Qry(Pus.id,S[i].w),R[Pus.id]<min(n,Pus.id+B)&&(LCT::LK(Pus.id,R[Pus.id]+1),Q.push((Pa){Qx(Pus.id,R[Pus.id]+1)-Qi(Pus.id,R[Pus.id]+1),Pus.id}),0);
	x=1;ToT=0;while(x<=n) ToT+=LCT::Qry(x)-1,x<=n&&(x=Qry(x,S[i].w)+1,ToT++);Ans[S[i].id]=ToT;} for(i=1;i<=k;i++) printf("%d\n",Ans[i]-1);
}