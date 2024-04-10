#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 18, K = 3e6;

bool ask(lli mid, int n) {
    lli bridge = mid + 1 >> 1;
    if (bridge > n - 1) return false;
    lli remain = n - bridge;
    return mid - bridge <= remain * (remain - 1) / 2;
}

int main () {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        lli l = 0, r = 1ll * n * (n + 1) / 2 + 1;
        while (r - l > 1) {
            lli mid = l + r >> 1;
            if (ask(mid, n)) l = mid;
            else r = mid;
        }
        cout << l << endl;
    }
}