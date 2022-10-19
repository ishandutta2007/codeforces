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
#define N 200000
#define M 300000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,x,y,z;ll d[N+5][2][2];
struct yyy{int to,w,z;}tmp;struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}}s;
struct Qs{ll w;int To,I1,I2;bool operator <(const Qs &x)const{return w>x.w;}}X;priority_queue<Qs>Q;
int main(){
//	freopen("1.in","r",stdin);
	RI i;Me(d,0x3f);scanf("%d%d",&n,&m);for(i=1;i<=m;i++)scanf("%d%d%d",&x,&y,&z),s.add(x,y,z),s.add(y,x,z);d[1][0][0]=0;Q.push((Qs){0,1,0,0});
	while(!Q.empty()){
		X=Q.top();Q.pop();if(X.w^d[X.To][X.I1][X.I2]) continue;for(i=s.h[X.To];i;i=tmp.z){
	    	tmp=s.f[i];if(d[tmp.to][X.I1][X.I2]>d[X.To][X.I1][X.I2]+tmp.w)d[tmp.to][X.I1][X.I2]=d[X.To][X.I1][X.I2]+tmp.w,Q.push((Qs){d[tmp.to][X.I1][X.I2],tmp.to,X.I1,X.I2});
    		if(!X.I1&&d[tmp.to][1][X.I2]>d[X.To][0][X.I2]+tmp.w*2)d[tmp.to][1][X.I2]=d[X.To][0][X.I2]+tmp.w*2,Q.push((Qs){d[tmp.to][1][X.I2],tmp.to,1,X.I2});
    		if(!X.I2&&d[tmp.to][X.I1][1]>d[X.To][X.I1][0])d[tmp.to][X.I1][1]=d[X.To][X.I1][0],Q.push((Qs){d[tmp.to][X.I1][1],tmp.to,X.I1,1});
    	}
	}
	for(i=2;i<=n;i++)printf("%lld ",min(d[i][1][1],d[i][0][0])>1e18?-1:min(d[i][1][1],d[i][0][0]));
}