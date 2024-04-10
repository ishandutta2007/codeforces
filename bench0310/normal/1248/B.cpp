#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<long long> v(n);
	for(int i=0;i<n;i++) scanf("%I64d",&v[i]);
	sort(v.begin(),v.end());
	int l=0,r=n-1;
	long long one=0,two=0;
	while(l<=r)
    {
        two+=v[r--];
        if(l>r) break;
        one+=v[l++];
    }
    printf("%I64d\n",one*one+two*two);
	return 0;
}