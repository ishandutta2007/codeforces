#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    
    while (tt--) {
        int n, k, kk;
        cin >> n >> k >> kk;
        int w, b;
        cin >> w >> b;
        cout << ((k + kk) / 2 >= w && (2 * n - k - kk) / 2 >= b ? "YES\n" : "NO\n");
    }
    

    return 0;
}