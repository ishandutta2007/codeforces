#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int k;
int a[111][111];
void solve() {
    cin >> k;
    if(k == 1) {
        cout << 1 << "\n";
    } else if(k == 2){
        cout << -1 << "\n";
    } else {
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                a[i][j] = i * k + j + 1;
            }
        }
        for(int i = 1; i < k; i += 2) {
            for(int j = 1; j < k; j++) {
                swap(a[j][i], a[j-1][i]);
            }
        }
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
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