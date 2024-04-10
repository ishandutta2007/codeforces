#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

struct DSU{
	vector<int> bo,ss;
	void init(int n){
		bo.resize(n);
		iota(bo.begin(),bo.end(),0);
		ss.resize(n,1);
	}
	int find(int x){
		return bo[x]==x?x:bo[x]=find(bo[x]);
	}
	bool merge(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y){
			return 0;
		}
		if(ss[x]>ss[y]){
			swap(x,y);
		}
		bo[x]=y;
		ss[y]+=ss[x];
		return 1;
	}
};
int main(){
	AquA;
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int> > > e(n);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		e[a].push_back({b,c});
		e[b].push_back({a,c});
	}
	p_q<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;
	vector<long long> dis(n,1e16);
	vector<int> bo(n,-1);
	int k;
	cin >> k;
	for(int i=0;i<k;i++){
		int a;
		cin >> a;
		a--;
		dis[a]=0;
		pq.push({0,a});
		bo[a]=a;
	}
	while(!pq.empty()){
		auto h=pq.top();
		pq.pop();
		if(dis[h.sc]!=h.fs){
			continue;
		}
		for(auto k:e[h.sc]){
			if(dis[k.fs]>h.fs+k.sc){
				dis[k.fs]=h.fs+k.sc;
				pq.push({dis[k.fs],k.fs});
				bo[k.fs]=bo[h.sc];
			}
		}
	}
	vector<pair<long long,pair<int,int> > > ne;
	for(int i=0;i<n;i++){
		for(auto h:e[i]){
			if(h.fs>i){
				ne.push_back({h.sc+dis[i]+dis[h.fs],{bo[i],bo[h.fs]}});
			}	
		}
	}
	DSU dsu;
	dsu.init(n);
	long long s=0;
	sort(ne.begin(),ne.end());
	for(int i=0;i<m;i++){
		if(dsu.merge(ne[i].sc.fs,ne[i].sc.sc)){
			s+=ne[i].fs;
		}
	}
	cout << s+dis[0] << "\n";
	return 0;
}