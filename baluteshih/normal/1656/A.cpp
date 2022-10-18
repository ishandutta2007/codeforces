#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, mx = 0, mi = 2e9;
        int mxn = -1, minn = -1;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            if (x > mx)
                mx = x, mxn = i;
            if (x < mi)
                mi = x, minn = i;
        }
        cout << minn << " " << mxn << "\n";
    }
}