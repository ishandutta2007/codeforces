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
int c[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    int q1 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == 1)
            ++q1;
    }

    if (q1 != 1)
    {
        cout << "NO\n";
        return;
    }

    for (int s = 1; s <= n; ++s)
    {
        if (c[s] == 1)
        {
            int u = 1;
            int nx = 1;
            for (int i = s + 1; i <= n; ++i)
            {
                ++u;
                if (c[i] > u)
                {
                    cout << "NO\n";
                    return;
                }
                if (c[i] - nx > 1)
                {
                    cout << "NO\n";
                    return;
                }
                nx = c[i];
            }
            for (int i = 1; i < s; ++i)
            {
                ++u;
                if (c[i] > u)
                {
                    cout << "NO\n";
                    return;
                }
                if (c[i] - nx > 1)
                {
                    cout << "NO\n";
                    return;
                }
                nx = c[i];
            }
            cout << "YES\n";
            return;
        }
    }
    assert(false);
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