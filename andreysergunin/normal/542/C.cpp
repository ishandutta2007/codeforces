#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;

long long gcd(long long a, long long b)
{
    return b ? gcd (b, a % b) : a;
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        a[i]--;
        b[i] = a[i];
        c[i] = 1;
    }

    for (int i = 0; i < 2 * n; i++)
    {
        bool f = true;
        for (int j = 0; j < n; j++)
            if (b[b[j]] != b[j])
                f = false;
        if (f)
        {
            cout << i + 1;
            return 0;
        }
        for (int j = 0; j < n; j++)
            d[j] = 0;
        for (int j = 0; j < n; j++)
        {
            b[j] = a[b[j]];
            if (c[j] == 1)
                d[b[j]] = 1;
        }

        for (int j = 0; j < n; j++)
            c[j] = d[j];
    }
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 1)
        {
            long long k = 1;
            int l = i;
            while (a[l] != i)
            {
                k++;
                l = a[l];
            }
            ans = lcm(ans, k);
        }
    }
    if (n <= ans)
        cout << ans;
    return 0;
}