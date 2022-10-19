#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        long long l, r, d;
        cin >> l >> r >> d;
        if ((l - 1) / d != 0) {
            cout << d << endl;
            continue;
        }
        cout << ((r / d) + 1) * d << endl;
    }
    return 0;
}