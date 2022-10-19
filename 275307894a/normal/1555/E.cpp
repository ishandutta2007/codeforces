#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 300000
#define M 1000000
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int n,m,r,Ans=1e9,Fl[M+5<<3],Sum[M+5<<3],Maxn,x,y,z;
struct ques{int x,y;}now;vector<ques> G[M+5];
I void Up(int now){Sum[now]=Sum[now<<1]+Sum[now<<1|1];}
I void getins(int x,int y,int l=1,int r=m,int now=1){
	if(x<=l&&r<=y){Fl[now]++;Sum[now]=r-l+1;return;}int m=l+r>>1;x<=m&&(getins(x,y,l,m,now<<1),0);y>m&&(getins(x,y,m+1,r,now<<1|1),0);Sum[now]=(Fl[now]?r-l+1:Sum[now<<1]+Sum[now<<1|1]);
}
I void getdel(int x,int y,int l=1,int r=m,int now=1){
	if(x<=l&&r<=y){Fl[now]--;Sum[now]=(Fl[now]?r-l+1:Sum[now<<1]+Sum[now<<1|1]);return;}int m=l+r>>1;x<=m&&(getdel(x,y,l,m,now<<1),0);y>m&&(getdel(x,y,m+1,r,now<<1|1),0);Sum[now]=(Fl[now]?r-l+1:Sum[now<<1]+Sum[now<<1|1]);
}
I void ins(int x){for(int i=0;i<G[x].size();i++) now=G[x][i],getins(now.x*2-1,now.y*2-1);}
I void del(int x){for(int i=0;i<G[x].size();i++) now=G[x][i],getdel(now.x*2-1,now.y*2-1);}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d%d",&n,&m);m<<=1;for(i=1;i<=n;i++) scanf("%d%d%d",&x,&y,&z),G[z].push_back((ques){x,y}),Maxn=max(Maxn,z);
	for(i=1;i<=Maxn;i++){
		del(i-1);while(r<=Maxn&&Sum[1]<m-1) ins(r++);if(Sum[1]<m-1) break;Ans=min(Ans,r-i-1);
	}printf("%d\n",Ans);
}