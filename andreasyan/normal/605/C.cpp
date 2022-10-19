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
const int N = 100005;
#define double long double

struct ban
{
    int x, y;
    ban(){}
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n, p, q;
ban a[N];

double ans;
double stg(double x)
{
    for (int i = n - 1; i >= 1; --i)
    {
        if (x >= a[i].x)
        {
            double y = (x - a[i].x) * (a[i + 1].y - a[i].y) / (a[i + 1].x - a[i].x) + a[i].y;
            ans = max((p / x), (q / y));
            return (p / x) - (q / y);
        }
    }
    assert(false);
}

ll F(const ban& t1, const ban& t2, const ban& t)
{
    return (t.x - t1.x) * 1LL * (t2.y - t1.y) - (t.y - t1.y) * 1LL * (t2.x - t1.x);
}

void solv()
{
    cin >> n >> p >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;

    sort(a + 1, a + n + 1);

    vector<ban> v;

    int y = a[1].y;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i].x == a[i - 1].x)
            y = max(y, a[i].y);
        else
        {
            v.push_back(ban(a[i - 1].x, y));
            y = a[i].y;
        }
    }
    v.push_back(ban(a[n].x, y));

    n = sz(v);
    for (int i = 1; i <= n; ++i)
        a[i] = v[i - 1];

    v.clear();

    int maxu = 0;
    for (int i = n; i >= 1; --i)
    {
        if (maxu >= a[i].y)
            continue;
        maxu = a[i].y;
        v.push_back(a[i]);
    }
    reverse(all(v));

    n = sz(v);
    for (int i = 1; i <= n; ++i)
        a[i] = v[i - 1];

    v.clear();
    for (int i = 1; i <= n; ++i)
    {
        while (sz(v) >= 2 && F(v[sz(v) - 2], v.back(), a[i]) < 0)
            v.pop_back();
        v.push_back(a[i]);
    }

    n = sz(v);
    for (int i = 1; i <= n; ++i)
        a[i] = v[i - 1];

    if (n == 1)
    {
        cout << max(p / (double)a[1].x, q / (double)a[1].y) << "\n";
        return;
    }

    double l = a[1].x, r = a[n].x;

    for (int ii = 0; ii < 200; ++ii)
    {
        double m = (l + r) / 2;
        if (stg(m) < 0)
            r = m;
        else
            l = m;
    }

    stg(l);
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}