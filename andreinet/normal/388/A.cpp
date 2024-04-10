#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int N=105;

int a[N][N];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int m=1, i, j, ok, k;
    scanf("%d", &a[1][0]);
    for(i=1;i<=a[1][0];i++) scanf("%d", &a[1][i]);
    sort(a[1]+1, a[1]+a[1][0]+1);
    for(i=1;i<=m;i++)
    {
        ok=0;
        for(j=1, k=0;j<=a[i][0];j++)
        {
            if(a[i][j]<k)
            {
                if(!ok) m++, ok=1;
                a[m][++a[m][0]]=a[i][j];
            }
            else k++;
        }
    }
    printf("%d", m);
}