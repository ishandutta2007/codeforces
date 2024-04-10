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
const ll INF = 1000000009000000009;

int n, k, b, c;
int ca[N];

struct ban
{
    int cc;
    int x;
};
bool operator<(const ban& a, const ban& b)
{
    ll aa = a.cc;
    ll bb = b.cc;
    if (a.x < b.x)
        aa += (b.x - a.x) * 1LL * ::b;
    else
        bb += (a.x - b.x) * 1LL * ::b;
    return aa < bb;
}
bool so(const ban& a, const ban& b)
{
    return a.x < b.x;
}

ban a[N];

void solv()
{
    scanf("%d%d%d%d", &n, &k, &b, &c);
    b = min(b, c * 5);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &ca[i]);
    int minu = 0;
    for (int i = 1; i <= n; ++i)
        minu = min(minu, ca[i]);
    for (int i = 1; i <= n; ++i)
        ca[i] -= minu;
    ll ans = INF;
    for (int mn = 0; mn < 5; ++mn)
    {
        for (int i = 1; i <= n; ++i)
        {
            a[i].x = ca[i];
            a[i].cc = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            while ((a[i].x % 5) != mn)
            {
                ++a[i].x;
                a[i].cc += c;
            }
            a[i].x /= 5;
        }
        sort(a + 1, a + n + 1, so);
        priority_queue<ban> q;
        ll s = 0, ss = 0;
        for (int i = 1; i <= n; ++i)
        {
            q.push(a[i]);
            s += a[i].x;
            ss += a[i].cc;
            while (q.size() > k)
            {
                s -= q.top().x;
                ss -= q.top().cc;
                q.pop();
            }
            if (q.size() == k)
            {
                ll yans = ss;
                yans += (k * 1LL * a[i].x - s) * b;
                ans = min(ans, yans);
            }
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
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}