#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[1000000];

string s;

int main()
{
    int n, m, a, b;
    int ans = 0;
    cin >> n >> m >> a >> b;
    while (n  > 0)
    {
        if (min(n, m) * a > b)
        {
            n -= m;
            ans += b;
        }
        else
        {
            n -= 1;
            ans += a;
        }
    }
    cout << ans;
    return 0;
}