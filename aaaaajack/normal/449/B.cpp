#include<cstdio>
#include<queue>
#include<utility>
#include<functional>
#include<algorithm>
#include<cstring>
#define N 100100
#define M 800100
#define inf (1LL<<60)
using namespace std;
bool pass[N]={};
struct edge{
	int x;
	int l;
	edge(int _x=0,int _l=0):x(_x),l(_l){}
	bool operator<(edge rhs)const{return l<rhs.l||(l==rhs.l&&x<rhs.x);}
}e[M];
vector<int> g[N];
int from[N];
long long dis[N];
int main(){
	int i,n,m,k,u,v,len,t,ans;
	scanf("%d%d%d",&n,&m,&k);
	ans=k;
	for(i=1;i<=n;i++){
		dis[i]=inf;
		from[i]=1023456789;
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&len);
		e[i*2]=edge(v,len);
		e[i*2+1]=edge(u,len);
		g[u].push_back(i*2);
		g[v].push_back(i*2+1);
	}
	for(i=0;i<k;i++){
		scanf("%d%d",&e[2*m+i].x,&e[2*m+i].l);
		g[1].push_back(2*m+i);
	}
	sort(e+2*m,e+2*m+k);
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;
	pq.push(make_pair(0,1));
	dis[1]=0;
	while(!pq.empty()){
		int now=pq.top().second;
		if(pq.top().first>dis[now]){
			pq.pop();
			continue;
		}
		pq.pop();
		for(i=0;i<g[now].size();i++){
			if(dis[now]+e[g[now][i]].l<dis[e[g[now][i]].x]){
				dis[e[g[now][i]].x]=dis[now]+e[g[now][i]].l;
				pq.push(make_pair(dis[e[g[now][i]].x],e[g[now][i]].x));
				if(now!=1) from[e[g[now][i]].x]=from[now];
				else from[e[g[now][i]].x]=g[now][i];
			}
			else if(dis[now]+e[g[now][i]].l==dis[e[g[now][i]].x]){
				from[e[g[now][i]].x]=min(from[now],from[e[g[now][i]].x]);
			}
		}
	}
	for(i=1;i<=n;i++){
		if(from[i]>=2*m&&from[i]<1023456789){
			pass[from[i]-2*m]=true;
		}
		//printf("%d\n",from[i]);
	}
	for(i=0;i<k;i++){
		if(pass[i]) ans--;
	}
	printf("%d\n",ans);
	return 0;
}