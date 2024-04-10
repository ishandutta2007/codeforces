#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
int l[maxn];
int r[maxn];
int c[maxn];
int n;
int inf = 1e18;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> c[i];
    }
    int left_id = 0;
    int right_id = 0;
    int L = l[0];
    int R = r[0];
    int mid_id = 0;
    cout << c[0] << "\n";
    for (int i = 1; i < n; i++) {
        if (l[i] == L && r[i] == R) {
            if (!(l[mid_id] == L && r[mid_id] == R) || c[i] < c[mid_id]) {
                mid_id = i;
            }
        } else if (l[i] <= L && r[i] >= R) {
            mid_id = i;
       }

        if (l[i] == L) {
            if (l[left_id] != L || c[i] < c[left_id]) {
                left_id = i;
            }
        } else if (l[i] < L) {
            left_id = i;
            L = l[i];
        }
        if (r[i] == R) {
            if (r[right_id] != R || c[i] < c[right_id]) {
                right_id = i;
            }
        } else if (r[i] > R) {
            right_id = i;
            R = r[i];
        }
        int ans = inf;
        if (l[left_id] == L && r[right_id] == R) {
            ans = min(ans, c[left_id] + c[right_id]);
        }
        if (l[mid_id] == L && r[mid_id] == R) {
            ans = min(ans, c[mid_id]);
        }
        cout << ans << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}