#include<bits/stdc++.h>
#define N 100100
using namespace std;
long long sum[N];
int a[N];
int main(){
	int n,x;
	priority_queue<pair<long long,pair<int,int> > > pq;
	set<int> del;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	del.insert(0);
	del.insert(n+1);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		int l=*--del.lower_bound(x),r=*del.upper_bound(x);
		pq.push(make_pair(sum[x-1]-sum[l],make_pair(l,x)));
		pq.push(make_pair(sum[r-1]-sum[x],make_pair(x,r)));
		del.insert(x);
		while(!pq.empty()){
			long long val=pq.top().first;
			int sl=pq.top().second.first,sr=pq.top().second.second;
			if(*del.upper_bound(sl)!=sr){
				pq.pop();
				continue;
			}
			printf("%I64d\n",val);
			break;
		}
		if(pq.empty()) printf("%d\n",0);
	}
	return 0;
}