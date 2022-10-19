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
const int m = 20;

int n;
int a[N];

struct ban
{
    int u[m];
    ban()
    {
        memset(u, 0, sizeof u);
    }
    bool ave(int x)
    {
        for (int i = m - 1; i >= 0; --i)
        {
            if ((x & (1 << i)))
            {
                if (!u[i])
                {
                    u[i] = x;
                    return true;
                }
                x ^= u[i];
            }
        }
        return false;
    }
};

ban t[N];

vector<pair<int, int> > v[N];

int yans[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int qq;
    scanf("%d", &qq);
    for (int i = 0; i < qq; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        v[r].push_back(m_p(l, i));
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j >= 1; --j)
        {
            if (!t[j].ave(a[i]))
                break;
        }
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j].fi;
            int ans = 0;
            for (int i = m - 1; i >= 0; --i)
            {
                if (!(ans & (1 << i)))
                    ans ^= t[x].u[i];
            }
            yans[v[i][j].se] = ans;
        }
    }

    for (int i = 0; i < qq; ++i)
        printf("%d\n", yans[i]);
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