#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 2000005;


int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;

    int bs[7];
    bs[0] = (1 << 6);
    for (int i = 1; i <= 6; i++) {
        bs[i] = (bs[i - 1] << i) | (bs[i - 1] >> 1);
    }

    while (ntest--) {
        int n;
        cin >> n;
        int ans = 0;
        if (n <= 15) {
            for (int i = 6; i >= 0; i--) {
                if (bit(bs[i], n + 6)) ans = i;
            }
        } else {
            int l = 0, r = N;
            while (r >= l) {
                int mid = (l + r) / 2;
                if (1LL * mid * (mid + 1) / 2 >= n) ans = mid, r = mid - 1;
                else l = mid + 1;
            }
            if (1LL * ans * (ans + 1) / 2 == n + 1) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}