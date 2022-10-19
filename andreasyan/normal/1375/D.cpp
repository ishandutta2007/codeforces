#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1020, m = 1003;

int n;
int a[N];

int q[N * 4];
int u[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        q[pos] = 0;
        u[pos] = tl;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    u[pos] = tl;
}

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        q[pos] += y;
        if (q[pos])
            u[pos] = -1;
        else
            u[pos] = tl;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    if (u[pos * 2] == -1)
        u[pos] = u[pos * 2 + 1];
    else
        u[pos] = u[pos * 2];
}

vector<int> ans;
void gor(int j)
{
    ans.push_back(j);
    int g = u[1];
    ubd(0, m, a[j], -1, 1);
    a[j] = g;
    ubd(0, m, a[j], 1, 1);
}

void solv()
{
    ans.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    bil(0, m, 1);
    for (int i = 0; i < n; ++i)
    {
        ubd(0, m, a[i], 1, 1);
    }

    /*for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (a[j] == i)
            {
                gor(j);
            }
        }
        gor(i);
    }*/

    while (1)
    {
        int z = -1;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != i)
            {
                z = i;
                break;
            }
        }
        if (z == -1)
            break;
        if (u[1] != n)
            gor(u[1]);
        else
            gor(z);
    }

    for (int i = 0; i < n - 1; ++i)
        assert(a[i] <= a[i + 1]);

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i] + 1);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}