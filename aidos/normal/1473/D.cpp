#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = (int)200200;
const int inf = (1<<30);
int n, m;
string s;
int sum[maxn];
int max_suf[maxn];
int min_suf[maxn];

int max_pref[maxn];
int min_pref[maxn];
void solve() {
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i-1];
        if(s[i-1] == '-') sum[i]--;
        else sum[i]++;
    }
    max_suf[n+1] = -inf;
    min_suf[n+1] = inf;
    for(int i = n; i >= 1; i--) {
        max_suf[i] = max(max_suf[i+1], sum[i]);
        min_suf[i] = min(min_suf[i+1], sum[i]);
    }
    for(int i = 1; i <= n; i++) {
        max_pref[i] = max(max_pref[i-1], sum[i]);
        min_pref[i] = min(min_pref[i-1], sum[i]);
    }
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        if(r == n) {
            cout << max_pref[l-1] - min_pref[l-1] + 1 << "\n";
        } else {
            int mx = max(max_pref[l-1], sum[l-1] + max_suf[r + 1] - sum[r]);
            int mi = min(min_pref[l-1], sum[l-1] + min_suf[r + 1] - sum[r]);
            cout << mx - mi + 1 << "\n";
        }
    }
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}