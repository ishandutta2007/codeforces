#include<bits/stdc++.h>
using namespace std;
int n,m,q,col[102][102][102],pd[102];
void dfs(int id,int c){
	pd[id]=1;
	for(int i=1;i<=n;i++)
		if(!pd[i]&&col[id][i][c])
			dfs(i,c);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		col[a][b][c]=col[b][a][c]=1;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int u,v,cnt=0;
		cin>>u>>v;
		for(int j=1;j<=m;j++){
			memset(pd,0,sizeof(pd));
			dfs(u,j);
			cnt+=pd[v];
		}
		cout<<cnt<<endl;
	}
    return 0;
}