#include<iostream> 
#include<algorithm>
using namespace std;


const int N = 300005;
long long a[N];
int n,k;

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%lld",a+i);

    for(int i=1;i<=n;++i)
        a[i] += a[i-1];

    long long ans = 0;
    ans += a[n]*1LL*k;

    sort(a+1,a+n);
    for(int i=1;i<=k-1;++i)
    {
        ans -= a[i];
    }
    printf("%lld\n", ans);
}