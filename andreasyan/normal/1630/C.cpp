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

int l[N], r[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        if (!l[a[i]])
            l[a[i]] = i;
        r[a[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (l[a[i]] < i && i < r[a[i]])
        {
            ++ans;
            a[i] = 0;
        }
    }

    /*cout << ans << endl;
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << endl;*/

    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!a[i])
            continue;
        maxu = max(maxu, r[a[i]]);
        if (l[a[i]] == r[a[i]])
        {
            a[i] = 0;
            if (i < maxu)
                ++ans;
        }
    }

    /*cout << ans << endl;
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << endl;*/

    maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!a[i])
            continue;
        maxu = max(maxu, r[a[i]]);
        if (i == l[a[i]])
        {
            if (r[a[i]] < maxu)
            {
                ans += 2;
                a[i] = a[r[a[i]]] = 0;
            }
        }
    }

    /*cout << ans << endl;
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << endl;*/

    for (int i = 1; i <= n; ++i)
    {
        if (!a[i])
            continue;

        if (i == l[a[i]])
        {
            int v = 0;
            for (int j = i + 1; j <= r[a[i]] - 1; ++j)
            {
                if (a[j] && j == l[a[j]])
                    v = a[j];
            }

            for (int j = i + 1; j <= r[a[i]] - 1; ++j)
            {
                if (a[j] && j == l[a[j]] && a[j] != v)
                {
                    ans += 2;
                    a[j] = a[r[a[j]]] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!a[i])
            continue;

        int q = 0;
        int j = i;
        while (1)
        {
            ++q;

            int v = 0;
            for (int k = j + 1; k <= r[a[j]] - 1; ++k)
            {
                if (a[k])
                    v = a[k];
            }
            a[j] = a[r[a[j]]] = 0;

            if (!v)
                break;

            j = l[v];
        }

        if (q % 2 == 1)
            ans += (q / 2) * 2;
        else
            ans += ((q - 1) / 2) * 2 + 1;
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}