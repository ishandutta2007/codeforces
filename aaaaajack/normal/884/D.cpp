#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<long long,vector<long long>,greater<long long> > pq;
	int n,x;
	scanf("%d",&n);
	long long ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		pq.push(x);
	}
	while(pq.size()>1){
		int c=2;
		if(pq.size()&1){
			c=3;
		}
		long long tmp=0;
		while(c--){
			tmp+=pq.top();
			pq.pop();
		}
		ans+=tmp;
		pq.push(tmp);
	}
	printf("%I64d\n",ans);
	return 0;
}