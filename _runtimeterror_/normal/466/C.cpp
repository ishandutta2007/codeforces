#include<iostream>
using namespace std;

const int N = 5e5+5;
long long a[N],sum[N];
long long cnt[4];

int main()
{
    int n;
    long long ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
        sum[i] = sum[i-1] + a[i];
    }
    long long u = sum[n];
    if(sum[n]==0)
    {
        for(int i=1;i<n;++i)
            ans += sum[i] == 0;
        ans = (ans*(ans-1))/2;
    }
    else if(u%3==0)
    {
        u /= 3;
        for(int i=n;i>=1;--i)
        {
            if(sum[i]==2*u)
                ++cnt[2];
            else if(sum[i]==u)
                ans += cnt[2];
        }
    }
    printf("%lld\n",ans);
}