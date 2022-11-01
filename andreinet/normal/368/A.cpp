#include <cstdio>
#include <algorithm>
using namespace std;

const int N=101;

int a[N];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, i, d, m;
    scanf("%d%d", &n, &d);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    for(i=1;i<=n;i++) a[i]+=a[i-1];
    scanf("%d", &m);
    if(m>n) printf("%d", a[n]-d*(m-n));
    else printf("%d", a[m]);
}