#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	bool even=0,odd=0;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        if(!(v[i]&1)) even=1;
        else odd=1;
    }
    if(odd&&even) sort(v.begin(),v.end());
    for(int i=0;i<n;i++) printf("%d ",v[i]);
    printf("\n");
	return 0;
}