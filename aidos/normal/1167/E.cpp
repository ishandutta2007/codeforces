#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 2e6 + 10;
const int mod = (int) 1e9 + 7;
int n;
int x;
int a[maxn];
int f[maxn];
int s[maxn];
int p[maxn];
void solve() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i]] = i;
        if(!f[a[i]]) {
            f[a[i]] = i;
        }
        p[i] = max(p[i-1], a[i]);
    }
    int last = n + 5;
    int en = x+1;
    for(int i = x; i >= 1; i--) {
        if(s[i]) {
            if(last < s[i]) break;
            last = f[i];
        }
        en = i;
    }
    last = -1;
    ll ans = 0;

    for(int i = 1; i <= x; i++) {
        int r = max(i, en-1);
        if(last != -1) r = max(r, p[last]);
        ans += x + 1 - r;

        if(f[i]) {
            if(last > f[i]) break;
            last = s[i];
        }
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}