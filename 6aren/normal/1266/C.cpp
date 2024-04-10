#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int r, c;
    cin >> r >> c;
    if (c == 1) {
        if (r == 1) {
            cout << 0;
            return 0;
        }
        for (int i = 1; i <= r; i++) {
            cout << i + 1 << endl;
        }
        return 0;
    }
    for (int i = 1; i <= c; i++) {
        cout << i + 1 << ' ';
    }
    cout << endl;
    for (int i = 2; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << (c + i) * (j + 1) << ' ';
        }
        cout << endl;
    }
    return 0;
}