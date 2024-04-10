#include<bits/stdc++.h>
using namespace std;
int n,m,dsu[1010],sz[1010],cnt;
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
multiset<int>s;
bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return false;
	if(sz[x]>sz[y])swap(x,y);
	s.erase(s.find(sz[x])),s.erase(s.find(sz[y]));
	dsu[x]=y,sz[y]+=sz[x];
	s.insert(sz[y]);
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)dsu[i]=i,sz[i]=1,s.insert(1);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y),cnt+=merge(x,y);
		int res=0;auto it=s.rbegin();
		for(int j=cnt;j<=i;j++,it++)res+=*it;
		printf("%d\n",res-1);
	}
	return 0;
}