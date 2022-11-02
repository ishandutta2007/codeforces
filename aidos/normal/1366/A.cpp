#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 5e5 + 123;
const int mod = 1e9 + 7;
int a, b;
void solve() {
    cin >> a >> b;
    cout << min({(a+b)/3, a, b}) << "\n";
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