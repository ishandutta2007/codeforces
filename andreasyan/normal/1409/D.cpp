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

void solv()
{
    ll n;
    int s;
    scanf("%lld%d", &n, &s);
    vector<int> v;
    ll cn = n;
    while (n)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    n = cn;
    reverse(all(v));
    int ss = 0;
    for (int i = 0; i < sz(v); ++i)
        ss += v[i];
    if (ss <= s)
    {
        printf("0\n");
        return;
    }

    for (int i = sz(v) - 1; i >= 0; --i)
    {
        if (v[i] == 9)
            continue;
        int ss = 0;
        for (int j = 0; j < i; ++j)
            ss += v[j];
        ss += (v[i] + 1);
        if (ss <= s)
        {
            ll nn = 0;
            for (int j = 0; j < i; ++j)
                nn = nn * 10 + v[j];
            nn = nn * 10 + (v[i] + 1);
            for (int j = i + 1; j < sz(v); ++j)
                nn = nn * 10;
            printf("%lld\n", nn - n);
            return;
        }
    }
    ll nn = 1;
    for (int i = 0; i < sz(v); ++i)
        nn = nn * 10;
    printf("%lld\n", nn - n);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}