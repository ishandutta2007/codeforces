#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	priority_queue<int,vector<int>,greater<int>>pq1,pq2;
	long long ans=0;
	for(int i=1;i<=n;++i){
		int p;
		scanf("%d",&p);
		int x1=1e9,x2=1e9;
		if(pq1.size())x1=pq1.top();
		if(pq2.size())x2=pq2.top();
		if(x1>=p)x1=1e9;
		if(x2>=p)x2=1e9;
		if(x1>1e8&&x2>1e8){
			pq1.emplace(p);
			continue;
		}
		if(x1<x2){
			ans+=p-x1;
			pq1.pop();
			pq2.emplace(p);
		}else{
			ans+=p-x2;
			pq2.pop();
			pq2.emplace(p);
			pq1.emplace(x2);
		}
	}
	printf("%lld\n",ans);
	return 0;
}