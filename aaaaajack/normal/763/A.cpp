#include<bits/stdc++.h>
#define N 100100
using namespace std;
int col[N],deg[N];
bool del[N];
vector<int> g[N];
int main(){
	queue<int> q;
	int n,a,b,cnt;
	scanf("%d",&n);
	cnt=n;
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&col[i]);
		if(deg[i]==1) q.push(i);
	}
	while(!q.empty()&&cnt>1){
		cnt--;
		int u=q.front();
		q.pop();
		del[u]=true;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(del[v]) continue;
			if(col[u]!=col[v]) col[v]=-1;
			deg[v]--;
			if(deg[v]==1&&col[v]>=0){
				q.push(v);
			}
		}
	}
	if(cnt==1){
		puts("YES");
		for(int i=1;i<=n;i++){
			if(!del[i]) printf("%d\n",i);
		}
	}
	else puts("NO");
	return 0;
}