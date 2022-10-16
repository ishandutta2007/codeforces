#include <cstdio>
#include <algorithm>

using namespace std;

int v[110];

int main() 
{
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    int r=v[2]-v[1];
    for(int i=2;i<=n;i++)
        if(v[i]!=v[i-1]+r)
        {
            printf("%d",v[n]);
            return 0;
        }
    printf("%d",v[n]+r);
    return 0;
}