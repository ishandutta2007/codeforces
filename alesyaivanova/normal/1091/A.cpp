#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int x = a;
    x = min(x, b - 1);
    x = min(x, c - 2);
    cout << 3 * x + 3;
}