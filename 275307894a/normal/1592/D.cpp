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
#define N 100000
#define M 5
#define mod 1000000007
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,F[N+5],Ans,l,r,mid,now,Fh,vis[N+5],fa[N+5],x,y;queue<int> Q;
struct yyy{int to,z;}tmp;struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
I int check(int mid){
	printf("? ");printf("%d ",mid);for(RI i=1;i<=mid;i++) printf("%d ",F[i]);cout<<endl;scanf("%d",&now);return now==Ans;
}
int main(){
	RI i;scanf("%d",&n);for(i=1;i<n;i++)scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);Q.push(1);
	while(!Q.empty()) for(now=Q.front(),vis[now]=1,Q.pop(),F[++Fh]=now,i=s.h[now];i;i=tmp.z) tmp=s.f[i],!vis[tmp.to]&&(Q.push(tmp.to),fa[tmp.to]=now);
	printf("? %d ",n);for(i=1;i<=n;i++)printf("%d ",i);cout<<endl;scanf("%d",&Ans);
	l=1;r=n;while(l+1<r)mid=l+r>>1,(check(mid)?r:l)=mid;printf("! %d %d\n",F[r],fa[F[r]]);cout<<endl;
}