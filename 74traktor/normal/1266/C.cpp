#include<bits/stdc++.h>

using namespace std;

#define int long long

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0 << '\n';
        return 0;
    }
    if (r <= c) {
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                cout << i * (r + j) << " ";
            }
            cout << '\n';
        }
    }
    else {
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                cout << (i + c) * j << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}