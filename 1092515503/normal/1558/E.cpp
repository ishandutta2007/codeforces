#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,a[1010],b[1010];
bool vis[1010];
ll f[1010],tot,num;int fr[1010];
vector<int>v[1010];
bool dfs(int x){
	// printf("dfs:%d<%lld>(%d)\n",x,f[x],fr[x]);
	for(auto y:v[x])if(y!=fr[x]){
		if(f[x]<=a[y])continue;
		if(f[y]==-1){
			f[y]=f[x]+b[y],fr[y]=x;
			if(dfs(y))return true;continue;
		}
		if(vis[x])continue;
		while(!vis[y])vis[y]=true,tot+=b[y],num++,y=fr[y];
		while(!vis[x])vis[x]=true,tot+=b[x],num++,x=fr[x];
		return true;
	}
	return false;
}
bool che(int val){
	// printf("che:%d\n",val);
	tot=val,num=1;for(int i=1;i<=n;i++)vis[i]=false;vis[1]=true;
	while(num<n){
		for(int i=1;i<=n;i++)f[i]=(vis[i]?tot:-1),fr[i]=-1;
		bool ok=false;
		for(int i=1;i<=n;i++)if(vis[i]&&dfs(i)){ok=true;break;}
		if(!ok)break;
	}
	return num==n;
}
void mina(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	int l=0,r=1e9+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(che(mid))r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	for(int i=1;i<=n;i++)v[i].clear();
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}