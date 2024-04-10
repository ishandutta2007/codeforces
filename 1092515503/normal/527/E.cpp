#include<bits/stdc++.h>
using namespace std;
int n,m,head[100100],deg[100100],cnt;
bool cho[1001000];
struct node{int to,next;}edge[1001000];
list<int>ls;
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
void Eular(int x,list<int>::iterator it){
	for(;head[x]!=-1;head[x]=edge[head[x]].next){
		if(cho[head[x]])continue;
		cho[head[x]]=cho[head[x]^1]=true;
		Eular(edge[head[x]].to,ls.insert(it,edge[head[x]].to));
		if(head[x]==-1)break;
	}
}
vector<int>v;
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),ae(x,y),deg[x]++,deg[y]++;
	for(int i=1,mat=-1;i<=n;i++){
		if(!(deg[i]&1))continue;
		if(mat==-1)mat=i;else ae(mat,i),m++,mat=-1;
	}
	if(m&1)ae(1,1),m++;
	Eular(1,ls.begin());
	v.push_back(ls.back());
	for(auto x:ls)v.push_back(x);
	printf("%d\n",m);
	for(int i=1;i<v.size();i+=2){
		printf("%d %d\n",v[i-1],v[i]);
		printf("%d %d\n",v[i+1],v[i]);
	}
	return 0;
}