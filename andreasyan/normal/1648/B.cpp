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
const int N = 1000006;

int n, m;
bool c[N];
int p[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        c[i] = false;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        c[x] = true;
    }
    n = m;

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + c[i];

    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
            continue;
        for (int y = x; y <= n; y += x)
        {
            if (p[min(n, y + x - 1)] - p[y - 1] > 0)
            {
                if (!c[y / x])
                {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
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