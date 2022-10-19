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
const int N = 303;

int n, m;
int a[N * N];
int b[N * N];

bool c[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i)
        cin >> a[i];

    for (int i = 1; i <= n * m; ++i)
        b[i] = a[i];
    sort(b + 1, b + n * m + 1);

    {
        memset(c, false, sizeof c);
        int ans = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = m; j >= 1; --j)
            {
                if (b[j] == a[i] && !c[j])
                {
                    c[j] = true;
                    for (int k = j - 1; k >= 1; --k)
                        ans += c[k];
                    break;
                }
            }
        }

        cout << ans << "\n";
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
        solv();
    return 0;
}