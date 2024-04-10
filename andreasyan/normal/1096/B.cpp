#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long M = 998244353;

int n;
char a[N];

int main()
{
    cin >> n >> a;
    long long ans = 0;
    long long x = 0, y = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == a[0])
            ++x;
        else
            break;
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == a[n - 1])
            ++y;
        else
            break;
    }
    if (a[0] != a[n - 1])
        cout << x + y + 1 << endl;
    else
        cout << ((x + 1) * (y + 1)) % M << endl;
    return 0;
}