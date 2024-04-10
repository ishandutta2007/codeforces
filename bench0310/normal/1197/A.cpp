#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v(n);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        sort(v.begin(),v.end());
        printf("%d\n",min(v[n-2]-1,n-2));
    }
	return 0;
}