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

bool c[N];
bool cc[N];

void solv()
{
    int n;
    cin >> n;

    if (n <= 3)
    {
        cout << 0 << endl;
        return;
    }

    int maxu = 0, k;
    for (int i = 1; i <= n; ++i)
    {
        maxu = max(maxu, n - n / i - !!(n % i) - (i - 1));
    }

    for (int i = 1; i <= n; ++i)
    {
        if (maxu == n - n / i - !!(n % i) - (i - 1))
        {
            k = i;
            break;
        }
    }

    for (int i = 1; i <= n; i += k)
        cc[i] = true;

    for (int ii = 0; ii < 1000; ++ii)
    {
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            if (!cc[i] && !c[i])
                v.push_back(i);
        }

        int d = sz(v);
        cout << sz(v) << ' ';
        for (int i = 0; i < sz(v); ++i)
        {
            cout << v[i] << ' ';
            c[v[i]] = true;
        }
        cout << endl;

        int x;
        cin >> x;

        int u = x;
        for (int i = 0; i < d; ++i)
        {
            c[u] = false;
            ++u;
            if (u == n + 1)
                u = 1;
        }
    }

    cout << 0 << endl;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}