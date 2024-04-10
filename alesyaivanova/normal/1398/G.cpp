#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define base complex<ld>

const int lg = 19;
const int maxn = (1 << lg);
const int T = 1e6 + 9;
int a[T];
int b[T];
int n, X, Y;
int mi[T];
int dp[T];

void fft(vector<base>& x)
{
    for (int i = 0; i < maxn; i++)
    {
        int e = 0;
        for (int j = 0; j < lg; j++)
        {
            if (i & (1 << j))
                e |= (1 << (lg - j - 1));
        }
        if (e < i)
            swap(x[i], x[e]);
    }
    ld pi = acos(-1);
    for (int len = 2; len <= maxn; len *= 2)
    {
        ld ang = 2 * pi / len;
        for (int i = 0; i < maxn; i += len)
        {
            base w(1), w0(cos(ang), sin(ang));
            for (int e = i; e < i + len / 2; e++)
            {
                base x1 = x[e] + w * x[e + len / 2];
                base x2 = x[e] - w * x[e + len / 2];
                x[e] = x1;
                x[e + len / 2] = x2;
                w *= w0;
            }
        }
    }
}

void mult(int* x, int* y)
{
    vector<base> x1(maxn), y1(maxn);
    for (int i = 0; i < maxn; i++)
    {
        x1[i] = x[i];
        y1[i] = y[i];
    }
    fft(x1);
    fft(y1);
    for (int i = 0; i < maxn; i++)
        x1[i] *= y1[i];
    fft(x1);
    for (int i = 0; i < maxn; i++)
        x1[i] /= maxn;
    reverse(x1.begin() + 1, x1.end());
    for (int i = 0; i < maxn; i++)
        x[i] = floorl(x1[i].real() + 0.5);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> X >> Y;
    n++;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
        b[maxn / 2 - x] = 1;
    }
    mult(a, b);
    for (int i = 0; i < T; i++)
        b[i] = 0;
    for (int i = maxn / 2 + 1; i < maxn; i++)
    {
        int pos = (i - maxn / 2 + Y) * 2;
        if (a[i])
            b[pos] = 1;
    }
    vector<int> primes;
    for (int i = 0; i < T; i++)
        mi[i] = i;
    for (int i = 2; i < T; i++)
    {
        if (mi[i] == i)
            primes.pb(i);
        for (int e : primes)
        {
            if (e > mi[i] || i * e >= T)
                break;
            mi[i * e] = e;
        }
    }
    for (int i = 1; i < T; i++)
    {
        if (i % 2)
        {
            dp[i] = -1;
            continue;
        }
        if (b[i])
        {
            dp[i] = i;
            continue;
        }
        vector<int> cur;
        int u = i;
        while (u > 1)
        {
            cur.pb(mi[u]);
            u /= mi[u];
        }
        dp[i] = -1;
        for (int e : cur)
            dp[i] = max(dp[i], dp[i / e]);
    }
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        int x;
        cin >> x;
        cout << dp[x] << " ";
    }
}