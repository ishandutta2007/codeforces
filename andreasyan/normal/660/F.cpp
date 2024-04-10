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

ll p[N], pp[N];

struct ban
{
    ll b, k;
    ban(ll b, ll k)
    {
        this->b = b;
        this->k = k;
    }
    ll yat(ll x)
    {
        return b + x * k;
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
        scanf("%lld", &a[i]);

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
        pp[i] = pp[i - 1] + i * a[i];

    ll ans = 0;
    deque<ban> t;
    deque<double> v;
    for (int i = 0; i <= n; ++i)
    {
        ban u = ban(-pp[i] + i * p[i], -i);
        while (!v.empty() && hat(u, t.front()) >= v.front())
        {
            t.pop_front();
            v.pop_front();
        }
        if (!t.empty())
        {
            v.push_front(hat(u, t.front()));
        }
        t.push_front(u);

        int l = 0, r = sz(v) - 1;
        ans = max(ans, pp[i] + t[0].yat(p[i]));
        while (l <= r)
        {
            int m = (l + r) / 2;
            ans = max(ans, pp[i] + t[m + 1].yat(p[i]));
            if (v[m] <= p[i])
                l = m + 1;
            else
                r = m - 1;
        }
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}