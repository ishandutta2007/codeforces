#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int inf = 1e9+100;
const int nax = 1e5;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int ans = k * 7;
        vector<int> p(7), a(7), b(8);
        for (int i = 0; i < 7; ++i) {
            cin >> p[i];
            a[i] = (i > 0 ? a[i - 1] : 0) + p[i];
        }
        for (int i = 6; i >= 0; --i) {
            b[i] = (i < 6 ? b[i + 1] : 0) + p[i];
        }
        for (int i = 0; i <= 7; ++i) {
            for (int j = 0; j <= 7; ++j) {
                ans = min(ans, i + 7 - j + (k - (i > 0 ? a[i - 1] : 0) - b[j] + a[6] - 1) / a[6] * 7);
                if (j >= i && a[j] - (i > 0 ? a[i - 1] : 0) >= k) {
                    ans = min(ans, j - i + 1);
                }
            }
        }
        cout << ans << '\n';
    }
}