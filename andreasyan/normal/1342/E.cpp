#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 400005;
const long long M = 998244353;

long long ast(long long x, long long n)
{
    long long ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

long long f[N], rf[N];

void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * (i + 1)) % M;
}

long long C(long long n, long long k)
{
    return (((f[n] * rf[k]) % M) * rf[n - k]) % M;
}

long long n;
long long k;

int tans;
vector<int> v;
void rec(int q)
{
    if (v.size() == n)
    {
        set<int> s;
        for (int i = 0; i < v.size(); ++i)
            s.insert(v[i]);
        if (s.size() == q)
            ++tans;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(i);
        rec(q);
        v.pop_back();
    }
}

void solv()
{
    cin >> n >> k;
    if (k >= n)
    {
        cout << 0 << endl;
        return;
    }
    if (k == 0)
    {
        cout << f[n] << endl;
        return;
    }
    long long q = n - k;
    long long ans = 0;
    for (long long i = 0; i <= q; ++i)
    {
        if (i % 2 == 0)
            ans = (ans + C(q, i) * ast(q - i, n)) % M;
        else
            ans = (ans - (C(q, i) * ast(q - i, n)) % M + M) % M;
    }
    ans = (ans * C(n, q)) % M;
    ans = (ans * 2) % M;
    cout << ans << endl;
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