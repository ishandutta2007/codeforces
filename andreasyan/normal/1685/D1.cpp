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
const int N = 203;

int n;
int p[N];
int cp[N];

bool c[N];
void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    for (int i = 1; i <= n; ++i)
        cp[i] = p[i];

    while (1)
    {
        for (int i = 1; i <= n; ++i)
            c[i] = false;
        vector<int> v;
        int x = 1;
        while (!c[x])
        {
            c[x] = true;
            v.push_back(x);
            x = p[x];
        }

        if (sz(v) == n)
        {
            for (int i = 0; i < sz(v); ++i)
                p[i + 1] = v[i];
            reverse(p + 1, p + n + 1);
            break;
        }

        sort(all(v));
        for (int i = 0; i < sz(v); ++i)
        {
            if (i == sz(v) - 1 || v[i + 1] != v[i] + 1)
            {
                int u = v[i];
                if (i == sz(v) && v[i] == n)
                    u = v[0] - 1;
                int x, y;
                for (int j = 1; j <= n; ++j)
                {
                    if (p[j] == u)
                        x = j;
                    if (p[j] == u + 1)
                        y = j;
                }
                swap(p[x], p[y]);
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << p[i] << ' ';
    cout << "\n";

    return;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += abs(p[i] - cp[p[i % n + 1]]);
    cout << ans << "\n";
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