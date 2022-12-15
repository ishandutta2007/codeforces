#include <bits/stdc++.h>
using namespace std;

int n,k,arr[200000];
int main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",arr+i);

	vector<int> ia;
	printf("%lld ", 1ll*k*(2*(n-k+1)+(k-1)) / 2);

	for(int i=0;i<n;i++) if(arr[i] > n-k) ia.push_back(i);
	
	long long ans = 1;
	for(int i=1;i<(int)ia.size();i++) ans = ans * (ia[i]-ia[i-1]) % 998244353;
	printf("%lld\n",ans);
	
	return 0;
}