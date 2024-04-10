#include <algorithm>
#include <cstdio>

using namespace std;

const int N=200005;

int a[N];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, i;
    long long sol1=0, sol2=0, s=0;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%d", &a[i]);
    for(i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            sol1+=s;
        }
        else ++s;
    }
    s=0;
    for(i=n;i;i--)
    {
        if(a[i]==1)
        {
            sol2+=s;
        }
        else ++s;
    }
    sol1=min(sol1, sol2);
    printf("%I64d", sol1);
}