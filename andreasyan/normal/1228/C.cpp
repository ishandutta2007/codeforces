#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;

long long ast(long long x, long long n)
{
    long long ans = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            ans = (ans * x) % M;
            --n;
        }
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

int x;
long long n;

long long ans = 1;

void ubd(long long i)
{
    bool z = true;
    long long yans = 0;
    for (long long j = i; j <= n; j *= i)
    {
        long long u = j;
        while (u % i == 0)
            u /= i;
        if (u != 1)
            break;
        yans += (n / j);
    }
    ans = (ans * ast(i, yans)) % M;
}

int main()
{
    cin >> x >> n;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            ubd(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x != 1)
        ubd(x);
    cout << ans << endl;
    return 0;
}