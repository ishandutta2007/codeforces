#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int x = 0, y = 0;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            x = max(x, a);
            y = max(y, b);
        }
        if (x + y > n)
            cout << "IMPOSSIBLE\n";
        else {
            for (int i = 0; i < x; i++)
                cout << "R";
            for (int i = 0; i < y; i++)
                cout << "W";
            for (int i = 1; i + x + y <= n; i++)
                cout << "W";
            cout << "\n";
        }
    }
}