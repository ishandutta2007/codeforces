#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct edge{
	int to,d;
};
int d1[N],d2[N],n,cnt,ans[N];
vector <edge> e[N];
void dfs1(int id,int f){
	for(auto i:e[id])if(i.to!=f)dfs1(i.to,id),d1[id]+=i.d+d1[i.to];
}
void dfs2(int id,int f){
	for(auto i:e[id])if(i.to!=f)d2[i.to]=d2[id]+(i.d?-1:1),dfs2(i.to,id);
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back({v,0});
		e[v].push_back({u,1});
	}
	dfs1(1,0);
	d2[1]=d1[1];
	dfs2(1,0);
	int mi=n;
	for(int i=1;i<=n;i++)mi=min(mi,d2[i]);
	cout<<mi<<endl;
	for(int i=1;i<=n;i++)if(d2[i]==mi)cout<<i<<" ";
	return 0;
}