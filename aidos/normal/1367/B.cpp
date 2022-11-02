#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int a[maxn];
int n;
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 ==  a[i] % 2) continue;
        int f = -1;
        for(int j = i + 1; j < n; j+=2) {
            if(a[j] % 2 == i % 2) {
                f = j;
            }
        }
        if(f == -1) {
            cout << -1 << "\n";
            return;
        }
        swap(a[i], a[f]);
        cnt++;
    }
    cout << cnt << "\n";
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}