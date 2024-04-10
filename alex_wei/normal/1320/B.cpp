#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int dis[N],n,m,k,p[N],vis[N];
vector <int> e[N];
map <int,int> mp[N];
struct node{
	int id,len;
};
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[v].push_back(u);
	}
	cin>>k;
	for(int i=1;i<=k;i++)cin>>p[i];
	int S=p[1],T=p[k];
	queue <node> q;
	q.push({T,0}),vis[T]=1;
	while(!q.empty()){
		node t=q.front(); q.pop();
		dis[t.id]=t.len;
		for(auto to:e[t.id]){
			if(!vis[to]){
				vis[to]=1;
				q.push({to,t.len+1});
			}
		}
	}
	for(int i=1;i<=n;i++)for(auto to:e[i])mp[to][dis[i]]++;
	int mi=0,ma=0;
	for(int i=2;i<=k;i++){
		int l=p[i-1],r=p[i];
		if(dis[l]<=dis[r])mi++,ma++;
		else if(mp[l][dis[r]]>1)ma++;
	}
	cout<<mi<<" "<<ma<<endl;
    return 0;
}