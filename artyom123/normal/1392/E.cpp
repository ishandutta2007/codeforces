#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) cout << 0 << " ";
                else cout << (1LL << (i + j)) << " ";
            }
            cout << endl;
        }
        int q;
        cin >> q;
        while (q--) {
            ll k;
            cin >> k;
            cout << 1 << " " << 1 << endl;
            int x = 0, y = 0;
            for (int b = 1; b < 2 * n - 1; b++) {
                if (k & (1LL << b)) {
                    if (x % 2 == 0) x++;
                    else y++;
                } else {
                    if (x % 2 == 0) y++;
                    else x++;
                }
                cout << x + 1 << " " << y + 1 << endl;
            }
        }
    }
    return 0;
}