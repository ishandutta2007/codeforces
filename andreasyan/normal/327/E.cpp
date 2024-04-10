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
const int N = 25;
const int M = 1000000007;
const int M1 = 341234291;

bool isprime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int f[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
}

int n;
int a[N];
int k;
int v[2];

int solv0()
{
    return f[n];
}

int solv1()
{
    map<ll, int> mp[N];
    for (int x = 0; x < (1 << (n / 2)); ++x)
    {
        int q = 0;
        ll s = 0;
        for (int i = 0; i < (n / 2); ++i)
        {
            if ((x & (1 << i)))
            {
                ++q;
                s += a[i];
            }
        }
        mp[q][s]++;
    }
    int ans = 0;
    for (int x = 0; x < (1 << (n / 2 + n % 2)); ++x)
    {
        int q = 0;
        ll s = 0;
        for (int i = 0; i < (n / 2 + n % 2); ++i)
        {
            if ((x & (1 << i)))
            {
                ++q;
                s += a[(n / 2) + i];
            }
        }
        for (int q0 = 0; q0 <= (n / 2); ++q0)
        {
            if (mp[q0].find(v[0] - s) != mp[q0].end())
            {
                ans += ((f[q + q0] * 1LL * f[n - q - q0]) % M * 1LL * mp[q0][v[0] - s]) % M;
                ans %= M;
            }
        }
    }
    return ans;
}

int solv2()
{
    if (v[0] > v[1])
        swap(v[0], v[1]);
    int z = 0;
    map<pair<ll, ll>, int> s;
    map<int, int> mp[N][N];
    for (int x = 0; x < (1 << (n / 2)); ++x)
    {
        for (int y = x; ; y = (y - 1) & x)
        {
            ll s0 = 0, s1 = 0;
            int q0 = 0, q1 = 0;
            for (int i = 0; i < (n / 2); ++i)
            {
                if (x & (1 << i))
                {
                    s1 += a[i];
                    if ((y & (1 << i)))
                    {
                        ++q0;
                        s0 += a[i];
                    }
                    else
                        ++q1;
                }
            }
            if (s.find(m_p(s0, s1)) == s.end())
                s[m_p(s0, s1)] = ++z;
            int u = s[m_p(s0, s1)];
            mp[q0][q1][u]++;
            if (y == 0)
                break;
        }
    }
    int ans = 0;
    for (int x = 0; x < (1 << (n / 2 + n % 2)); ++x)
    {
        for (int y = x; ; y = (y - 1) & x)
        {
            ll s0 = 0, s1 = 0;
            int q0 = 0, q1 = 0;
            for (int i = 0; i < (n / 2 + n % 2); ++i)
            {
                if (x & (1 << i))
                {
                    s1 += a[i + n / 2];
                    if ((y & (1 << i)))
                    {
                        ++q0;
                        s0 += a[i + n / 2];
                    }
                    else
                        ++q1;
                }
            }
            if (s.find(m_p(v[0] - s0, v[1] - s1)) == s.end())
            {
                if (y == 0)
                    break;
                continue;
            }
            int u = s[m_p(v[0] - s0, v[1] - s1)];
            for (int q0_ = 0; q0_ <= (n / 2); ++q0_)
            {
                for (int q1_ = 0; q0_ + q1_ <= (n / 2); ++q1_)
                {
                    if (mp[q0_][q1_].find(u) != mp[q0_][q1_].end())
                    {
                        ans += (((f[q0 + q0_] * 1LL * f[q1 + q1_]) % M * 1LL * f[n - q0 - q0_ - q1 - q1_]) * 1LL * mp[q0_][q1_][u]) % M;
                        ans %= M;
                    }
                }
            }
            if (y == 0)
                break;
        }
    }
    return ans;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
        scanf("%d", &v[i]);
    int ans;
    if (k == 0)
        ans = solv0();
    else if (k == 1)
    {
        ans = solv0();
        ans = (ans - solv1() + M) % M;
    }
    else
    {
        ans = solv0();
        ans = (ans - solv1() + M) % M;
        swap(v[0], v[1]);
        ans = (ans - solv1() + M) % M;
        ans = (ans + solv2()) % M;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}