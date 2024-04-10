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
ll k;

struct ban
{
    int d, q;
    ban(){}
    ban(int d, int q)
    {
        this->d = d;
        this->q = q;
    }
    ll val() const
    {
        return (d / (q + 1)) * 1LL * (d / (q + 1)) * 1LL * (q + 1 - (d % (q + 1))) +
            (d / (q + 1) + 1) * 1LL * (d / (q + 1) + 1) * 1LL * (d % (q + 1));
    }
    ll og() const
    {
        return val() - ban(d, q + 1).val();
    }
};

bool operator<(const ban& a, const ban& b)
{
    return a.og() < b.og();
}

ll stg(ll g)
{
    ll kk = 0;
    for (int i = 1; i <= n; ++i)
    {
        int l = 0, r = a[i] - a[i - 1];
        int u;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (ban(a[i] - a[i - 1], m).og() <= g)
            {
                u = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        kk += ban(a[i] - a[i - 1], u).val();
    }
    return kk;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> k;

    if (stg(1000000009000000009LL) <= k)
    {
        cout << "0\n";
        return;
    }

    ll l = 0, r = 1000000009000000009LL;
    ll g;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (stg(m) > k)
        {
            g = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    priority_queue<ban> q;
    ll kk = 0;
    for (int i = 1; i <= n; ++i)
    {
        int l = 0, r = a[i] - a[i - 1];
        int u;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (ban(a[i] - a[i - 1], m).og() <= g)
            {
                u = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        kk += ban(a[i] - a[i - 1], u).val();
        q.push(ban(a[i] - a[i - 1], u));
    }

    while (kk > k)
    {
        ban t = q.top();
        q.pop();

        int l = 0, r = t.d;
        int u;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (ban(t.d, t.q + m).og() != t.og())
            {
                u = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        if (kk - t.og() * u > k)
        {
            kk -= t.og() * u;
            t.q += u;
            q.push(t);
        }
        else
        {
            // kk hech
            t.q += (kk - k) / t.og() + !!((kk - k) % t.og());
            q.push(t);
            break;
        }
    }

    int ans = 0;
    while (!q.empty())
    {
        ans += q.top().q;
        q.pop();
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