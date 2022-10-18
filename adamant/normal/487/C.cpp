#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int binpow(int x, int n, int m)
{
    if(n == 0) return 1;
    int t = binpow(x, n / 2, m);
    if(n % 2) return x * t * t % m;
    else return t * t % m;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << "YES\n1\n";
        return 0;
    }
    if(n == 4)
    {
        cout << "YES\n" << 1 << "\n" << 3 << "\n" << 2 << "\n" << 4 << "\n";
        return 0;
    }
    for(int i = 2; i < n; i++)
    {
        if(!(n % i))
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n1\n";
    int x = 1;
    for(int i = 2; i < n; i++)
        cout << binpow(i - 1, n - 2, n) * i % n << "\n";
    cout << n << "\n";
    return 0;
}