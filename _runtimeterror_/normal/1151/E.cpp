#include <iostream>
using namespace std;

int a[100005];


int main() 
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
    }

    long long ans = 0;
    for(int i=0;i<n;++i)
    {
        int l=a[i],r=a[i+1];
        if(l>r)
            ans += 1LL*(l-r)*r;
        else
            ans += 1LL*(r-l)*(n-r+1);
    }
    printf("%lld",ans);
}