#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    if (abs(z - x) * t2 + abs(x - y) * t2 + 3 * t3 <= t1 * abs(x - y))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}