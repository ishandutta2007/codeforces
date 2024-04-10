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

int k;
int a[7];

void solv()
{
    cin >> k;
    for (int i = 0; i < 7; ++i)
        cin >> a[i];

    int ans = k * 7;
    for (int s = 0; s < 7; ++s)
    {
        for (int f = 0; f < 7; ++f)
        {
            int q = 0;
            for (int i = s; i <= f; ++i)
            {
                q += a[i];
            }
            if (q >= k)
            {
                ans = min(ans, f - s + 1);
                continue;
            }

            q = 0;
            for (int i = s; i < 7; ++i)
                q += a[i];
            for (int i = 0; i <= f; ++i)
                q += a[i];

            if (q >= k)
            {
                ans = min(ans, 7 - s + f + 1);
                continue;
            }

            int yq = 0;
            for (int i = 0; i < 7; ++i)
                yq += a[i];

            ans = min(ans, 7 - s + f + 1 + ((k - q) / yq + !!((k - q) % yq)) * 7);
        }
    }

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