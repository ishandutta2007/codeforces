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

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ll s = 0;
    for (int i = 1; i <= n; ++i)
    {
        s += a[i];
        if (s < 0)
        {
            cout << "No\n";
            return;
        }
        else if (s == 0)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (a[j])
                {
                    cout << "No\n";
                    return;
                }
            }
            break;
        }
    }

    if (s == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
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