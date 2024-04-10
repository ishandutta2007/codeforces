#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x[3];
    long long d;
    cin >> x[0] >> x[1] >> x[2] >> d;
    sort(x, x + 3);
    long long ans = 0;
    if (x[1] - x[0] < d)
        ans += (d - (x[1] - x[0]));
    if (x[2] - x[1] < d)
        ans += (d - (x[2] - x[1]));
    cout << ans << endl;
    return 0;
}