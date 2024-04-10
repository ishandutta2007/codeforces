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

struct ban
{
    ll a, b;
};
bool operator<(const ban& a, const ban& b)
{
    return a.b < b.b;
}

int n;
ban u[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> u[i].a >> u[i].b;
    sort(u + 1, u + n + 1);

    ll s = 0;
    ll ans = 0;

    int j = 1;
    int i = n;
    while (1)
    {
        while (j <= n && s >= u[j].b)
        {
            s += u[j].a;
            ans += u[j].a;
            u[j].a = 0;
            ++j;
        }
        if (j == n + 1)
            break;

        ll q = min(u[i].a, u[j].b - s);
        s += q;
        ans += q * 2;
        u[i].a -= q;
        if (u[i].a == 0)
            --i;
        if (i == 0)
            break;
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