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
const int N = 200000, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k & 1 ^ 1) {
            cout << 1 << ' ';
            n--, k--;
        }
        int base = 1;
        while (n > (k << 1) && n & 1 ^ 1) n >>= 1, base <<= 1;
        if ((n ^ k) & 1) {
            for (int i = 0; i < k; ++i) {
                if (n > k - i) cout << base * 2 << ' ', n -= 2;
                else cout << base << ' ', n--;
            }
            cout << endl;
        } else {
            for (int i = 0; i < k - 2; ++i) cout << base << ' ';
            cout << (n - k + 2) / 2 * base << ' ' << (n - k + 2) / 2 * base << endl;
        }
    }
}