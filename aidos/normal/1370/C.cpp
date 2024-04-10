#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
void solve() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << "FastestFinger\n";
        return;
    }
    if(n % 2 == 1 || n == 2) {
        cout << "Ashishgup\n";
        return;
    }
    int cnt = 0;
    while(n % 2 == 0) {
        n/=2;
        cnt++;
    }
    if(n == 1) {
        cout << "FastestFinger\n";
        return;
    }
    if(cnt > 1) {
        cout << "Ashishgup\n";
        return;
    }
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            cout << "Ashishgup\n";
            return;
        }
    }
    cout << "FastestFinger\n";
}
int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}