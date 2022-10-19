#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string x;
    cin >> x;
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        char c1, c2;
        cin >> c1 >> c2;
        while (l<=r) {
            if (x[l]==c1) {
                x[l]=c2;
            }
            ++l;
        }
    }
    cout << x;
}