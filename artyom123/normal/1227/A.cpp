#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int maxl = -INF, minr = INF;
        while (n--) {
            int l, r;
            cin >> l >> r;
            maxl = max(maxl, l); minr = min(minr, r);
        }
        cout << (maxl <= minr ? 0 : maxl - minr) << "\n";
    }
    return 0;
}