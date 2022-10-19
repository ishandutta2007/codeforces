#include<cstdio>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define beg(x) int cur=s.h[x]
#define end cur
#define go cur=tmp.z
#define l(x) x<<1
#define r(x) x<<1|1
#define N 200039
#define ll long long
#define ui unsigned int
using namespace std;
int n,m,k,x,y,z,f[4*N],a[N],op;
struct bit{
	int a[40];
	I void merge(bit x){for(int i=31;i>=0;i--)insert(x.a[i]);}
	I void insert(int x){
		for(int i=31;i>=0&&x;i--){
			if(x&(1<<i)){
				if(!a[i]){a[i]=x;break;}
				x^=a[i]; 
			}
		}
	}
	I void clear(){for(int i=31;i>=0;i--) a[i]=0;}
	I int count(){int x=0;for(int i=31;i>=0;i--)a[i]&&(x++);return x;}
}sum[4*N],tmp;
I void get(int x,int y){while(x<=n)f[x]^=y,x+=x&-x;}
I int find(int x){int ans=0;while(x) ans^=f[x],x-=x&-x;return ans;}
I void up(int x){sum[x]=sum[l(x)];sum[x].merge(sum[r(x)]);}
I void insert(int x,int y,int l=1,int r=n,int now=1){
	if(l==r) return (void)(sum[now].clear(),sum[now].insert(y));int m=l+r>>1;
	x<=m?insert(x,y,l,m,l(now)):insert(x,y,m+1,r,r(now));up(now);
}
I void build(int l=1,int r=n,int now=1){
	if(l==r) return (void)(sum[now].insert(a[l]^a[l-1]));int m=l+r>>1;
	build(l,m,l(now));build(m+1,r,r(now));up(now); 
}
I void finds(int x,int y,int l=1,int r=n,int now=1){
	if(x<=l&&r<=y) return (void)(tmp.merge(sum[now]));int m=l+r>>1;
	x<=m&&(finds(x,y,l,m,l(now)),0);y>m&&(finds(x,y,m+1,r,r(now)),0); 
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),get(i,a[i]),get(i+1,a[i]);build();
	while(m--){
		scanf("%d",&op);
		if(op==1)scanf("%d%d%d",&x,&y,&z),get(x,z),get(y+1,z),insert(x,find(x)^find(x-1)),y+1<=n&&(insert(y+1,find(y)^find(y+1)),0);
		else scanf("%d%d",&x,&y),tmp.clear(),x+1<=y&&(finds(x+1,y),0),tmp.insert(find(x)),printf("%d\n",1<<tmp.count());
	}
}