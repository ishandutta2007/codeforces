#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        long long x;
        scanf("%d%I64d",&n,&x);
        vector<long long> v(n);
        for(int i=0;i<n;i++) scanf("%I64d",&v[i]);
        sort(v.begin(),v.end(),greater<long long>());
        long long sum=0;
        int res=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            if(sum>=(x*(i+1))) res=i+1;
        }
        printf("%d\n",res);
    }
    return 0;
}