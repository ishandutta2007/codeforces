#include<bits/stdc++.h>
#define N 100100
#define Q 300100
using namespace std;
typedef long long ll;
ll inf=1LL<<60;
ll dis[N];
ll ans[Q];
int fr[N],f[N];
vector<int> g[N];
vector<int> w[N];
pair<int,int> qry[Q];
vector<int> qid[N];
struct obj{
	int u;
	long long d;
	bool operator<(obj rhs)const{return d>rhs.d;}
};
struct edge{
	int x,y;
	ll d;
	bool operator<(edge rhs)const{return d<rhs.d;}
}e[Q];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	obj tmp;
	int n,m,k,q,x,y,z;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		x--,y--;
		e[i].x=x;
		e[i].y=y;
		e[i].d=z;
		g[x].push_back(y);
		g[y].push_back(x);
		w[x].push_back(z);
		w[y].push_back(z);
	}
	fill(dis+k,dis+n,inf);
	priority_queue<obj> pq;
	for(int i=0;i<k;i++){
		tmp.u=i;
		tmp.d=0;
		pq.push(tmp);
		fr[i]=i;
	}
	while(!pq.empty()){
		auto x=pq.top();
		pq.pop();
		if(dis[x.u]<x.d){
			continue;
		}
		for(int i=0;i<g[x.u].size();i++){
			int v=g[x.u][i],len=w[x.u][i];
			if(x.d+len<dis[v]){
				tmp.u=v;
				tmp.d=x.d+len;
				dis[v]=tmp.d;
				pq.push(tmp);
				fr[v]=fr[x.u];
			}
		}
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&x,&y);
		x--,y--;
		qry[i].first=x;
		qry[i].second=y;
		qid[x].push_back(i);
		qid[y].push_back(i);
	}
	for(int i=0;i<m;i++){
		e[i].d+=dis[e[i].x]+dis[e[i].y];
		e[i].x=fr[e[i].x];
		e[i].y=fr[e[i].y];
		//printf("%d: %d %lld\n",e[i].x+1,e[i].y+1,e[i].d);
	}
	for(int i=0;i<n;i++){
		f[i]=i;	
	}
	sort(e,e+m);
	for(int i=0;i<m;i++){
		int fx=find(e[i].x),fy=find(e[i].y);
		if(fx!=fy){
			if(qid[fx].size()>qid[fy].size()){
				swap(fx,fy);
			}
			for(int j=0;j<qid[fx].size();j++){
				int u=qid[fx][j];
				if(find(qry[u].first)==fy||find(qry[u].second)==fy) ans[u]=e[i].d;
				qid[fy].push_back(u);
			}
			f[fx]=fy;
		}
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}