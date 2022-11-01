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
        vector<long long> v(n);
        for(int i=0;i<n;i++) scanf("%I64d",&v[i]);
        sort(v.begin(),v.end());
        long long m=v[0]*v[n-1];
        vector<long long> d;
        for(long long i=2;i*i<=m;i++)
        {
            if((m%i)==0)
            {
                d.push_back(i);
                if(i*i!=m) d.push_back(m/i);
            }
        }
        sort(d.begin(),d.end());
        if(v==d) printf("%I64d\n",m);
        else printf("-1\n");
    }
	return 0;
}