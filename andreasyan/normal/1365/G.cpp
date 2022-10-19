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
const int N = 1003;

int n;

ll a[N] = {0, 1, 2, 4};

ll qry(vector<int> v)
{
    if (v.empty())
        return 0;
    printf("? ");
    printf("%d ", v.size());
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
    fflush(stdout);
    ll x;
    /*x = 0;
    for (int i = 0; i < v.size(); ++i)
        x |= a[v[i]];
    return x;*/
    scanf("%lld", &x);
    return x;
}

int h[N];
ll u[13][2];

void solv()
{
    scanf("%d", &n);
    int m = 0;
    for (int x = 0; x < (1 << 13); ++x)
    {
        int q = 0;
        for (int i = 0; i < 13; ++i)
        {
            if ((x & (1 << i)))
                ++q;
        }
        if (q == 6)
        {
            h[m++] = x;
            if (m == n)
                break;
        }
    }
    for (int i = 0; i < 13; ++i)
    {
        vector<int> v;
        for (int j = 0; j < n; ++j)
        {
            if (!(h[j] & (1 << i)))
                v.push_back(j + 1);
        }
        u[i][0] = qry(v);
    }
    printf("! ");
    for (int j = 0; j < n; ++j)
    {
        ll x = 0;
        for (int i = 0; i < 13; ++i)
        {
            if ((h[j] & (1 << i)))
                x |= u[i][0];
        }
        printf("%lld ", x);
    }
    printf("\n");
    fflush(stdout);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}