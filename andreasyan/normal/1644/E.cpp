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
char a[N];

void solv()
{
    cin >> n;
    cin >> a;
    m = strlen(a);

    int fx = 1;
    int fy = 1;
    for (int i = 0; i < m; ++i)
    {
        if (a[i] == 'R')
            ++fy;
        else
            ++fx;
    }

    int xx = n - fx + 1;
    int yy = n - fy + 1;

    ll ans = 0;
    bool z = false;
    for (int i = 0; i < m; ++i)
    {
        if (!z)
        {
            if (a[i] != a[0])
            {
                z = true;
                ans += xx * 1LL * yy;
            }
            else
            {
                if (i == 0)
                {
                    if (a[i] == 'D')
                        ans += xx;
                    else
                        ans += yy;
                }
                else
                    ++ans;
            }
            continue;
        }

        if (a[i] == 'R')
            ans += xx;
        else
            ans += yy;
    }
    ++ans;

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