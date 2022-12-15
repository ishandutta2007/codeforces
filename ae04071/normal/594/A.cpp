#include <bits/stdc++.h>
using namespace std;

int n,a[200000];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	
	int mx=1000000001;
	for(int i=0;i+n/2<n;i++) {
		mx = min(mx, a[i+n/2] - a[i]);
	}
	printf("%d\n",mx);
	
	return 0;
}