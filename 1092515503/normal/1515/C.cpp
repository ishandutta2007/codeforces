#include<bits/stdc++.h>
using namespace std;
int T,n,m,p;
priority_queue<pair<int,int> >q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&p);
		while(!q.empty())q.pop();
		for(int i=1;i<=m;i++)q.emplace(0,i);
		puts("YES");
		for(int i=1,x;i<=n;i++){
			scanf("%d",&x);
			auto y=q.top();q.pop();
			printf("%d ",y.second);
			y.first-=x;
			q.push(y);
		}puts("");
	}
	return 0;
}