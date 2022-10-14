#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int, int>
#define pll pair<lli, lli>
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define test(x) cout << #x << ' ' << x << endl
#define printv(x) {\
    for (auto a : x) cout << a << ' ';\
    cout << endl;\
}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int N = 20000087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        lli ans = 0;
        lli prerow = a[0], precol = a[1];
        priority_queue <int, vector <int>, greater <int>> pq1, pq2;
        pq1.push(a[0]);
        pq2.push(a[1]);
        ans = prerow * n + precol * n;
        for (int i = 2; i < n; ++i) {
            if (i & 1) pq2.push(a[i]), precol += a[i];
            else pq1.push(a[i]), prerow += a[i];
            ans = min(ans, prerow + 1ll * pq1.top() * int(n - pq1.size()) + precol + 1ll * pq2.top() * int(n - pq2.size()));
        }
        cout << ans << endl;
    }
}