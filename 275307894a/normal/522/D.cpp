#include<cstdio>
#include<algorithm>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,a[500039],f[2000039],nows[500039],l,r,mid,tots[500039],ans[500039],head,top[500039];
inline void get(int x,int y,int l,int r,int now){
    if(l==r){f[now]=y;return;}
    int m=(l+r)>>1;
    if(x<=m) get(x,y,l,m,now<<1);
    else get(x,y,m+1,r,now<<1|1);
    f[now]=min(f[now<<1],f[now<<1|1]);
}
inline int find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f[now];
	int m=(l+r)>>1,ans1=1e9,ans2=1e9;
	if(x<=m) ans1=find(x,y,l,m,now<<1);
	if(y>m) ans2=find(x,y,m+1,r,now<<1|1);
	return min(ans1,ans2);
}
struct yyy{int x,y,num;}s[500039];
inline bool cmp(yyy x,yyy y){return x.y<y.y;}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	memset(f,0x3f,sizeof(f));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),nows[i]=a[i];
	sort(nows+1,nows+n+1);
	nows[0]=nows[1]-1;
	for(i=1;i<=n;i++){
		tots[i]=tots[i-1];
		if(nows[i]!=nows[i-1]) tots[i]++;
	}
	for(i=1;i<=n;i++){
		l=0;r=n+1;
		while(l+1<r){
			mid=(l+r)>>1;
			if(nows[mid]<a[i]) l=mid;
			else r=mid;
		}
		a[i]=tots[r];
	}
	for(i=1;i<=m;i++) scanf("%d%d",&s[i].x,&s[i].y),s[i].num=i;
	sort(s+1,s+m+1,cmp);
	for(i=1;i<=m;i++){
		while(head<s[i].y){
			head++;
			if(top[a[head]])get(top[a[head]],head-top[a[head]],1,n,1);
			top[a[head]]=head;
		}
		ans[s[i].num]=find(s[i].x,s[i].y,1,n,1);
	}
	for(i=1;i<=m;i++) if(ans[i]>=1e9)printf("-1\n");
	else printf("%d\n",ans[i]);
}