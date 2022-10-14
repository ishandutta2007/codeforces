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
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;
        if (k1 > k2) swap(k1, k2);
        w -= k1;
        b -= n - k2;
        w -= (k2 - k1) / 2;
        b -= (k2 - k1) / 2;
        if (w  <= 0 && b <= 0) cout << "YES\n";
        else cout << "NO\n";
    }
}