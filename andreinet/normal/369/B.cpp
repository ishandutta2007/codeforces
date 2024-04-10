#include <cstdio>

using namespace std;

int a[1001];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, k, l, r, sall, sk, i;
    scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sall, &sk);
    sall-=sk;
    for(i=1;i<=k;i++)
    {
        a[i]=sk/k;
    }
    sk%=k;
    for(i=1;i<=sk;i++) a[i]++;
    if(k<n)
    {
        for(i=k+1;i<=n;i++)
        {
            a[i]=sall/(n-k);
        }
        sall%=(n-k);
        for(i=k+1;sall;i++, sall--) a[i]++;
    }
    for(i=1;i<=n;i++) printf("%d ", a[i]);
}