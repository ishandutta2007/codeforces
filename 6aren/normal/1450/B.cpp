#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;

    while (ntest--) {
        int n, k;
        cin >> n >> k;
        vector<ii> a(n);
        for (ii &e : a) cin >> e.x >> e.y;
        bool ok = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) <= k) cnt++;
            }
            if (cnt == n) ok = 1;
        }
        cout << (ok ? 1 : -1) << '\n';
    }

    return 0;
}