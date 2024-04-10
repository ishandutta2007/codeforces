#include <bits/stdc++.h> 

using namespace std;

#define all(x) begin(x), end(x)

const int inf = 1e9 + 7;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int g = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        cnt += a[i] != 1;
    }
    if(g != 1) {
        cout << -1 << "\n";
        return 0;
    }
    int ans = 1e6;
    for(int i = 0; i < n; i++) {
        int j = i + 1;
        int g = a[i];
        while(j < n && g != 1) {
            g = __gcd(g, a[j++]);
        }
        if(g == 1) {
            ans = min(ans, cnt - (a[i] != 1) + j - i - 1);
        }
    }
    cout << ans << "\n";
    
    return 0;
}