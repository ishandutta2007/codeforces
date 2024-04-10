#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)6e5 + 100;
typedef long long ll;
int n, m;
void solve() {
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            a[i] = max(a[i], x);
            b[j] = max(b[j], x);
        }
    }
    int s = accumulate(a.begin(), a.end(), 0);
    int t = accumulate(b.begin(), b.end(), 0);
    int cur = min(n-s, m-t);
    if(cur % 2 == 1) {
        cout << "Ashish\n";
    } else {
        cout << "Vivek\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}