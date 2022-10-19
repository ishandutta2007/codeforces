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

int c[N];
int p[N];
int s, f;
bool dfs(int x)
{
    c[x] = 1;
    if (c[a[x]] == 1)
    {
        s = a[x];
        f = x;
        c[x] = 2;
        return true;
    }
    if (c[a[x]] == 0)
    {
        p[a[x]] = x;
        if (dfs(a[x]))
        {
            c[x] = 2;
            return true;
        }
    }
    c[x] = 2;
    return false;
}

bool cc[N];

int ans[N];

int v[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        c[i] = 0;
        cc[i] = false;
        ans[i] = 0;
        v[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == 0)
        {
            if (dfs(i))
            {
                for (int x = f; x != s; x = p[x])
                    cc[x] = true;
                cc[s] = true;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (cc[i])
        {
            ans[i] = a[i];
            v[a[i]] = i;
            continue;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!v[a[i]])
        {
            ans[i] = a[i];
            v[a[i]] = i;
        }
    }

    vector<vector<int> > uu;
    for (int i = 1; i <= n; ++i)
    {
        if (!v[i])
        {
            vector<int> u;
            int x = i;
            while (1)
            {
                u.push_back(x);
                if (!ans[x])
                    break;
                x = ans[x];
            }
            uu.push_back(u);
        }
    }

    if (sz(uu) == 1 && sz(uu[0]) == 1)
    {
        ans[uu[0][0]] = a[uu[0][0]];
        ans[v[a[uu[0][0]]]] = uu[0][0];
    }
    else
    {
        for (int i = 0; i < sz(uu); ++i)
            ans[uu[i].back()] = uu[(i + 1) % sz(uu)][0];
    }

    int yans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i] == a[i])
            ++yans;
    }
    cout << yans << "\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
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