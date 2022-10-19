#include<bits/stdc++.h>
using namespace std;
int n,X[100100],Y[100100];
vector<int>v[200100];
int col[200100];
void dfs(int x){for(auto y:v[x])if(col[y]==-1)col[y]=col[x]^1,dfs(y);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&X[i],&Y[i]),v[X[i]].push_back(Y[i]),v[Y[i]].push_back(X[i]),v[(i<<1)-1].push_back(i<<1),v[i<<1].push_back((i<<1)-1);
	memset(col,-1,sizeof(col));
	for(int i=1;i<=(n<<1);i++)if(col[i]==-1)col[i]=0,dfs(i);
	for(int i=1;i<=n;i++)printf("%d %d\n",col[X[i]]+1,col[Y[i]]+1);
	return 0;
}