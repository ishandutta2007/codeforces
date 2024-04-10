#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,num[10],tot,res[2001000];
vector<int>v[2001000][10];
queue<vector<int> >q;
int main(){
	scanf("%d%d",&n,&m),tot=n,memset(res,-1,sizeof(res));
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		int tmp=i,sz=0;
		while(tmp)num[++sz]=tmp%10,tmp/=10;
		if(sz==1)v[x][num[sz]].push_back(y);
		else v[x][num[sz]].push_back(tot+1),v[tot+sz-1][num[1]].push_back(y);
		for(int j=2;j<sz;j++)v[tot+j-1][num[sz-j+1]].push_back(tot+j);
		
		if(sz==1)v[y][num[sz]].push_back(x);
		else v[y][num[sz]].push_back(tot+sz-1),v[tot+1][num[1]].push_back(x);
		for(int j=2;j<sz;j++)v[tot+sz-j+1][num[sz-j+1]].push_back(tot+sz-j);
		
		tot+=sz;
	}
	q.push({1}),res[1]=0;
	while(!q.empty()){
		vector<int>x=q.front();q.pop();
//		for(int i=0;i<x.size();i++)printf("%d ",x[i]);puts("");
		for(int i=0;i<10;i++){
			vector<int>y;
			for(int j=0;j<x.size();j++)for(int k=0;k<v[x[j]][i].size();k++)if(res[v[x[j]][i][k]]==-1)res[v[x[j]][i][k]]=(10ll*res[x[j]]+i)%mod,y.push_back(v[x[j]][i][k]);
			if(!y.empty())q.push(y);
		}
	}
	for(int i=2;i<=n;i++)printf("%d\n",res[i]);
	return 0;
}