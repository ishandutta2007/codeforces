#include<cstdio>
using namespace std;


const int MAXN = 1111;

int next[MAXN];
int x[MAXN], y[MAXN], d[MAXN];
int n, m;

int find(int x)
{
    if (x != next[x]) next[x] = find(next[x]);
    return next[x];
}

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        next[i] = i;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (find(a) == find(b))
        {
            x[m] = a;
            y[m] = b;
            m++;
        }

        next[next[a]] = next[b];
    }
    m = 0;
    for (int i = 1; i <= n; i++)
        if (next[i] == i)
            d[m++] = i;

    printf("%d\n", m - 1);
    for (int i = 0; i < m - 1; i++)
        printf("%d %d %d %d\n", x[i], y[i], d[i], d[i + 1]);
    
    return 0;
}