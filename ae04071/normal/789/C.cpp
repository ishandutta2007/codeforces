#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long lli;
int n;
lli arr[100100];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",arr+i);

	std::vector<lli> a;
	for(int i=0;i<n-1;i++) {
		a.push_back(arr[i+1]-arr[i]);
		if(a[a.size()-1]<0) a[a.size()-1]*=-1;
	}

	lli max=a[0],sum=a[0];
	for(int i=2;i<a.size();i+=2) {
		sum+=a[i]-a[i-1];
		max=std::max(max,sum);
		if(sum<a[i]) sum=a[i];
	}

	if(n>2) {
		sum=a[1];
		max=std::max(max,sum);
		for(int i=3;i<a.size();i+=2) {
			sum+=a[i]-a[i-1];
			max=std::max(max,sum);
			if(sum<a[i]) sum=a[i];
		}
	}

	printf("%lld\n",max);
	

	return 0;
}