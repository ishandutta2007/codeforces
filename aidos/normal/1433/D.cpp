#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int b[maxn];

void solve() {
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == a[1])++cnt;
    }
    if(cnt == n) {
        cout << "NO\n";
        return;
    } else {
        int j = -1;
        cout << "YES\n";
        for(int i = 2; i <= n; i++) {
            if(a[1] != a[i]) {
                cout << 1 << " " << i << "\n";
                j = i;
            }
        }
        for(int i = 2; i <= n; i++) {
            if(a[1] == a[i]) {
                cout << j << " " << i << "\n";
            }
        }
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