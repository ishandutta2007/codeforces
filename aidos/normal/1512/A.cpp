#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int n;
pair<int, int> a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    if(a[0].first == a[1].first) {
        cout << a[n-1].second + 1 << "\n";
    } else {
        cout << a[0].second + 1 << "\n";
    }
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}