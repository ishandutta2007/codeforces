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

ll ans;

int n;
int a[N];

ll sans;
ll p[N];

struct ban
{
    ll b, k;
    ban(){}
    ban(ll b, ll k)
    {
        this->b = b;
        this->k = k;
    }
    ll yat(ll x)
    {
        return b + k * x;
    }
};
double hat(const ban& t1, const ban& t2)
{
    return (t2.b - t1.b) / (double)(t1.k - t2.k);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
        sans += i * 1LL * a[i];
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    ans = sans;

    deque<ban> t;
    deque<double> v;

    for (int i = 1; i <= n; ++i)
    {
        ban u(-p[i - 1], i);
        while (sz(t) >= 2 && v.back() >= hat(t.back(), u))
        {
            t.pop_back();
            v.pop_back();
        }
        if (!t.empty())
            v.push_back(hat(t.back(), u));
        t.push_back(u);

        ll yans = sans + p[i - 1] - i * 1LL * a[i];
        int l = 0, r = sz(v) - 1;
        int e = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (v[m] <= a[i])
            {
                e = m + 1;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        yans += t[e].yat(a[i]);

        ans = max(ans, yans);
    }

    t.clear();
    v.clear();

    for (int i = n; i >= 1; --i)
    {
        ban u(-p[i], i);
        while (sz(t) >= 2 && v.front() <= hat(t.front(), u))
        {
            t.pop_front();
            v.pop_front();
        }
        if (!t.empty())
            v.push_front(hat(t.front(), u));
        t.push_front(u);

        ll yans = sans + p[i] - i * 1LL * a[i];
        int l = 0, r = sz(v) - 1;
        int e = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (v[m] <= a[i])
            {
                e = m + 1;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        yans += t[e].yat(a[i]);

        ans = max(ans, yans);
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}