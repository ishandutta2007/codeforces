#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
int a[maxn];
int col[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        col[i] = 0;
    }
    int sz = 1;
    for(int pr = 2; pr * pr <= 1000; pr++) {
        int ok = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] % pr == 0 && col[i] == 0) {
                col[i] = sz;
                ok = 1;
            }
        }
        sz += ok;
    }
    cout << sz - 1 << "\n";
    for(int i = 0; i < n; i++) {
        cout << col[i] << " \n"[i + 1 == n];
    }

}
int main() {
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}