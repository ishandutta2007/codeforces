#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

typedef long long lli;
typedef std::pair<int, int> ip;
int n,m,q;
std::vector<int> adj[100001],rad[100001];
std::vector<lli> sum[100001];
int g[100001], dia[100001];
ip len[100001];
std::map<ip, int> tm;
std::vector<double> res;

int DFS1(int node, int p, int gn) {
	g[node]=gn;
	int m1=0,m2=0;
	for(auto &it:adj[node]) {
		if(it==p) continue;
		int tmp=DFS1(it,node,gn);
		if(tmp>m1) {
			m2=m1; m1=tmp;
		}
		else if(tmp>m2) {
			m2=tmp;
		}
	}
	len[node]=ip(m1,m2);
	return m1+1;
}
void DFS2(int node, int p, int gn, int dist) {
	dia[gn]=std::max(dia[gn],dist+len[node].first);
	int m1=dist,m2=len[node].first,m3=len[node].second;
	if(m2>m1) std::swap(m1,m2);
	if(m3>m1) std::swap(m1,m3);
	if(m3>m2) std::swap(m2,m3);
	rad[gn].push_back(m1);
	for(auto &it:adj[node]) {
		if(it==p) continue;
		if(len[it].first==m1-1) DFS2(it,node,gn,m2+1);
		else DFS2(it,node,gn,m1+1);
	}
}
void Proc(int node, int gn) {
	DFS1(node,0,gn);
	DFS2(node,0,gn,0);
	std::sort(rad[gn].begin(), rad[gn].end());
	lli prev=0;
	for(auto &it:rad[gn]){
		sum[gn].push_back(prev+it);
		prev=sum[gn].back();
	}
}
double Proc2(int a, int b){
	lli dm=std::max(dia[a],dia[b]),rs=0;
	if(rad[a].size()>rad[b].size()) std::swap(a,b);
	for(int i=0;i<rad[a].size();i++) {
		int idx=std::lower_bound(rad[b].begin(),rad[b].end(),dm-rad[a][i]-1)-rad[b].begin();
		rs+=dm*idx+rad[a][i]*(1ll*rad[b].size()-idx)+(1ll*rad[b].size()-idx);
		if(idx==0) rs+=sum[b][rad[b].size()-1];
		else rs+=sum[b][rad[b].size()-1]-sum[b][idx-1];
	}
	return rs/(double)(1ll*rad[a].size()*rad[b].size());
}
int main() {
	int u,v;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<m;i++) {
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int gn=0;
	for(int i=1;i<=n;i++) {
		if(!g[i]) Proc(i,++gn);
	}	

	int sz=0;
	res.push_back(0);
	while(q--) {
		scanf("%d %d",&u,&v);
		u=g[u],v=g[v];
		if(u==v) {
			printf("-1\n");
			continue;
		}
		if(u>v)std::swap(u,v);
		int idx;
		if((idx=tm[ip(u,v)])!=0) {
			printf("%.7lf\n",res[idx]);
			continue;
		}
		tm[ip(u,v)]=++sz;
		double rs=Proc2(u,v);
		printf("%.8lf\n",rs);
		res.push_back(rs);
	}
	return 0;
}