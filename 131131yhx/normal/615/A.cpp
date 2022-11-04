#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 10010

using namespace std;

bool B[M];

int main()
{
    int n, m;
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i++)
    {
        int k;
        scanf("%d", &k);
        for(int j = 1; j <= k; j++)
        {
            int s;
            scanf("%d", &s);
            B[s] = 1;
        }
    }
    bool ans = 1;
    for(int i = 1; i <= n; i++) ans &= B[i];
    if(ans) puts("YES");
    else puts("NO");
}