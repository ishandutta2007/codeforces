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
const int M = 1000000007;

int ast(int x, ll n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int k, n;
map<ll, int> c;

map<ll, vector<int> > mp;

void solv()
{
    cin >> k;
    cin >> n;

    set<ll> h;
    for (int i = 1; i <= n; ++i)
    {
        ll v;
        string s;
        cin >> v >> s;

        int u = 2;
        if (s[0] == 'w' || s[0] == 'y')
            u = 0;
        else if (s[0] == 'g' || s[0] == 'b')
            u = 1;

        c[v] = u;

        ll x = v;
        while (x)
        {
            h.insert(x);
            x /= 2;
        }
    }

    int ans = 1;
    for (auto it = h.begin(); it != h.end(); ++it)
    {
        if ((1LL << (k - 1)) <= *it)
        {
            vector<int> v;
            v.assign(3, 0);
            v[c[*it]] = 1;
            mp[*it] = v;
        }
    }
    for (int i = k - 2; i >= 0; --i)
    {
        for (auto it = h.begin(); it != h.end(); ++it)
        {
            if ((1LL << i) <= *it && *it < (1LL << (i + 1)))
            {
                vector<int> v;
                for (int u = 0; u < 3; ++u)
                {
                    if (c.find(*it) != c.end() && c[*it] != u)
                    {
                        v.push_back(0);
                        continue;
                    }
                    int yans = 1;
                    if (mp.find(*it * 2) == mp.end())
                    {
                        yans = (yans * 1LL * ((ans + ans) % M)) % M;
                    }
                    else
                    {
                        int s = 0;
                        for (int v = 0; v < 3; ++v)
                        {
                            if (v == u)
                                continue;
                            s = (s + mp[*it * 2][v]) % M;
                        }
                        yans = (yans * 1LL * s) % M;
                    }
                    if (mp.find(*it * 2 + 1) == mp.end())
                    {
                        yans = (yans * 1LL * ((ans + ans) % M)) % M;
                    }
                    else
                    {
                        int s = 0;
                        for (int v = 0; v < 3; ++v)
                        {
                            if (v == u)
                                continue;
                            s = (s + mp[*it * 2 + 1][v]) % M;
                        }
                        yans = (yans * 1LL * s) % M;
                    }
                    v.push_back(yans);
                }
                mp[*it] = v;
            }
        }
        ans = (ans * 2LL) % M;
        ans = (ans * 1LL * ans) % M;
    }

    if (!h.empty())
    {
        ans = ((mp[1][0] + mp[1][1]) % M + mp[1][2]) % M;
    }
    else
    {
        ans = (ans * 3LL) % M;
    }

    ans = (ans * 1LL * ast(2, (1LL << k) - 1 - n)) % M;
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
        solv();
    return 0;
}