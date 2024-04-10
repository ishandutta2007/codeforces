#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

int n,m;
lli arr[200001];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",arr+i);
		arr[i]+=arr[i-1];
	}

	lli val;
	int s=0,id=1;
	for(int i=0;i<m;i++) {
		scanf("%lld",&val);
		int lo=0,up=n+1;
		while(up-lo>1) {
			int md=(lo+up)>>1;
			if(arr[md]<val) lo=md;
			else up=md;
		}
		printf("%d %lld\n",lo+1,val-arr[lo]);
	}
	return 0;
}