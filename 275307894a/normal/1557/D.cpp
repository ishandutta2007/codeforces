#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 300000
#define K 50
#define mod 1000000007
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int n,m,k,x[N+5],y[N+5],z[N+5],dp[N+5],nows[N+5<<1],tots[N+5<<1],las[N+5],Fl[N+5],ToT;
struct Ques{int x,y;};vector<Ques> G[N+5];
struct pai{int w,id;pai operator +(const pai &B)const{return w>B.w?(pai){w,id}:B;};}F[N+5<<4],Sum[N+5<<4],Cl,now;
I void pushF(int now,pai z){F[now]=F[now]+z;Sum[now]=Sum[now]+z;}I void push(int x){pushF(x<<1,F[x]);pushF(x<<1|1,F[x]);F[x]=Cl;}I void Up(int now){Sum[now]=Sum[now<<1]+Sum[now<<1|1];}
I void insert(int x,int y,pai z,int l=1,int r=2*m,int now=1){
	if(x<=l&&r<=y) return pushF(now,z);push(now);int m=l+r>>1;x<=m&&(insert(x,y,z,l,m,now<<1),0);y>m&&(insert(x,y,z,m+1,r,now<<1|1),0);Up(now);
}
I pai find(int x,int y,int l=1,int r=m*2,int now=1){
	if(x<=l&&r<=y) return  Sum[now];push(now);int m=l+r>>1;pai Ans=Cl;x<=m&&(Ans=Ans+find(x,y,l,m,now<<1),0);y>m&&(Ans=Ans+find(x,y,m+1,r,now<<1|1),0);return Ans;
}
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d%d",&n,&m);for(i=1;i<=m;i++) scanf("%d%d%d",&z[i],&x[i],&y[i]),nows[i*2-1]=x[i],nows[i*2]=y[i];sort(nows+1,nows+m*2+1);for(i=1;i<=m*2;i++) tots[i]=tots[i-1]+(nows[i]!=nows[i-1]);
	for(i=1;i<=m;i++)x[i]=tots[lower_bound(nows+1,nows+2*m+1,x[i])-nows],y[i]=tots[lower_bound(nows+1,nows+2*m+1,y[i])-nows],G[z[i]].push_back((Ques){x[i],y[i]});
	for(i=1;i<=n;i++){
		now=Cl;for(j=0;j<G[i].size();j++) now=now+find(G[i][j].x,G[i][j].y);dp[i]=now.w+1;las[i]=now.id;dp[i]>dp[ToT]&&(ToT=i);for(j=0;j<G[i].size();j++) insert(G[i][j].x,G[i][j].y,(pai){dp[i],i});
	}printf("%d\n",n-dp[ToT]);while(ToT) Fl[ToT]=1,ToT=las[ToT];for(i=1;i<=n;i++) !Fl[i]&&(printf("%d ",i));
}