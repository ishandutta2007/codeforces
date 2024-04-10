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

const int maxn = 2e5 + 9;
int a[maxn];
int n;
int b[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    sort(a, a + n);
    int max_cnt = 0;
    int cnt = 0;
    int elem = 0;
    for (int i = 0; i < n; i++) {
        if (i && a[i] != a[i - 1]) {
            cnt = 0;
        }
        cnt++;
        if (cnt > max_cnt) {
            max_cnt = cnt;
            elem = a[i];
        }
    }
//    if (max_cnt > n / 2) {
//        cout << "NO\n";
//        return;
//    }
//    if (max_cnt * 2 == n) {
//        for (int i = 0; i < n; i += 2) {
//            b[i] = elem;
//        }
//        int pt = 1;
//        for (int i = 0; i < n; i++) {
//            if (a[i] != elem) {
//                b[pt] = a[i];
//                pt += 2;
//            }
//        }
//    } else if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            b[i * 2] = a[i];
            b[i * 2 + 1] = a[i + n / 2];
        }
//    }
    for (int i = 0; i < n; i++) {
        if (b[i] == b[(i + 1) % n]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}