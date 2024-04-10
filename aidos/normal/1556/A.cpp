#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    int l, r;
    cin >> l >> r;
    if((l + r) % 2) {
        cout << -1 << "\n";
        return;
    }
    if(l == 0 && r == 0) {
        cout << 0 << "\n";
    }else if(l == r) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}