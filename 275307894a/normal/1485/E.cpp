#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define CI const int &
#define ll long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t,a[200039],d[200039],nows[200039],tots[200039],ys[200039],l,r,mid,now,minn,maxn;
ll ans,dp[200039];
struct yyy{int to,z;}tmp;
struct ljb{
	int head,h[200039];yyy f[200039];
	inline void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s;
vector<int> g[200039];
struct tree{
	ll sum[800039];
	inline void clear(int x,int y,CI l=1,CI r=n,CI now=1){
	    if(x<=l&&r<=y){sum[now]=-1e18;return;}
	    int m=l+r>>1;
	    if(x<=m) clear(x,y,l,m,now<<1);
     	if(y>m) clear(x,y,m+1,r,now<<1|1);
     }
     inline ll find(int x,CI l=1,CI r=n,CI now=1){
     	if(l==r)return sum[now];
		 int m=l+r>>1;ll fs=-1e18;
		 if(x<=m) fs=find(x,l,m,now<<1);
		 else fs=find(x,m+1,r,now<<1|1);
		 return max(fs,sum[now]); 
     }
     inline void get(int x,int y,ll z,CI l=1,CI r=n,CI now=1){
     	if(x<=l&&r<=y) {sum[now]=max(sum[now],z);return;}
     	int m=l+r>>1;
     	if(x<=m) get(x,y,z,l,m,now<<1);
     	if(y>m) get(x,y,z,m+1,r,now<<1|1);
     }
}f1,f2;
inline void dfs(int x){
	yyy tmp;
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];
		d[tmp.to]=d[x]+1;dfs(tmp.to);
	}
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&t);memset(f1.sum,-0x3f,sizeof(f1.sum));memset(f2.sum,-0x3f,sizeof(f2.sum));
	while(t--){
		for(i=1;i<=n;i++) dp[i]=d[i]=s.h[i]=0,g[i].clear();s.head=0;ans=0;g[0].clear();
		for(i=1;i<=4*n;i++) f1.sum[i]=f2.sum[i]=-1e18;
		scanf("%d",&n);
		for(i=2;i<=n;i++) scanf("%d",&x),s.add(x,i);
		for(i=2;i<=n;i++) scanf("%d",&a[i]),nows[i-1]=a[i];
		dfs(1);
		for(i=1;i<=n;i++)g[d[i]].push_back(i);
		sort(nows+1,nows+n);
		for(i=1;i<n;i++) tots[i]=(i^1)?(tots[i-1]+(nows[i]!=nows[i-1])):1,ys[tots[i]]=nows[i];
		for(i=2;i<=n;i++){
			l=0;r=n-1;
			while(l+1<r){
				mid=l+r>>1;
				if(nows[mid]<a[i]) l=mid;
				else r=mid;
			}
			a[i]=tots[r];
		}
		for(i=1;;i++){
			if(!g[i].size()) break;
			for(j=0;j<g[i-1].size();j++){
				now=g[i-1][j];yyy tmp;
				for(int cur=s.h[now];cur;cur=tmp.z){
					tmp=s.f[cur];
				    f1.get(1,a[tmp.to],dp[now]+ys[a[tmp.to]]);f2.get(a[tmp.to],n,dp[now]-ys[a[tmp.to]]);
				}
			}minn=1e9;maxn=-1e9;
			for(j=0;j<g[i].size();j++) now=g[i][j],dp[now]=max(f1.find(a[now])-ys[a[now]],f2.find(a[now])+ys[a[now]]);
			for(j=0;j<g[i].size();j++) now=g[i][j],minn=min(minn,ys[a[now]]),maxn=max(maxn,ys[a[now]]);
			for(j=0;j<g[i-1].size();j++){
				now=g[i-1][j];yyy tmp;
				for(int cur=s.h[now];cur;cur=tmp.z){
					tmp=s.f[cur];dp[tmp.to]=max(dp[tmp.to],dp[now]+max(maxn-ys[a[tmp.to]],ys[a[tmp.to]]-minn));
				}
			}
			for(j=0;j<g[i-1].size();j++){
				now=g[i-1][j];yyy tmp;
				for(int cur=s.h[now];cur;cur=tmp.z){
					tmp=s.f[cur];
				    f1.clear(1,a[tmp.to]);f2.clear(a[tmp.to],n);
				}
			}
		}
		for(i=1;i<=n;i++) ans=max(ans,dp[i]);
		printf("%lld\n",ans);
	}
}