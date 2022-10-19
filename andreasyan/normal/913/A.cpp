#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long x = 1;
    for (int i = 0; i < n; ++i)
    {
        x *= 2;
        if (x > m)
        {
            cout << m << endl;
            return 0;
        }
    }
    cout << (m % x) << endl;
    return 0;
}