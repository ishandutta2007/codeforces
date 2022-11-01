#include <algorithm>
#include <cstdio>

using namespace std;

const int N=103;

int a[N][N];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, k, i, j, sol=0, nr[3];
    scanf("%d%d", &n, &k);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i%k][i/k]);
    }
    for(i=0;i<k;i++)
    {
        nr[1]=nr[2]=0;
        for(j=0;j<n/k;j++) nr[a[i][j]]++;
        sol+=min(nr[1], nr[2]);
    }
    printf("%d", sol);
}