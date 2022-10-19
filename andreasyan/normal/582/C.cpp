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
const int N = 400005;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;

int a[N];

void kar()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void gen()
{
    n = rnd() % 70 + 1;
    for (int i = 0; i < n; ++i)
        a[i] = rnd() % N;
}

ll por()
{
    //kar();
    int ans = 0;
    for (int s = 0; s < n; ++s)
    {
        for (int d = 1; d < n; ++d)
        {
            int i = s;
            int j = s;
            set<pair<int, int> > u;
            while (1)
            {
                if (u.find(m_p(i, j)) != u.end())
                    break;
                u.insert(m_p(i, j));
                i = (i + 1) % n;
                j = (j + 1) % n;
                if (j == (s + d) % n)
                    j = s;
            }
            if (d == 6)
            {
                printf("\n");
                printf("%d %d\n", s, d);
                for(auto it = u.begin(); it != u.end(); ++it)
                {
                    printf("%d %d\n", it->fi, it->se);
                }
            }
            //printf("\n");
            //printf("%d %d\n", s, d);
            bool z = true;
            for(auto it = u.begin(); it != u.end(); ++it)
            {
                //printf("%d %d\n", it->fi, it->se);
                if (a[it->se] < a[it->fi])
                    z = false;
            }
            if (z)
            {
                //printf("%d %d\n", s, d);
                ++ans;
            }
        }
    }
    return ans;
}

vector<int> v[N];

int maxu[N];

int u[N];

int p[N];

ll solv()
{
    //kar();
    for (int i = n; i < n * 2; ++i)
        a[i] = a[i - n];
    for (int i = 1; i < n; ++i)
        v[i].clear();
    for (int i = 1; i <= n; ++i)
        v[gcd(i, n)].push_back(i);
    ll ans = 0;
    for (int k = 1; k < n; ++k)
    {
        if (n % k != 0)
            continue;
        for (int i = 0; i < k; ++i)
            maxu[i] = 0;
        for (int i = 0; i < n; ++i)
            maxu[(i % k)] = max(maxu[(i % k)], a[i]);
        for (int i = n * 2 - 1; i >= 0; --i)
        {
            if (a[i] == maxu[(i % k)])
                u[i] = u[i + 1] + 1;
            else
                u[i] = 0;
        }
        int j = 0;
        for (int i = 1; i < n; ++i)
        {
            p[i] = p[i - 1];
            if (v[k][j] == i)
            {
                ++p[i];
                ++j;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            u[i] = min(u[i], n - 1);
            ans += p[u[i]];
        }
    }
    return ans;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    kar();
    printf("%lld\n", solv());
    return 0;
    if (solv() == por())
    {
        printf("OK\n");
    }
    else
    {
        printf("%lld\n", por());
        printf("%lld\n", solv());
        printf("WA\n");
    }
    return 0;
    while (1)
    {
        gen();
        if (solv() == por())
        {
            printf("OK\n");
        }
        else
        {
            printf("WA\n");
            return 0;
        }
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}