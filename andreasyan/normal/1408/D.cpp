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
const int N = 2003, M = 1000006;

struct ban
{
    int x, y;
};
bool operator<(const ban& a, const ban& b)
{
    return m_p(a.y, a.x) < m_p(b.y, b.x);
}

int n, m;
ban a[N], b[N];

vector<int> v[M];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &b[i].x, &b[i].y);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    multiset<int> s;
    s.insert(0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i].x <= b[j].x && a[i].y <= b[j].y)
            {
                s.insert((b[j].x - a[i].x + 1));
                v[b[j].y - a[i].y + 1].push_back((b[j].x - a[i].x + 1));
            }
        }
    }
    int ans = (0 + *(--s.end()));
    for (int i = 1; i < M; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
            s.erase(s.find(v[i][j]));
        ans = min(ans, i + *(--s.end()));
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}