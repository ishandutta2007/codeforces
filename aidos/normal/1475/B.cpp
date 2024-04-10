#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
void solve() {
    int n;
    cin >> n;
    if(n / 2020 >= n % 2020) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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