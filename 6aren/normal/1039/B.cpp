#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); // or mt19937 for int
long long Rand(long long l, long long r) {
    if (r < l) return 0;
    return l + rng() % (r - l + 1);
}

string query(int l, int r) {
    cout << l << ' ' << r << endl;
    string s;
    cin >> s;
    return s;
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int l = 1, r = n;
    while (true) {
        if ((r - l + 1) >= 45) {
            int mid = (l + r) / 2;
            string foo = query(l, mid);
            if (foo == "Yes") {
                r = min(mid + k, n);
                l = max(1LL, l - k);
            } else {
                l = max(mid + 1 - k, 1LL);
                r = min(n, r + k);
            }
        } else {
            int t = Rand(l, r);
            string foo = query(t, t);
            if (foo == "Yes") return 0;
            else {
                l = max(1LL, l - k);
                r = min(n, r + k);
            }
        }
    }
    return 0;
}