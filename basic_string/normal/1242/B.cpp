#include<bits/stdc++.h>
using namespace std;
const int N=100009;
unordered_set<int>v,e[N];
queue<int>q;
void bfs(int x){
	int i;
	unordered_set<int>::iterator it,it2;
	q.push(x),v.erase(x);
	while(!q.empty()){
		i=q.front(),q.pop();
		for(it=v.begin();it!=v.end();it=it2){
			it2=it,++it2;
			if(!e[i].count(*it)){
				q.push(*it),v.erase(it);
			}
		}
	}
}
int main(){
	int n,m,i,j,s=-1;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&i,&j);
		e[i].insert(j),e[j].insert(i);
	}
	for(i=1;i<=n;++i)v.insert(i);
	for(i=1;i<=n;++i)if(v.count(i))bfs(i),++s;
	printf("%d",s);
	return 0;
}