#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int n;
int a[10];
void solve() {
    for(int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    int s1 = max(a[0], a[1]), s2 = max(a[2], a[3]);
    int s = max(s1, s2);
    int t = min(s1, s2);
    for(int i = 0; i < 4; i++) {
        if(a[i] == s) continue;
        if(a[i] > t) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}