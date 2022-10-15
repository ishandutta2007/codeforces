#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 2005;

int n, u, v, d[MN][MN], dep[MN], dist[MN];

int32_t main() {
    boost();

    cin >> n;
    int lim = (n + 1) / 2;
    cout << "? " << 1 << endl;
    int ev = 0, odd = 0;
    for (int i = 1; i <= n; i++) {
        cin >> dep[i];
        d[1][i] = dep[i];
        if (dep[i] % 2) odd++;
        else ev++;
    }
    if (ev <= lim) {
        for (int i = 2; i <= n; i++) {
            if (dep[i] % 2) continue;
            cout << "? " << i << endl;
            for (int j = 1; j <= n; j++) cin >> d[i][j];
        }
        cout << "!" << endl;
        for (int i = 1; i <= n; i++) {
            if (dep[i] % 2) continue;
            for (int j = 1; j <= n; j++) {
                if (d[i][j] == 1) cout << i << " " << j << endl;
            }
        }
    } else {
        assert(odd + 1 <= lim);
        for (int i = 2; i <= n; i++) {
            if (dep[i] % 2 == 0) continue;
            cout << "? " << i << endl;
            for (int j = 1; j <= n; j++) cin >> d[i][j];
        }
        cout << "!" << endl;
        for (int i = 1; i <= n; i++) {
            if (dep[i] % 2 == 0) continue;
            for (int j = 1; j <= n; j++) {
                if (d[i][j] == 1) cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}