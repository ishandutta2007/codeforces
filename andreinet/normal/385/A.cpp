#include <cstdio>

using namespace std;

int a[101];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, i, c, sol=-0x3f3f3f3f;
    scanf("%d%d", &n, &c);
    for(i=1;i<=n;i++) scanf("%d", &a[i]);
    for(i=1;i<n;i++)
    {
        if(a[i]-a[i+1]>sol) sol=a[i]-a[i+1];
    }
    if(sol-c>0) printf("%d", sol-c);
    else printf("0");
}