#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n,i,v[105];
    scanf("%d",&n);

    for(i=0;i<n;i++)
       scanf("%d",&v[i]);

    sort(v,v+n);
    printf("%d ",v[n-1]);
    n--;
    for(i=1;i<n;i++)
        printf("%d ",v[i]);
    printf("%d\n",v[0]);
    return 0;
}