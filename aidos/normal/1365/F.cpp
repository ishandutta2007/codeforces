#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)1e9+7;
long long ans = 0;
int a[maxn];
int b[maxn];
int n;
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector< pair<int, int> > c, d;
    if(n % 2 == 1) {
        if(a[n/2] != b[n/2]) {
            cout << "No\n";
            return;
        }
    }
    for(int i = 0; i < n - i - 1; i++) {
        c.push_back(make_pair(a[i], a[n-i-1]));
        c.push_back(make_pair(a[n-i-1], a[i]));

        d.push_back(make_pair(b[i], b[n-i-1]));
        d.push_back(make_pair(b[n-i-1], b[i]));
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    if(c == d) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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