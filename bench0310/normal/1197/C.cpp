#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	long long a[n];
	for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
	vector<long long> v;
	for(int i=0;i<n-1;i++) v.push_back(a[i+1]-a[i]);
	sort(v.begin(),v.end(),greater<long long>());
	long long res=a[n-1]-a[0];
	for(int i=0;i<k-1;i++) res-=v[i];
	printf("%I64d\n",res);
	return 0;
}