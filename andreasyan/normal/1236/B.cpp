#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;

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

int main()
{
    long long n, m;
    cin >> n >> m;
    cout << ast((ast(2, m) - 1 + M) % M, n) << endl;
    return 0;
}