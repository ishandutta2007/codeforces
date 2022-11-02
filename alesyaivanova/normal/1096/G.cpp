#include <bits/stdc++.h>

using namespace std;

#define int long long
#define base long long

int mod = 998244353;
int ww[23];

int binpow(int a, int p)
{
    if (p == 1)
        return a;
    int b = binpow(a, p / 2);
    b = (b * b) % mod;
    if (p % 2 == 0)
        return b;
    b = (b * a) % mod;
    return b;
}

int divide(int a, int b)
{
    return (binpow(b, mod - 2) * a) % mod;
}

void fft(vector<base>& a, int n)
{
    vector<base> v(n);
    v[0] = 1;
    int lg = 0;
    while ((1 << lg) < n)
        lg++;
    v[1] = ww[lg];
    for (int i = 2; i < n; i++)
        v[i] = (v[i - 1] * v[1]) % mod;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int e = 0; (1 << e) < n; e++)
        {
            if (i & (1 << e))
                x |= n / (1 << (e + 1));
        }
        //cout << n << " " << i << " " << x << "\n";
        if (x < i)
        {
            base c = a[i];
            a[i] = a[x];
            a[x] = c;
        }
    }
    for (int len = 1; len < n; len *= 2)
    {
        for (int st = 0; st < n; st += 2 * len)
        {
            for (int j = st; j < st + len; j++)
            {
                base x = a[j];
                base y = a[j + len];
                base w = v[(j - st) * n / (2 * len)];
                a[j] = (x + y * w) % mod;
                a[j + len] = (x - y * w) % mod;
                if (a[j + len] < 0)
                    a[j + len] += mod;
            }
        }
    }
}

void multiply(vector<base>& a, int p)
{
    int n = 1;
    while (n <= 10 * p)
        n *= 2;
    a.resize(n, 0);
    fft(a, n);
    for (int i = 0; i < n; i++)
        a[i] = binpow(a[i], p);
    fft(a, n);
    for (int i = 0; i < n; i++)
        a[i] = divide(a[i], n);
    for (int i = 1; i < n - i; i++)
    {
        base c = a[i];
        a[i] = a[n - i];
        a[n - i] = c;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ww[22] = 662;
    for (int i = 21; i >= 0; i--)
        ww[i] = (ww[i + 1] * ww[i + 1]) % mod;
    vector<int> p(10, 0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        p[d] = 1;
    }
    vector<int> res;
    multiply(p, n / 2);
    int ans = 0;
    for (int i = 0; i < (int)p.size(); i++)
        ans = (ans + p[i] * p[i]) % mod;
    cout << ans;
}