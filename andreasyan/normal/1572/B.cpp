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

int p[N], s[N];

vector<int> ans;
void ubd(int i)
{
    assert(1 <= i && i <= n - 2);
    ans.push_back(i);
    int x = (a[i] ^ a[i + 1] ^ a[i + 2]);
    a[i] = a[i + 1] = a[i + 2] = x;
}

bool solv()
{
    cin >> n;

    for (int i = 0; i <= n + 1; ++i)
    {
        p[i] = s[i] = 0;
    }
    ans.clear();

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            z = true;
            break;
        }
    }
    if (!z)
    {
        cout << "NO\n";
        return false;
    }

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = n; i >= 1; --i)
        s[i] = s[i + 1] + a[i];
    if (p[n] % 2 == 1)
    {
        cout << "NO\n";
        return false;
    }

    int u = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0 && p[i] % 2 == 0 && s[i] % 2 == 0)
        {
            u = i;
            break;
        }
    }

    if (u == -1)
    {
        int l, r;
        bool f = false;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == 0)
            {
                if (i == 0 || a[i - 1] == 1)
                {
                    l = i;
                }
                r = i;
                if (i == n || a[i + 1] == 1)
                {
                    if ((r - l + 1) % 2 == 1)
                    {
                        f = true;
                        break;
                    }
                }
            }
        }

        if (!f)
        {
            cout << "NO\n";
            return false;
        }

        for (int i = l - 1; i <= n; ++i)
        {
            if (a[i] == 1 && a[i + 1] == 0 && a[i + 2] == 1)
            {
                ubd(i);
                u = i;
                break;
            }
            else if (a[i] == 1 && a[i + 1] == 0 && a[i + 2] == 0)
            {
                ubd(i);
            }
        }
    }

    if (u != -1)
    {
        for (int i = u; i <= n; ++i)
        {
            if (a[i] == 1)
            {
                if (a[i + 1] == 1)
                {
                    ubd(i - 1);
                }
                else if (a[i + 2] == 1)
                {
                    ubd(i);
                }
                else
                {
                    ubd(i);
                    ubd(i - 1);
                }
            }
        }
        for (int i = u; i >= 1; --i)
        {
            if (a[i] == 1)
            {
                if (a[i - 1] == 1)
                {
                    ubd(i - 1);
                }
                else if (a[i - 2] == 1)
                {
                    ubd(i - 2);
                }
                else
                {
                    ubd(i - 2);
                    ubd(i - 1);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        assert(a[i] == 0);
    }
    assert(sz(ans) <= n);

    cout << "YES\n";
    cout << sz(ans) << "\n";
    if (!ans.empty())
    {
        for (int i = 0; i < sz(ans); ++i)
            cout << ans[i] << ' ';
        cout << "\n";
    }
    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*for (int x = 0; x < (1 << 10); ++x)
    {
        n = 10;
        for (int i = 1; i <= n; ++i)
        {
            if ((x & (1 << (i - 1))))
                a[i] = 1;
            else
                a[i] = 0;
        }
        int q = 0;
        for (int i = 1; i <= n; ++i)
        {
            q += a[i];
        }
        if (!solv() && q % 2 != 1)
        {
            cout << "..............................................\n";
            for (int i = 1; i <= n; ++i)
                cout << a[i] << ' ';
            cout << "\n";
            cout << "..............................................\n";
        }
    }
    return 0;*/

    int tt = 1;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}