#include<bits/stdc++.h>
#define no puts("NO"),exit(0)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=105;
int n,m,pd[N];
vector <int> e[N];
void dfs(int id){
	pd[id]=1;
	for(int i=0;i<e[id].size();i++)
		if(!pd[e[id][i]])
			dfs(e[id][i]);
}
int main(){
	cin>>n>>m;
	if(n!=m)no;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u); 
	}
	dfs(1);
	for(int i=1;i<=n;i++)if(!pd[i])no;
	puts("FHTAGN!");
	return 0;
}