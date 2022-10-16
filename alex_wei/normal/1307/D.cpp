#include<bits/stdc++.h>
using namespace std;
#define mmpljsbD make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long

int n,m,k,a[200005],dis[200005],vis[200005],G[200005],ans;

struct ed{
	int to,w;
};
struct node{
	int dis,x;
	bool operator < (const node &j) const {
		return dis>j.dis;
	}
};
priority_queue <node> q;
vector <ed> d[200002];
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push((node){0,s});
	while(!q.empty()){
		node t=q.top();
		int g=t.x;
		q.pop();
		if(vis[g])continue;
		vis[g]=1;
		for(int i=0;i<d[g].size();i++){
			int h=d[g][i].to,w=d[g][i].w;
			if(!vis[h]&&dis[g]+w<dis[h]){
				dis[h]=dis[g]+w;
				q.push((node){dis[h],h});
			}
		}
	}
}
const int N=2e5+5;
int cnt,mx[N];
pii c[N];
bool check(int dd){
	for(int i=1;i<=k;i++){
		int p=max(i+1,lower_bound(c+1,c+k+1,mmpljsbD(dd-c[i].se,0))-c);
		if(k>=p&&c[i].fi+mx[p]>=dd)return true;
	}
	return false;
}
int bs(int l,int r){
	if(l==r)return l;
	int m=(l+r>>1)+1;
	if(check(m))return bs(m,r);
	else return bs(l,m-1);
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)cin>>a[i],G[a[i]]=1;
	int pd=0;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if(G[u]&&G[v])pd=1;
		d[u].push_back({v,1});
		d[v].push_back({u,1});
	}
	dij(1);
	int cnt=0; ans=dis[n];
	for(int i=1;i<=n;i++)if(G[i])c[++cnt].fi=dis[i];
	dij(n);
	cnt=0;
	for(int i=1;i<=n;i++)if(G[i])c[++cnt].se=dis[i];
	sort(c+1,c+k+1);
	for(int i=k;i;i--)mx[i]=max(mx[i+1],c[i].se);
	cout<<min(ans,1+bs(0,n));
    return 0;
}