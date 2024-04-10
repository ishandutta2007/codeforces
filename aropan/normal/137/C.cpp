#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


const int MAXN = 200007;

int n, m;
int l[MAXN], r[MAXN];
int X[MAXN];
bool f[MAXN];
priority_queue < pair <int, int> > H;
int ans;


bool opr_sort(int i, int j)
{
    return (i < 0? r[-i] : l[i]) < (j < 0? r[-j] : l[j]);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &l[i], &r[i]);

    m = 0;
    for (int i = 1; i <= n; i++)
    {
        X[m++] = i;
        X[m++] = -i;
    }

    sort(X, X + m, opr_sort);

    for (int i = 0; i < m; i++)
    {
        while (H.size() && f[H.top().second] == false) H.pop();
        if (X[i] > 0)
        {
            if (H.size() && H.top().first > r[X[i]]) ans++;
            H.push(make_pair(r[X[i]], X[i]));
            f[X[i]] = true;
        }
        else
        {
            f[-X[i]] = false;
        }
    }
    printf("%d\n", ans);
    return 0;
}