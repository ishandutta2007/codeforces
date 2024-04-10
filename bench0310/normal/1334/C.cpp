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
        vector<long long> a(n);
        vector<long long> b(n);
        for(int i=0;i<n;i++) scanf("%I64d%I64d",&a[i],&b[i]);
        long long now=a[0];
        for(int i=1;i<n;i++) now+=max(0ll,a[i]-b[i-1]);
        long long res=now;
        for(int i=1;i<n;i++)
        {
            now-=a[i-1];
            now+=max(0ll,a[i-1]-b[(i-2+n)%n]);
            now-=max(0ll,a[i]-b[i-1]);
            now+=a[i];
            res=min(res,now);
        }
        printf("%I64d\n",res);
    }
    return 0;
}