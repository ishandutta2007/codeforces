#include<cstdio>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,f[1000039],siz[1000039],w[1000039],un,wn;
long long ans;
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=x*10+s-48,s=getchar();
}
struct yyy{int x,y,z;}s[1000039];
inline bool cmp(yyy x,yyy y){return x.z<y.z;}
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	read(n);m=n-1;
	for(i=1;i<=n;i++) read(w[i]);
	for(i=1;i<=m;i++)read(s[i].x),read(s[i].y),s[i].z=max(w[s[i].x],w[s[i].y]);
	sort(s+1,s+m+1,cmp);
	for(i=1;i<=n;i++) f[i]=i,siz[i]=1;
	for(i=1;i<=m;i++) {
		un=find(s[i].x);wn=find(s[i].y);
		ans+=(long long)s[i].z*siz[un]*siz[wn];
		f[un]=wn,siz[wn]+=siz[un];
	}
	for(i=1;i<=m;i++)s[i].z=min(w[s[i].x],w[s[i].y]);
	sort(s+1,s+m+1,cmp);
	for(i=1;i<=n;i++) f[i]=i,siz[i]=1;
	for(i=m;i;i--) {
		un=find(s[i].x);wn=find(s[i].y);
		ans-=(long long)s[i].z*siz[un]*siz[wn];
		f[un]=wn,siz[wn]+=siz[un];
	}
	printf("%lld\n",ans);
}