#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int n;
pair<int, int> a[maxn];
void solve() {
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cnt += c;
    }
    if(cnt == n) cout << "0\n";
    else if(cnt < n) cout << "1\n";
    else {
        cout << cnt - n << "\n";
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