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
const int N = 200005;

int n, k;
vector<int> a[N];

int q[N], qq[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int x = 1; x <= n; ++x)
        a[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    if (n == 2)
    {
        printf("1\n");
        return;
    }

    set<pair<int, int> > s;
    for (int x = 1; x <= n; ++x)
    {
        q[x] = sz(a[x]);
        if (q[x] == 1)
            continue;
        qq[x] = 0;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (sz(a[h]) == 1)
                ++qq[x];
        }
        s.insert(m_p(qq[x], x));
    }

    int ans = 0;
    while (!s.empty())
    {
        int x = (--s.end())->se;
        s.erase(--s.end());
        if (qq[x] < k)
        {
            break;
        }
        ans += (qq[x] / k);
        q[x] -= (qq[x] / k) * k;
        qq[x] %= k;
        if (q[x] == 1)
        {
            for (int i = 0; i < a[x].size(); ++i)
            {
                int h = a[x][i];
                if (s.find(m_p(qq[h], h)) != s.end())
                {
                    s.erase(m_p(qq[h], h));
                    ++qq[h];
                    s.insert(m_p(qq[h], h));
                }
            }
        }
        else
            s.insert(m_p(qq[x], x));
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}