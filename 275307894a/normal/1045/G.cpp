#include<cstdio>
#include<algorithm>
#define r(x) f[x].r
#define l(x) f[x].l
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,cnt,root;
long long ans;
struct yyy{int x,y,z,tot;}s[100039];
inline bool cmp1(yyy x,yyy y){return x.x>y.x;}
inline bool cmp2(yyy x,yyy y){return x.z<y.z;}
struct tree{int l,r,f;}f[10000039];
inline void get(int x,int y,int l,int r,int &now){
	if(!now) now=++cnt;f[now].f+=y;
	if(l==r) return;
	int m=l+r>>1;
	if(x<=m) get(x,y,l,m,l(now));
	else get(x,y,m+1,r,r(now));
}
inline int find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f[now].f;
	int m=l+r>>1,fs=0;
	if(x<=m&&l(now)) fs+=find(x,y,l,m,l(now));
	if(y>m&&r(now)) fs+=find(x,y,m+1,r,r(now));
	return fs;
}
inline void slove(int x,int y){
	if(x==y) return;
	int m=x+y>>1,l=x,r=x,i;
	slove(x,m);slove(m+1,y);
	sort(s+x,s+m+1,cmp2);sort(s+m+1,s+y+1,cmp2);
	for(i=m+1;i<=y;i++){
		while(r<=m&&s[r].z-s[i].z<=k) get(s[r].y,1,0,1e9,root),r++;
		while(l<=m&&s[i].z-s[l].z>k) get(s[l].y,-1,0,1e9,root),l++;
		ans+=find(max(s[i].y-s[i].x,0),min(s[i].y+s[i].x,1e9),0,1e9,root);
	}
	for(i=l;i<r;i++) get(s[i].y,-1,0,1e9,root);
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d%d%d",&s[i].y,&s[i].x,&s[i].z);
	sort(s+1,s+n+1,cmp1);
	slove(1,n);
	printf("%lld\n",ans);
}