#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;

int n;
void solve() {
    cin >> n;
    int mi = 123123;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x < mi) {
            mi = x;
            cnt = 1;
        } else if(x == mi) cnt++;
    }
    cout << n - cnt << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}