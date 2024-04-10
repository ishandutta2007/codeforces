#include<cstdio>
#include<set>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#define N 100100
using namespace std;
int x[N],y[N],z[N],w[N],tx[N*2],dis[N],from[N];
struct cmp{
	bool operator()(int i,int j)const{return y[i]<y[j];}
};
multiset<int,cmp> f[N*2];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&x[i],&y[i],&z[i],&w[i]);
		tx[i*2]=x[i];
		tx[i*2+1]=z[i];
	}
	memset(dis,-1,sizeof(dis));
	tx[0]=-1;
	sort(tx,tx+n*2+2);
	m=unique(tx,tx+n*2+2)-tx;
	for(int i=1;i<=n;i++){
		int nx=lower_bound(tx,tx+m,x[i])-tx;
		while(nx<N*2){
			f[nx].insert(i);
			nx+=nx&-nx;
		}
	}
	queue<int> q;
	q.push(0);
	dis[0]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int nx=lower_bound(tx,tx+m,z[u])-tx;
		while(nx>0){
			while(!f[nx].empty()&&w[u]>=y[*f[nx].begin()]){
				int v=*f[nx].begin();
				f[nx].erase(f[nx].begin());
				if(dis[v]==-1){
					dis[v]=dis[u]+1;
					from[v]=u;
					q.push(v);
				}
			}
			nx-=nx&-nx;
		}
	}
	vector<int> ans;
	printf("%d\n",dis[n]);
	if(dis[n]>=0){
		for(int i=n;i;i=from[i]) ans.push_back(i);
		for(int i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
	}
	return 0;
}