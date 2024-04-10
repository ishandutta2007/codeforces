#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
    int n, bx;
    int m, by;
    int x = 0;
    int y = 0;
    cin >> n >> bx;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        x = x * bx + k;
    }
    cin >> m >> by;
    for (int i = 0; i < m; i++) {
        cin >> k;
        y = y * by + k;
    }
    if(x < y) {
        cout << '<';
    }
    else if(x > y) {
        cout << '>';
    }
    else {
        cout << '=';
    }

}