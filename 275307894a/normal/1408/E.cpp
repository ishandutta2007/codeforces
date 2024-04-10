#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,a[100039],b[100039],f[200039],t,head,cnt,un,wn;
long long ans;
struct yyy{int to,z,w;}s[1000039];
inline bool cmp(yyy x,yyy y){return x.w>y.w;}
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		while(t--) scanf("%d",&x),s[++head]=(yyy){i,x+n,a[i]+b[x]},ans+=a[i]+b[x];
	}
	sort(s+1,s+head+1,cmp);
	for(i=1;i<=n+m;i++)f[i]=i;
	for(i=1;i<=head;i++){
		un=find(s[i].to);wn=find(s[i].z);
		if(un==wn) continue;
		cnt++;
		ans-=s[i].w;
		f[un]=wn;
		if(cnt==n+m-1) break;
	}
	printf("%lld\n",ans);
}