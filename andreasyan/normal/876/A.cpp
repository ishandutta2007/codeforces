#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;

int main()
{
    cin >> n >> a >> b >> c;
    int ans = 0;
    --n;
    if (n)
    {
        ans += min(a, b);
        --n;
        if (min(a, b) < c)
            ans += n * min(a, b);
        else
            ans += n * c;
    }
    cout << ans << endl;
    return 0;
}