#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        long long s;
        scanf("%d%I64d",&n,&s);
        vector<long long> a(n);
        for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
        int m=0;
        long long sum=0;
        int res=0;
        int idx=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(a[i]>a[m]) m=i;
            if(sum-a[m]<=s&&res<i) tie(res,idx)=make_pair(i,m+1);
            if(sum<=s&&res<i+1) tie(res,idx)=make_pair(i+1,0);
        }
        printf("%d\n",idx);
    }
    return 0;
}