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
        vector<long long> a(2,0);
        for(int i=0;i<n;i++)
        {
            int p;
            scanf("%d",&p);
            a[p%2]++;
        }
        int m;
        scanf("%d",&m);
        vector<long long> b(2,0);
        for(int i=0;i<m;i++)
        {
            int q;
            scanf("%d",&q);
            b[q%2]++;
        }
        printf("%I64d\n",a[0]*b[0]+a[1]*b[1]);
    }
	return 0;
}