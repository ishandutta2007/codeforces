#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 2e5 + 123;
const int mod = 1e9 + 7;
int n, k;
void solve() {
    cin >> n >> k;
    int last = -1;
    set<int> S;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        S.insert(x);
    }
    int cur = 0;
    int ok = 0;
    while(k > 0) {
        while(S.count(cur)) ++cur;
        int d = *(--S.end());
        if(cur == d + 1) {
            ok = 1;
            break;
        }
        k--;
        int el = (d + cur + 1)/2;
        if(last == el) {
            break;
        }
        last = el;
        S.insert(last);
    }
    if(ok) cout << S.size() + k << "\n";
    else cout << S.size() << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}