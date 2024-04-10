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
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == b) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 1; ; i++) {
            int u = 1LL * i * (i + 1) / 2;
            if (u < b - a) continue;
            if (u % 2 != (b - a) % 2) continue;
            ans = i;
            break;
        }
        cout << ans << '\n';
    }
    return 0;
}