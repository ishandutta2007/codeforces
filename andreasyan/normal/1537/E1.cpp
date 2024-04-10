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
const int N = 1000005;

int n, k;
char a[N];

char ans[N];

void solv()
{
    cin >> n >> k;
    cin >> a;

    for (int i = 1; i < n; ++i)
    {
        if (a[0] < a[i])
        {
            n = i;
            break;
        }
    }

    for (int i = 0; i < k; ++i)
        ans[i] = a[(i % n)];

    for (int i = 1; i < n; ++i)
    {
        if (a[0] == a[i])
        {
            bool z = false;
            for (int j = 0; j < k; ++j)
            {
                if (ans[j] < a[(j % i)])
                    break;
                else if (ans[j] > a[(j % i)])
                {
                    z = true;
                    break;
                }
            }
            if (z)
            {
                for (int j = 0; j < k; ++j)
                    ans[j] = a[(j % i)];
            }
        }
    }
    ans[k] = 0;

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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}