/*
Solution:
simply solved by updating brute algorithm.
first, we can maintain connnectivity of each colour by dsu.
for each pair(x,y),
we can numerate all the colours which are connected to node x,
and check if node x and y are in the same connected block of the numerated colour.
some simply updating ideas:
1.it's clear that the final complexity is based on the numerated number of colours.
and if we always numerate the smaller-coloured node, the comlextity can be declined.
2.if pair(x,y) has been numerated before, we can just store the previous answer and output in directly.
BY THIS, YOU CAN PASS IT!!!
why?
Compexity analysing:
for the nodes which connected more than sqrt(n) colours, there are at most sqrt(n) such ones, and solving it can be m*sqrt(n)
otherwise, solving the rest of it can be q*sqrt(n)
and the final complexity is O((m+q)*sqrt(n))
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
unordered_map<int,int>fa[100100],res[100100];
int find(int x,int col){
	return fa[x][col]==x?x:fa[x][col]=find(fa[x][col],col);
}
void merge(int x,int y,int col){
	if(fa[x].find(col)==fa[x].end())fa[x][col]=x;
	if(fa[y].find(col)==fa[y].end())fa[y][col]=y;
	x=find(x,col),y=find(y,col);
	if(x!=y)fa[x][col]=y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),merge(x,y,z);
	scanf("%d",&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(fa[x].size()>fa[y].size())swap(x,y);
		if(res[x].find(y)!=res[x].end()){printf("%d\n",res[x][y]);continue;}
		int ans=0;
		for(unordered_map<int,int>::iterator it=fa[x].begin();it!=fa[x].end();it++)if(fa[y].find(it->first)!=fa[y].end())ans+=(find(x,it->first)==find(y,it->first));
		printf("%d\n",res[x][y]=ans);
	}
	return 0;
}