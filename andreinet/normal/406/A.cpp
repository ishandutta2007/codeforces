#include <cstdio>

using namespace std;

const int N=1005;

int a[N][N];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, m, i, j, s=0;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            s=(s+a[i][j]*a[j][i])%2;
        }
    }
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &i);
        if(i==3) printf("%d", s);
        else
        {
            scanf("%d", &j);
            s^=1;
        }
    }
}