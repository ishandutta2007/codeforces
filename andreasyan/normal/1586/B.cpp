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

int n, m;
int a[N], b[N], c[N];

bool u[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        u[i] = false;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
        u[b[i]] = true;
    }

    for (int r = 1; r <= n; ++r)
    {
        if (u[r] == false)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (i == r)
                    continue;
                cout << r << ' ' << i << "\n";
            }
            return;
        }
    }
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