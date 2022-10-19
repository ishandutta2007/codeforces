#include<bits/stdc++.h>
using namespace std;
int n,m,val[50100],col[50100],num;
vector<int>v[50100],u[501000];
int tot,blk[500100],b,dfn[500100],low[500100];
stack<int>s;
void Tarjan(int x){
	dfn[x]=low[x]=++tot,s.push(x);
	for(auto y:u[x]){
		if(!dfn[y])Tarjan(y),low[x]=min(low[x],low[y]);
		else if(!blk[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]>low[x])return;
	b++;
	while(s.top()!=x)blk[s.top()]=b,s.pop();
	blk[s.top()]=b,s.pop();
}
void ae(int x,int y){u[x].push_back(y);}
bool che(int ip){
	for(int i=1;i<=num;i++)u[i].clear(),dfn[i]=low[i]=blk[i]=0;num=tot=b=0;
	num=2*m;
	for(int i=1;i<=m;i++)if(val[i]>ip)ae(i,m+i);
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			if(j)ae(v[i][j],num);
			ae(++num,v[i][j]+m);
			if(j+1!=v[i].size())ae(num+1,num);
		}
		for(int j=0;j<v[i].size();j++){
			if(j)ae(num,v[i][j]+m);
			ae(v[i][j],++num);
			if(j+1!=v[i].size())ae(num,num+1);
		}
		for(int l=0,r=0;l<v[i].size();l=r){
			while(r<v[i].size()&&col[v[i][l]]==col[v[i][r]])r++;
			for(int j=l;j<r;j++){
				if(j!=l)ae(v[i][j]+m,num);
				ae(++num,v[i][j]);
				if(j+1!=r)ae(num+1,num);
			}
			for(int j=l;j<r;j++){
				if(j!=l)ae(num,v[i][j]);
				ae(v[i][j]+m,++num);
				if(j+1!=r)ae(num,num+1);
			}
		}
	}
	for(int i=1;i<=num;i++)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=m;i++)if(blk[i]==blk[m+i])return false;
	return true;
}
vector<int>res;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d%d%d",&x,&y,&col[i],&val[i]);
		v[x].push_back(i),v[y].push_back(i);
	}
	for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end(),[](int x,int y){return col[x]<col[y];});
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(che(mid))r=mid;
		else l=mid+1;
	}
	if(!che(r))return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=m;i++)if(blk[i]<blk[m+i])res.push_back(i);
	printf("%d %d\n",r,res.size());
	for(auto i:res)printf("%d ",i);puts("");
	return 0;
}
/*
2 4
1 2 2 2
1 2 2 3
1 2 7 1
1 2 6 2
*/