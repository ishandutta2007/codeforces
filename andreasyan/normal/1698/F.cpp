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
const int N = 503;

int n;
int a[N], b[N];

void solv()
{
    n = 6;
    for (int i = 1; i <= n; ++i)
        a[i] = rnf() % 5 + 1;
    for (int i = 1; i <= n; ++i)
        b[i] = a[i];
    for (int i = n; i >= 1; --i)
        swap(b[i], b[rnf() % i + 1]);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    vector<pair<int, int> > va, vb;
    for (int i = 1; i < n; ++i)
    {
        va.push_back(m_p(min(a[i], a[i + 1]), max(a[i], a[i + 1])));
        vb.push_back(m_p(min(b[i], b[i + 1]), max(b[i], b[i + 1])));
    }

    sort(all(va));
    sort(all(vb));

    if (va != vb || a[1] != b[1] || a[n] != b[n])
    {
        cout << "NO\n";
        return;
    }

    vector<pair<int, int> > ans;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == b[i])
            continue;

        for (int j = i; j < n; ++j)
        {
            if (a[j] == b[i] && a[j + 1] == b[i - 1])
            {
                ans.push_back(m_p(i - 1, j + 1));
                reverse(a + i - 1, a + j + 2);
                break;
            }
        }
        if (a[i] == b[i])
            continue;

        bool z = false;
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[j] == b[i] && a[j - 1] == b[i - 1])
            {
                for (int k1 = i; k1 < j; ++k1)
                {
                    for (int k2 = j; k2 <= n; ++k2)
                    {
                        if (a[k1] == a[k2])
                        {
                            ans.push_back(m_p(k1, k2));
                            reverse(a + k1, a + k2 + 1);
                            z = true;
                            break;
                        }
                    }
                    if (z)
                        break;
                }
                if (!z)
                {
                    for (int i = 1; i <= n; ++i)
                        cout << a[i] << ' ';
                    cout << endl;
                    for (int i = 1; i <= n; ++i)
                        cout << b[i] << ' ';
                    cout << endl;
                }
                assert(z);
                break;
            }
        }
        assert(z);

        for (int j = i; j < n; ++j)
        {
            if (a[j] == b[i] && a[j + 1] == b[i - 1])
            {
                ans.push_back(m_p(i - 1, j + 1));
                reverse(a + i - 1, a + j + 2);
                break;
            }
        }
        assert(a[i] == b[i]);
    }

    for (int i = 1; i <= n; ++i)
        assert(a[i] == b[i]);

    cout << "YES\n";
    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int st = 100000;
    while (st--)
    {
        solv();
    }
    cout << "No runtime error unfortunately or fortunately" << endl;
    return 0;*/

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}