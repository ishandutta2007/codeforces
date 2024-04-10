/*
 * test.cpp
 *
 *
 *      Author: Fireworks
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<bitset>
#include<set>
#include<iomanip>
#include<fstream>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<list>
#include<sstream>
#include<cassert>   // assert

using namespace std;

//#define double long double

typedef pair<int,int> ii;
typedef pair<int,long long> il;
typedef pair<long long,long long> ll;
typedef pair<ll,int> lli;
typedef pair<long long,int> li;
typedef pair<double,double> dd;
typedef pair<ii,int> iii;
typedef pair<double,int> di;
long long mod = 1000000007LL;
long long base = 10000007;
long long large = 1000000000000000000LL;




vector<vector<int> > adj;
vector<vector<ii> > adj2;
vector<int> comp;
vector<int> vis;
vector<bool> flag;
void dfs(int u){
	comp.push_back(u);
	vis[u]=true;
	for(int j=0;j<(int)adj[u].size();j++){
		int v = adj[u][j];
		if(!vis[v]){
			dfs(v);
		}
	}
}

void dfs2(int u){
	comp.push_back(u);
	vis[u]=true;
	for(int j=0;j<(int)adj[u].size();j++){
		int v = adj[u][j];
		if(!vis[v]){
			dfs2(v);
		}
	}
	for(int j=0;j<(int)adj2[u].size();j++){
		int v = adj2[u][j].first;
		int e = adj2[u][j].second;
		bool mark = 1;
		if(e<0) {
			mark = 0;
			e = -e;
		}
		e--;
		if(!vis[v]){
			flag[e] = mark;
			dfs2(v);
		}
	}
}


int main(){

	int n;
	cin>>n;

	adj.assign(n,vector<int>(0,0));
	vector<ii> e;
	int m;
	cin>>m;
	int st;
	cin>>st;
	st--;
	while(m--){
		int x,y,t;
		scanf("%d%d%d",&t,&x,&y);
		x--;y--;
		if(t==1){
			adj[x].push_back(y);
		}else{
			e.push_back(ii(x,y));
		}
	}
	m = (int)e.size();
	comp.clear();
	vis.assign(n,false);
	dfs(st);
	flag.assign(m,true);
	for(int i=0;i<m;i++){
		int x = e[i].first;
		int y = e[i].second;
		if(vis[x]&&(!vis[y])) flag[i] = false;
	}

	vector<bool> re2 = flag;
	int ans2 = (int)comp.size();

	adj2.assign(n,vector<ii>(0,ii()));
	for(int i=0;i<m;i++){
		int x = e[i].first;
		int y = e[i].second;
		adj2[x].push_back(ii(y,i+1));
		adj2[y].push_back(ii(x,-(i+1)));
	}
	comp.clear();
	vis.assign(n,false);
	dfs2(st);
	cout<<comp.size()<<endl;
	for(int i=0;i<(int)re2.size();i++){
		if(flag[i]) cout<<'+';
		else cout<<'-';
	}
	cout<<endl;

	cout<<ans2<<endl;
	for(int i=0;i<(int)re2.size();i++){
		if(re2[i]) cout<<'+';
		else cout<<'-';
	}
	cout<<endl;


	return 0;

}