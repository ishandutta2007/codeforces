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

int n, aa;
int a[N];

int l[N], r[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void solv()
{
    cin >> n >> aa;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] % a[i] == 0)
            s.pop();
        if (s.empty())
            l[i] = 1;
        else
            l[i] = s.top() + 1;
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && a[s.top()] % a[i] == 0)
            s.pop();
        if (s.empty())
            r[i] = n;
        else
            r[i] = s.top() - 1;
        s.push(i);
    }

    vector<pair<int, pair<int, int> > > v;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < aa)
            v.push_back(m_p(a[i], m_p(l[i], r[i])));
    }
    sort(all(v));

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i].fi;
        int l = v[i].se.fi;
        int r = v[i].se.se;
        while (1)
        {
            if (fi(l) < r)
            {
                ans += x;
                p[fi(l)] = p[fi(fi(l) + 1)];
            }
            else
                break;
        }
    }

    set<int> ss;
    for (int i = 1; i <= n; ++i)
        ss.insert(fi(i));
    ans += (sz(ss) - 1) * 1LL * aa;

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
        solv();
    return 0;
}