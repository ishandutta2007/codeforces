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
const int N = 300005, m = 30;

int n;
int a[N];

int z;
int t[N * m][2];
int maxu[N * m][2][2];

void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    z = 0;
    t[z][0] = t[z][1] = 0;
    maxu[z][0][0] = maxu[z][0][1] = maxu[z][1][0] = maxu[z][1][1] = -N;
    int yans = 0;
    for (int i = 0; i < n; ++i)
    {
        int ans = 1;
        int pos = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            int u1 = 0;
            if ((a[i] & (1 << j)))
                u1 = 1;
            int u2 = 0;
            if ((i & (1 << j)))
                u2 = 1;
            int u = (u1 ^ u2);
            if (t[pos][(u ^ 1)])
            {
                for (int k1 = 0; k1 < 2; ++k1)
                {
                    for (int k2 = 0; k2 < 2; ++k2)
                    {
                        if ((k1 ^ u2) < (u1 ^ k2))
                            ans = max(ans, maxu[t[pos][(u ^ 1)]][k1][k2] + 1);
                    }
                }
            }
            if (!t[pos][u])
                break;
            pos = t[pos][u];
        }

        pos = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            int u1 = 0;
            if ((a[i] & (1 << j)))
                u1 = 1;
            int u2 = 0;
            if ((i & (1 << j)))
                u2 = 1;
            int u = (u1 ^ u2);
            if (!t[pos][u])
            {
                t[pos][u] = ++z;
                t[z][0] = t[z][1] = 0;
                maxu[z][0][0] = maxu[z][0][1] = maxu[z][1][0] = maxu[z][1][1] = -N;
            }
            pos = t[pos][u];
            maxu[pos][u1][u2] = max(maxu[pos][u1][u2], ans);
        }
        yans = max(yans, ans);
    }

    cout << yans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}