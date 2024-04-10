#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int n,arr[200000],s;

int main() {
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;i++) scanf("%d",arr+i);

	sort(arr,arr+n);
	
	long long sum=max(arr[n/2]-s, s-arr[n/2]);
	for(int i=0;i<n/2;i++) if(arr[i]>s) sum += arr[i]-s;
	for(int i=n/2+1;i<n;i++) if(arr[i]<s) sum += s-arr[i];
	printf("%lld\n",sum);

	return 0;
}