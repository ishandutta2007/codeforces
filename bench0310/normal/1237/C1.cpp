#include <bits/stdc++.h>

using namespace std;

long long sq(long long a)
{
    return a*a;
}

int main()
{
	int n;
	scanf("%d",&n);
	long long x[n],y[n],z[n];
	for(int i=0;i<n;i++) scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
	vector<bool> used(n,0);
	for(int o=0;o<n;o++)
    {
        if(used[o]) continue;
        long long m=1000000000000000000;
        int id=o+1;
        for(int i=o+1;i<n;i++)
        {
            if(used[i]) continue;
            long long d=(sq(x[o]-x[i])+sq(y[o]-y[i])+sq(z[o]-z[i]));
            if(d<m)
            {
                m=d;
                id=i;
            }
        }
        printf("%d %d\n",o+1,id+1);
        used[o]=used[id]=1;
    }
	return 0;
}