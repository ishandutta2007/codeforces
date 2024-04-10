#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n;
int a[maxn];
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int d = abs(a - b);
    if(a > d && b > d) {
        cout << -1 << "\n";
        return;
    }
    if(d * 2 < c) {
        cout << -1 << "\n";
        return;
    }
    if(c > d) {
        cout << c - d << "\n";
    } else {
        cout << c+d << "\n";
    }
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}