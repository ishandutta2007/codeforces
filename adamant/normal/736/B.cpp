#include <bits/stdc++.h>

using namespace std;

#define int int64_t

bool is_prime(int n)
{
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    cout << fixed << setprecision(2);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(is_prime(n))
    {
        cout << 1 << endl;
        return 0;
    }
    if(n % 2 == 0 || is_prime(n - 2))
    {
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
    return 0;
}