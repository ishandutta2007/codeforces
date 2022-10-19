#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int stg(int x)
{
    if (1 <= x && x <= 9)
        return x;
    int s = 0;
    while (x)
    {
        s += (x % 10);
        x /= 10;
    }
    return stg(s);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long x, k;
        cin >> k >> x;
        cout << x + 9LL * (k - 1) << endl;
    }
    return 0;
}