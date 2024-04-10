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

int n, c, q;
char a[N];
ll l[N], r[N];

void solv()
{
    cin >> n >> c >> q;
    cin >> (a + 1);

    for (int i = 1; i <= c; ++i)
        cin >> l[i] >> r[i];

    while (q--)
    {
        ll k;
        cin >> k;

        while (1)
        {
            if (k <= n)
            {
                cout << a[k] << "\n";
                break;
            }
            ll u = n;
            for (int i = 1; i <= c; ++i)
            {
                if (k <= u + r[i] - l[i] + 1)
                {
                    k = l[i] + k - u - 1;
                    break;
                }
                else
                    u += (r[i] - l[i] + 1);
            }
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