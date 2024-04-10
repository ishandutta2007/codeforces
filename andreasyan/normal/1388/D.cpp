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
ll a[N];
ll ca[N];
int b[N];

int q[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
        ca[i] = a[i];

    for (int i = 1; i <= n; ++i)
    {
        if (b[i] != -1)
        {
            q[b[i]]++;
        }
    }

    queue<int> q0;
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] == 0)
            q0.push(i);
    }

    ll ans = 0;
    vector<int> s, v;
    while (!q0.empty())
    {
        int x = q0.front();
        q0.pop();

        ans += a[x];

        if (a[x] > 0)
        {
            s.push_back(x);
            if (b[x] != -1)
            {
                --q[b[x]];
                a[b[x]] += a[x];
                if (q[b[x]] == 0)
                    q0.push(b[x]);
            }
        }
        else
        {
            v.push_back(x);
            if (b[x] != -1)
            {
                --q[b[x]];
                if (q[b[x]] == 0)
                    q0.push(b[x]);
            }
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < sz(s); ++i)
        cout << s[i] << ' ';
    for (int i = sz(v) - 1; i >= 0; --i)
        cout << v[i] << ' ';
    cout << "\n";

    for (int i = 1; i <= n; ++i)
        a[i] = ca[i];

    ll sans = 0;
    for (int i = 0; i < sz(s); ++i)
    {
        int x = s[i];
        sans += a[x];
        if (b[x] != -1)
            a[b[x]] += a[x];
    }
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        int x = v[i];
        sans += a[x];
        if (b[x] != -1)
            a[b[x]] += a[x];
    }
    assert(sans == ans);
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