#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
int n, m;
int a[maxn];
int b[maxn];
int c[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int pos = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = n-1; i >= 0; i--) {
        ll sum = 0;
        for(int j = i; j >= 0; j--) {
            sum += a[j];
        }
        if(sum < 0) {
            break;
        }
        if(b[i]) continue;
        for(int j=i-1; j >= 0; j--) {
            if(a[j] < a[i] && b[j] == 0) {
                swap(a[j], a[i]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}