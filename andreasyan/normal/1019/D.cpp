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
const int N = 2003;

struct ban
{
    int x, y;
    ban()
    {
        x = y = 0;
    }
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x, a.y - b.y);
}
ll cp(const ban& a, const ban& b)
{
    return a.x * 1LL * b.y - b.x * 1LL * a.y;
}

struct bant
{
    ban t;
    int i, j;
};
bool socp(const bant& a, const bant& b)
{
    return (cp(a.t, b.t) > 0);
}
bool so(const bant& a, const bant& b)
{
    return m_p(a.t.x, a.t.y) < m_p(b.t.x, b.t.y);
}

int n;
ll S;
bant a[N];
int u[N];

int m;
bant b[N * N];

void solv()
{
    cin >> n >> S;
    S *= 2;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].t.x >> a[i].t.y;
        a[i].i = i;
    }

    sort(a + 1, a + n + 1, so);
    for (int i = 1; i <= n; ++i)
        u[a[i].i] = i;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            ++m;
            b[m].i = a[i].i;
            b[m].j = a[j].i;
            b[m].t = a[j].t - a[i].t;
        }
    }
    sort(b + 1, b + m + 1, socp);

    for (int i = 1; i <= m; ++i)
    {
        int l = u[b[i].i] + 1;
        int r = n;
        while (l <= r)
        {
            int m = (l + r) / 2;
            ll s = abs(cp(b[i].t, a[m].t - a[u[b[i].i]].t));
            if (s == S)
            {
                cout << "Yes\n";
                cout << a[u[b[i].i]].t.x << ' ' << a[u[b[i].i]].t.y << "\n";
                cout << a[u[b[i].j]].t.x << ' ' << a[u[b[i].j]].t.y << "\n";
                cout << a[m].t.x << ' ' << a[m].t.y << "\n";
                return;
            }
            if (s < S)
                l = m + 1;
            else
                r = m - 1;
        }
        assert(abs(u[b[i].i] - u[b[i].j]) == 1);
        swap(a[u[b[i].i]], a[u[b[i].j]]);
        swap(u[b[i].i], u[b[i].j]);
    }
    cout << "No\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}