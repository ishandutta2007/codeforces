#include<bits/stdc++.h>
#define N 200100
using namespace std;
int x[N],y[N],w[N];
int f[N];
vector<int> g[N],sg[N];
//g: neighbor in increasing order
//sg: edge in decreasing weight
vector<int> gp[N];
bool cmp(int i,int j){
	return w[i]>w[j];
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int to(int u,int i){
	return u^x[i]^y[i];
}
void uni(int x,int y){
	int fx=find(x),fy=find(y);
	assert(fx!=fy);
	if(gp[fx].size()<gp[fy].size()){
		swap(fx,fy);
	}
	f[fy]=fx;
	for(auto x:gp[fy]) gp[fx].push_back(x);
	gp[fy].clear();
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x[i],&y[i],&w[i]);
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
		sg[x[i]].push_back(i);
		sg[y[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		sort(sg[i].begin(),sg[i].end(),cmp);
		sort(g[i].begin(),g[i].end());
	}
	if(1LL*n*(n-1)/2-m<=n-1){
		int txor=0;
		long long ans=1LL<<60;
		vector<vector<int> >  d(n+1,vector<int>(n+1,0));
		for(int i=0;i<m;i++){
			d[x[i]][y[i]]=d[y[i]][x[i]]=w[i];
			txor^=w[i];
		}
		vector<pair<int,int> > ne;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(!d[i][j]) ne.push_back(make_pair(i,j));
			}
		}
		for(auto p:ne){
			long long tans=0;
			d[p.first][p.second]=d[p.second][p.first]=txor;
			vector<int> dmin(n+1,1<<30);
			vector<bool> vis(n+1,false);
			dmin[1]=0;
			int u=1;
			for(int t=0;t<n;t++){
				tans+=dmin[u];
				vis[u]=true;
				int nxt=0;
				for(int i=1;i<=n;i++){
					dmin[i]=min(dmin[i],d[u][i]);
					if(!vis[i] && (!nxt || dmin[i]<dmin[nxt])){
						nxt=i;
					}
				}
				u=nxt;
			}
			ans=min(ans,tans);
			d[p.first][p.second]=d[p.second][p.first]=0;
		}
		printf("%lld\n",ans);
	}
	else{
		long long ans=0;
		queue<int> pq;
		for(int i=1;i<=n;i++){
			f[i]=i;
			gp[i].push_back(i);
			pq.push(i);
		}
		vector<int> ne(n+1,n);//largest alive non-neighbor
		while(!pq.empty()){
			int u=pq.front();
			pq.pop();
			if(f[u]!=u || 1LL*gp[u].size()*(n-gp[u].size())>=m || gp[u].size()>n/2) continue;
			int bn=0,bnw=1<<30;
			for(auto i: gp[u]){
				while(ne[i]>0){
					if(!g[i].empty() && ne[i]==g[i].back()){
						g[i].pop_back();
					}
					else if(find(ne[i])!=u){
						break;
					}
					ne[i]--;
				}
				if(ne[i]) bn=ne[i],bnw=0;
				else{
					while(!sg[i].empty() && find(to(i,sg[i].back()))==u) sg[i].pop_back();
					if(!sg[i].empty() && w[sg[i].back()]<bnw){
						bn=to(i,sg[i].back());
						bnw=w[sg[i].back()];
					}
				}
			}
			if(bn){
				ans+=bnw;
				uni(u,bn);
				u=find(u);
				if(gp[u].size()<n) pq.push(u);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}