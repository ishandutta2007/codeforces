#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int long long

vector<int> cubes;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 1000000; i++) {
        cubes.push_back(i * i * i);
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int r = cubes.size() - 1;
        bool good = 0;
        for (int i = 0; cubes[i] < x; i++) {
            while (r > 0 && cubes[i] + cubes[r] > x) {
                r--;
            }
            if (cubes[i] + cubes[r] == x) {
                good = 1;
                break;
            }
        }
        if (good) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}