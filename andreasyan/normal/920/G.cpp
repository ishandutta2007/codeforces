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
const int M = 1000000009;

int x, p, k;

vector<int> v;

int stg(int u)
{
    int ans = 0;
    for (int x = 0; x < (1 << sz(v)); ++x)
    {
        int y = 1;
        int q = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            if ((x & (1 << i)))
            {
                ++q;
                y *= v[i];
            }
        }
        if (q % 2 == 0)
            ans += (u / y);
        else
            ans -= (u / y);
    }
    return ans;
}

void solv()
{
    scanf("%d%d%d", &x, &p, &k);

    v.clear();
    for (int i = 2; i * i <= p; ++i)
    {
        if (p % i == 0)
        {
            v.push_back(i);
            while (p % i == 0)
                p /= i;
        }
    }
    if (p > 1)
        v.push_back(p);

    int l = x + 1, r = M;
    int ans;

    int stgx = stg(x);

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m) - stgx >= k)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}