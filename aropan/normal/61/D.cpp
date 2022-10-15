#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100007;
const int MAXM = MAXN << 1;

int last[MAXN];
int next[MAXM], dest[MAXM], dist[MAXM];
long long ans = 0;
int n;

long long rec(int curr, int prev)
{
    int i = last[curr];
    long long res = 0;

    while (i)
    {
        if (dest[i] != prev)
            res = max(res, rec(dest[i], curr) + dist[i]);
        i = next[i];
    }
    return res;
}

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);


        dest[i] = y;
        dist[i] = z;
        next[i] = last[x];
        last[x] = i;


        dest[i + n] = x;
        dist[i + n] = z;
        next[i + n] = last[y];
        last[y] = i + n;

        ans += z << 1;
    }

    printf("%I64d\n", ans - rec(1, 0));
    return 0;
}