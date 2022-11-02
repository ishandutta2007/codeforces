#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
int n, m, k;
void solve() {
    cin >> n >> k;
    if(n < k) {
        cout << k - n << "\n";
    } else {
        cout << (k + n) % 2 << "\n";
    }
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