#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, k;
int a[maxn];
void solve() {
    cin >> n >> k;
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x * 2 == k) {
            if(c1 > c2) {
                cout << 1 << " ";
                c2++;
            } else {
                cout << 0 << " ";
                c1++;
            }
        } else if(x * 2 < k) {
            cout << 0 << " ";
        } else {
            cout << 1 << " ";
        }
    }
    cout << "\n";
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}