#include<cstdio>
#include<vector>
#define N 100100
using namespace std;
long long cnt[N];
int w[N];
bool visit[N];
int e[N*2];
int n;
vector<int> g[N];
long long DFS(int u){
	long long r=1;
	visit[u]=true;
	for(int i=0;i<g[u].size();i++){
		if(visit[e[g[u][i]]]) continue;
		long long tmp=DFS(e[g[u][i]]);
		cnt[g[u][i]>>1]=tmp*(n-tmp);
		r+=tmp;
	}
	return r;
}
int main(){
	int i,x,y,z,q;
	double ans=0;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		w[i]=z;
		e[i*2]=y;
		e[i*2+1]=x;
		g[x].push_back(i*2);
		g[y].push_back(i*2+1);
	}
	DFS(1);
	for(i=1;i<n;i++){
		ans+=6.0*cnt[i]*w[i]/n/(n-1);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d",&x,&y);
		ans+=6.0*cnt[x]*(y-w[x])/n/(n-1);
		w[x]=y;
		printf("%.10f\n",ans);
	}
	return 0;
}