#include<bits/stdc++.h>
using namespace std;
const int N=200009;
unordered_set<int>v,e[N];
queue<int>q;
int a[N],g;
void bfs(int x){
	int i;
	unordered_set<int>::iterator it,it2;
	q.push(x),v.erase(x);
	while(!q.empty()){
		i=q.front(),q.pop(),++g;
		for(it=v.begin();it!=v.end();it=it2){
			it2=it,++it2;
			if(!e[i].count(*it)){
				q.push(*it),v.erase(it);
			}
		}
	}
}
int main(){
	int n,m,i,j,s=0;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&i,&j);
		e[i].insert(j),e[j].insert(i);
	}
	for(i=1;i<=n;++i)v.insert(i);
	for(i=1;i<=n;++i)if(v.count(i))g=0,bfs(i),++a[g],++s;
	printf("%d\n",s);
	for(i=1;i<=n;++i)while(a[i]--)printf("%d ",i);
	return 0;
}