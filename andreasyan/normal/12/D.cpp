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
const int N = 500005;

struct ban
{
    int x, y, z;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n;
ban a[N];

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
        scanf("%d", &a[i].x);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].y);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].z);
    sort(a + 1, a + n + 1);
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i].y);
    }
    sort(all(v));
    for (int i = 1; i <= n; ++i)
    {
        a[i].y = lower_bound(all(v), a[i].y) - v.begin() + 1;
    }
    int ans = 0;
    for (int i = n; i >= 1; --i)
    {
        if (i < n && a[i].x != a[i + 1].x)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (a[j].x != a[i + 1].x)
                    break;
                ubd(1, n, a[j].y, a[j].z, 1);
            }
        }
        if (a[i].z < qry(1, n, a[i].y + 1, n, 1))
            ++ans;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}