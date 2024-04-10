#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<long long> a(n);
    vector<long long> sum(n,0);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        sum[i]+=a[i];
        if(i<n-1) sum[i+1]=sum[i];
    }
    long long t=sum[n-1];
    vector<long long> v;
    for(long long i=2;i*i<=t;i++)
    {
        if((t%i)==0) v.push_back(i);
        while((t%i)==0) t/=i;
    }
    if(t>1) v.push_back(t);
    long long res=sum[n-1]*n;
    for(long long p:v)
    {
        long long cnt=0;
        for(int i=0;i<n-1;i++) cnt+=min(sum[i]%p,p-sum[i]%p);
        res=min(res,cnt);
    }
    if(res!=sum[n-1]*n) printf("%I64d\n",res);
    else printf("-1\n");
    return 0;
}