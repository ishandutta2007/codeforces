#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    cin >>n >> k;
    if(k == 0) {
        for(int i = 1; i <= n; i++) {
            cout << i  << " ";
        }
        cout << "\n";
        return;
    }
    if(2 * k + 1 > n) {
        cout << -1 << "\n";
        return;
    }
    for(int i = 0; i < 2 * k + 1; i++) {
        if(i % 2 == 0) {
            cout << i/2 + 1 << " ";
        } else{
            cout << k + 2 + i/2 << " ";
        }
    }
    for(int i = 2 * k + 1; i < n; i++) {
        cout << i + 1 << " ";
    }
    cout << "\n";
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