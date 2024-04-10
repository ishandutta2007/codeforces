#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
bool vis[600100];
char c[600100];
vector<pair<int,int> >v[400100];
list<int>ls;
void dfs(int x,list<int>::iterator it){
	while(true){
		while(!v[x].empty()&&vis[v[x].back().second])v[x].pop_back();
		if(v[x].empty())return;	
		int y=v[x].back().first,z=v[x].back().second;v[x].pop_back();
		vis[z]=true;
		dfs(y,ls.insert(it,z));
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++)scanf("%d%d",&x,&y),v[x].emplace_back(y+N,i),v[y+N].emplace_back(x,i);
	m=n;
	for(int i=1;i<=(N<<1);i++)if(v[i].size()&1)m++,v[i].emplace_back(0,m),v[0].emplace_back(i,m);
	for(int i=0;i<=(N<<1);i++)if(!v[i].empty())dfs(i,ls.end());
	auto it=ls.begin();
	for(int i=0;it!=ls.end();i^=1,it++)c[*it]=(i?'b':'r');
	for(int i=1;i<=n;i++)putchar(c[i]);puts("");
	return 0;
}