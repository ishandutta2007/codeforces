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
const int N = 100005;

int n;
int a[N];
vector<int> v[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = max(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        v[a[i]].push_back(i);
    }
    for (int x = 1; x <= n + 3; ++x)
    {
        bool z = false;
        if (v[x].empty())
        {
            if (qry(1, n, 1, 1, 1) < n)
                z = true;
        }
        else
        {
            if (v[x][0])
            {
                if (qry(1, n, 1, 1, 1) < v[x][0] - 1)
                    z = true;
            }
            if (v[x].back() < n)
            {
                if (qry(1, n, 1, v[x].back() + 1, 1) < n)
                    z = true;
            }
        }
        for (int i = 0; i < sz(v[x]) - 1; ++i)
        {
            if (v[x][i] + 1 <= v[x][i + 1] - 1)
            {
                if (qry(1, n, 1, v[x][i] + 1, 1) < v[x][i + 1] - 1)
                {
                    z = true;
                    break;
                }
            }
        }
        if (!z)
        {
            printf("%d\n", x);
            return;
        }

        if (v[x].empty())
            ubd(1, n, 1, n, 1);
        else
        {
            if (v[x][0])
                ubd(1, n, 1, v[x][0] - 1, 1);
            if (v[x].back() < n)
                ubd(1, n, v[x].back() + 1, n, 1);
        }
        for (int i = 0; i < sz(v[x]) - 1; ++i)
        {
            if (v[x][i] + 1 <= v[x][i + 1] - 1)
            {
                ubd(1, n, v[x][i] + 1, v[x][i + 1] - 1, 1);
            }
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}