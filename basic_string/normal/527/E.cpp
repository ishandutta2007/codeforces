#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
vector<pair<int,int>>e[N];
int d[N],o;
bool v[N*3];
void add(int x,int y){++o,e[x].push_back({y,o}),e[y].push_back({x,o}),++d[x],++d[y];}
void dfs(int x){
	while(1){
		while(e[x].size()&&v[e[x].back().second])e[x].pop_back();
		if(e[x].empty())return;
		int y=e[x].back().first;
		v[e[x].back().second]=1,dfs(y);
		if((++o)&1)cout<<x<<' '<<y<<'\n';
		else cout<<y<<' '<<x<<'\n';
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,la=0;
	cin>>n>>m;
	while(m--)cin>>i>>j,add(i,j);
	for(i=1;i<=n;++i)if(d[i]&1){if(la)add(i,la),la=0;else la=i;}
	if(o&1)add(1,1);
	cout<<o<<'\n',dfs(1);
	return 0;
}