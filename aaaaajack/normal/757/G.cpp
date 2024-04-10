#include<bits/stdc++.h>
#define N 200100
using namespace std;
int sz[N];
vector<int> g[N],w[N];
int loc[N][20],dep[N],tloc[20],td;
long long len[N][20];
bool del[N];
void build(int u, int p, int ly, long long d){
	sz[u]=1;
	len[u][ly]=d;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p||del[v]) continue;
		build(v,u,ly,d+w[u][i]);
		sz[u]+=sz[v];
	}
}
void decom(int u){
	build(u,0,td,0);
	int tsz=sz[u],p=-1;
	bool flag=true;
	while(flag){
		flag=false;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(del[v]||v==p) continue;
			if(sz[v]+sz[v]>tsz){
				p=u;
				u=v;
				flag=true;
				break;
			}
		}
	}
	build(u,0,td,0);
	tloc[td++]=u;
	dep[u]=td;
	for(int i=0;i<td;i++){
		loc[u][i]=tloc[i];
	}
	del[u]=true;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(del[v]) continue;
		decom(v);
	}
	td--;
}
int a[N];
vector<long long> sum[N];
vector<int> ts[N];
int pos[N][20];
int main(){
	int n,q,u,v,x,t,l,r;
	long long ans=0,msk=(1LL<<30)-1;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&x);
		g[u].push_back(v);
		g[v].push_back(u);
		w[u].push_back(x);
		w[v].push_back(x);
	}
	decom(1);
	for(int i=1;i<=n;i++){
		sum[i].push_back(0);
		ts[i].push_back(-1);
	}
	for(int i=0;i<n;i++){
		u=a[i];
		for(int j=0;j<dep[u];j++){
			sum[loc[u][j]].push_back(sum[loc[u][j]].back()+len[u][j]-(j>0?len[u][j-1]:0));
			pos[u][j]=ts[loc[u][j]].size();
			ts[loc[u][j]].push_back(i);
		}
	}
	while(q--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d%d",&l,&r,&u);
			l=msk&ans^l;
			r=msk&ans^r;
			u=msk&ans^u;
			l--,r--;
			//printf("actual: %d %d %d\n",l,r,u);
			ans=0;
			for(int i=0;i<dep[u];i++){
				v=loc[u][i];
				int pr=upper_bound(ts[v].begin(),ts[v].end(),r)-ts[v].begin()-1,pl=lower_bound(ts[v].begin(),ts[v].end(),l)-ts[v].begin()-1;
				if(pl==pr) break;
				ans+=sum[v][pr]-sum[v][pl]+(pr-pl)*(len[u][i]-(i>0?len[u][i-1]:0));
			}
			printf("%I64d\n",ans);
		}
		else{
			scanf("%d",&x);
			x=msk&ans^x;
			//printf("actual: %d\n",x);
			u=a[x],v=a[x-1];
			for(int i=0;i<max(dep[u],dep[v]);i++){
				if(i<min(dep[u],dep[v])&&loc[u][i]==loc[v][i]){
					sum[loc[u][i]][pos[v][i]]=sum[loc[u][i]][pos[v][i]+1]-sum[loc[u][i]][pos[v][i]]+sum[loc[u][i]][pos[v][i]-1];
					swap(pos[u][i],pos[v][i]);
				}
				else{
					if(i<dep[u]){
						ts[loc[u][i]][pos[u][i]]--;
					}
					if(i<dep[v]){
						ts[loc[v][i]][pos[v][i]]++;
					}
				}
			}
			swap(a[x],a[x-1]);
		}
	}
	return 0;
}