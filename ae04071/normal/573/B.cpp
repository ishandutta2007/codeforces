#include <cstdio>
#include <algorithm>

using namespace std;

int n,arr[100000],ans[100000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	for(int i=0;i<n;i++) ans[i] = arr[i];

	int mx=1;
	for(int i=0;i<n;i++) {
		ans[i] = min(ans[i], i+mx);
		mx = min(mx, arr[i]-i);
	}

	mx=n;
	for(int i=n-1;i>=0;i--)  {
		ans[i] = min(ans[i], mx-i);
		mx = min(mx, i+arr[i]);
	}

	mx=0;
	for(int i=0;i<n;i++) mx = max(mx,ans[i]);
	printf("%d\n",mx);

	return 0;
}