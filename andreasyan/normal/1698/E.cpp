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
const int N = 200005, M = 998244353;

int n, s;
int a[N], b[N];

int u[N];
bool t[N];

bool c[N];

void solv()
{
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
    {
        u[i] = 0;
        t[i] = false;
        c[i] = false;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (b[i] != -1)
        {
            u[b[i]] = a[i];
            t[a[i]] = true;
        }
    }

    vector<int> v1, v2;
    for (int i = 1; i <= n; ++i)
    {
        if (t[i])
            continue;

        vector<int> v;
        int x = i;
        while (x)
        {
            c[x] = true;
            v.push_back(x);
            x = u[x];
        }

        for (int i = 0; i < sz(v) - 1; ++i)
        {
            if (v[i + 1] - v[i] > s)
            {
                cout << "0\n";
                return;
            }
        }
        v1.push_back(v[0]);
        v2.push_back(v.back());
    }

    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;

        vector<int> v;
        int x = i;
        while (!c[x])
        {
            c[x] = true;
            v.push_back(x);
            x = u[x];
        }

        for (int i = 0; i < sz(v) - 1; ++i)
        {
            if (v[i + 1] - v[i] > s)
            {
                cout << "0\n";
                return;
            }
        }
        if (v[0] - v.back() > s)
        {
            cout << "0\n";
            return;
        }
    }

    sort(all(v1));
    sort(all(v2));

    int ans = 1;
    int j = 0;
    for (int i = 0; i < sz(v2); ++i)
    {
        while (j < sz(v1) && v1[j] - v2[i] <= s)
            ++j;
        if ((j - i) <= 0)
        {
            ans = 0;
            break;
        }
        ans = (ans * 1LL * (j - i)) % M;
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