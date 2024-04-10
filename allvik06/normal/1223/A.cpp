#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << 2 << "\n";
        }
        else if (n % 2 == 0) {
            cout << 0 << "\n";
        }
        else {
            cout << 1 << "\n";
        }
    }
}