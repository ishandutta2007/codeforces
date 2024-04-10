#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
ll r, b, d;
void solve() {
    cin >> r >> b >> d;
    if(r * (d+1) >= b && (d+1) * b >= r){
        cout << "YES\n";
    } else {
        cout << "NO\n";
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