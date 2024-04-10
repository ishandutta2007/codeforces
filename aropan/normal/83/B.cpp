#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 111111;

int n;
long long k;
long long a[MAXN];
int d[MAXN];
bool f[MAXN];
queue < pair <long long, int> > q;

bool opr_sort(const int &i, const int &j)
{
    return a[i] < a[j] || a[i] == a[j] && i < j;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        d[i] = i;

    sort(d + 1, d + n + 1, opr_sort);

    long long x = 0;
    int l = n;
    for (int i = 1; i <= n; i++)
    {
        if ((a[d[i]] - x) * (n - i + 1) > k) break;
        k -= (a[d[i]] - x) * (n - i + 1);
        f[d[i]] = true;
        x = a[d[i]];
        l = n - i;
    }

    if (l == 0)
    {
        if (k) printf("-1");
        printf("\n");
        return 0;
    }

    x += k / l;
    k %= l;

    for (int i = 1; i <= n; i++)
        if (x < a[i])
            q.push(make_pair(a[i] - x, i));

    while (k--)
    {
        if (q.size() == 0)
        {
            printf("-1");
            return 0;
        }
        if (q.front().first - 1 > 0)
            q.push(make_pair(q.front().first, q.front().second));

        q.pop();
    }

    while (q.size())
    {
        printf("%d", q.front().second);
        q.pop();
        if (q.size()) printf(" ");
    }
    printf("\n");
    return 0;
}