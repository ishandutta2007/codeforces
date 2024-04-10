#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int L, v, l, r;
        cin >> L >> v >> l >> r;
        cout << ((l - 1) / v) + L / v - r / v << "\n";
    }
    return 0;
}