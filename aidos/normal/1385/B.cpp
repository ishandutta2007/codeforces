#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 2e6 + 123;
const int mod = 1e9 + 9;
int n;
void solve() {
    cin >> n;
    set<int> s;
    for(int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        if(!s.count(x)) cout << x << " ";
        s.insert(x);
    }
    cout << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}