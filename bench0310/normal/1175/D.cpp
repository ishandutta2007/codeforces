#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	long long a[n];
	for(int i=n-1;i>=0;i--) scanf("%I64d",&a[i]);
	vector<long long> v(n);
	v[0]=a[0];
	for(int i=1;i<n;i++) v[i]=v[i-1]+a[i];
	long long res=v[n-1];
	v.pop_back();
	sort(v.begin(),v.end(),greater<long long>());
	for(int i=0;i<k-1;i++) res+=v[i];
	printf("%I64d\n",res);
	return 0;
}