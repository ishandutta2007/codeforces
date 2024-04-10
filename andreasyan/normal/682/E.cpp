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
const int N = 5003;
struct ban
{
    ll x, y;
    ban()
    {
        x = y = 0;
    }
    ban(ll x, ll y)
    {
        this->x = x;
        this->y = y;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}

int n;
ll SS;
ban a[N];

ll S(const ban& t1, const ban& t2, const ban& t3)
{
    return abs((t2.y - t1.y) * (t3.x - t1.x) * 2 -
               (t2.y - t1.y) * (t2.x - t1.x) -
               (t2.y - t3.y) * (t3.x - t2.x) -
               (t3.y - t1.y) * (t3.x - t1.x));
}

ll U(const ban& t1, const ban& t2, const ban& t3)
{
    return (t3.x - t1.x) * (t2.y - t1.y) - (t3.y - t1.y) * (t2.x - t1.x);
}

vector<ban> u, d;

void solv()
{
    scanf("%d%lld", &n, &SS);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1);
    u.push_back(a[1]);
    d.push_back(a[1]);
    for (int i = 2; i <= n; ++i)
    {
        if (i == n || U(a[1], a[n], a[i]) < 0)
        {
            while (u.size() >= 2 && U(u[u.size() - 2], u[u.size() - 1], a[i]) <= 0)
                u.pop_back();
            u.push_back(a[i]);
        }
        if (i == n || U(a[1], a[n], a[i]) > 0)
        {
            while (d.size() >= 2 && U(d[d.size() - 2], d[d.size() - 1], a[i]) >= 0)
                d.pop_back();
            d.push_back(a[i]);
        }
    }
    n = 0;
    for (int i = 0; i < u.size(); ++i)
        a[++n] = u[i];
    for (int i = (int)d.size() - 2; i > 0; --i)
        a[++n] = d[i];
    /*for (int i = 1; i <= n; ++i)
        printf("%lld %lld\n", a[i].x, a[i].y);
    printf("\n\n");*/
    ban t1 = a[1], t2 = a[2], t3 = a[3];
    for (int i = 1; i <= n; ++i)
    {
        int k = (i % n) + 1;
        for (int j = (i + 1) % n + 1; j != i; j = (j % n) + 1)
        {
            while (S(a[i], a[k], a[j]) < S(a[i], a[(k % n) + 1], a[j]))
                k = (k % n) + 1;
            if (S(a[i], a[k], a[j]) > S(t1, t2, t3))
            {
                t1 = a[i];
                t2 = a[k];
                t3 = a[j];
            }
        }
    }
    printf("%lld %lld\n", t1.x + t2.x - t3.x, t1.y + t2.y - t3.y);
    printf("%lld %lld\n", t1.x + t3.x - t2.x, t1.y + t3.y - t2.y);
    printf("%lld %lld\n", t3.x + t2.x - t1.x, t3.y + t2.y - t1.y);
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