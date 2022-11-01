#include <algorithm>
#include <cstdio>

using namespace std;

int a[500004];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, i, j, sol;
    scanf("%d", &n);
    sol=n;
    for(i=1;i<=n;i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    j=1;
    for(i=(n+1)/2+1;i<=n;i++)
    {
        if(a[i]>=a[j]*2)
        {
            sol--;
            j++;
        }
    }
    printf("%d", sol);
}