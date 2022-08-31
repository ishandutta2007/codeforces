#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

int t[91];

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, x;
    cin >> n;    
    for (int i = 0; i < n; i++) {
        cin >> x;
        t[x] = 1;
    }
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= 90; i++) {
        ans++;
        if (t[i]) {
            cur = 0;
        } else {
            cur++;
        }
        if (cur >= 15) {
            break;
        }
    }
    cout << ans << endl;
}