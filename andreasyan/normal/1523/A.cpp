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
const int N = 1003;

int n, m;
char a[N];

int ul[N], ur[N];

void solv()
{
    cin >> n >> m;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '0')
            ul[i] = ul[i - 1];
        else
            ul[i] = i;
    }

    ur[n + 1] = n + 1;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == '0')
            ur[i] = ur[i + 1];
        else
            ur[i] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        int d = m + 1;
        if (ul[i] != 0)
            d = min(d, i - ul[i]);
        if (ur[i] != n + 1)
            d = min(d, ur[i] - i);

        if (ul[i] != 0 && ur[i] != n + 1 && a[i] != '1')
        {
            if ((ur[i] - ul[i] + 1) % 2 == 1)
            {
                if ((ul[i] + ur[i]) / 2 == i)
                {
                    d = m + 1;
                }
            }
        }

        if (d <= m)
            cout << '1';
        else
            cout << '0';
    }

    cout << "\n";
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