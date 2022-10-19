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

int n, m;

void solv()
{
    scanf("%d%d", &n, &m);
    set<pair<int, int> > s;
    set<int> ss;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        s.insert(m_p(y, x));
        ss.insert(y);
    }
    s.insert(m_p(n + 1, 1));
    s.insert(m_p(n + 1, 2));
    ss.insert(n + 1);

    int y = 0;
    int u = 0;
    for (auto it = ss.begin(); it != ss.end(); ++it)
    {
        int yy = *it;
        int uu;
        if (u == 0)
        {
            if (s.find(m_p(yy, 1)) != s.end() && s.find(m_p(yy, 2)) != s.end())
                uu = 0;
            else if (s.find(m_p(yy, 1)) != s.end())
                uu = 1;
            else
                uu = 2;
        }
        else if (u == 1)
        {
            if (s.find(m_p(yy, 1)) != s.end() && s.find(m_p(yy, 2)) != s.end())
            {
                printf("NO\n");
                return;
            }
            else if (s.find(m_p(yy, 1)) != s.end())
            {
                if ((yy - y) % 2 == 1)
                    uu = 0;
                else
                {
                    printf("NO\n");
                    return;
                }
            }
            else
            {
                if ((yy - y) % 2 == 0)
                    uu = 0;
                else
                {
                    printf("NO\n");
                    return;
                }
            }
        }
        else
        {
            if (s.find(m_p(yy, 1)) != s.end() && s.find(m_p(yy, 2)) != s.end())
            {
                printf("NO\n");
                return;
            }
            else if (s.find(m_p(yy, 2)) != s.end())
            {
                if ((yy - y) % 2 == 1)
                    uu = 0;
                else
                {
                    printf("NO\n");
                    return;
                }
            }
            else
            {
                if ((yy - y) % 2 == 0)
                    uu = 0;
                else
                {
                    printf("NO\n");
                    return;
                }
            }
        }
        y = yy;
        u = uu;
    }
    printf("YES\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}