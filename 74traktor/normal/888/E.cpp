#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[40];
set < int > g[2];
int m;

void work(int l, int r, int h){
    for (int mask = 0; mask <= (1<<(r - l + 1)) - 1; ++mask){
        int sum = 0;
        for (int i = 0; i <= r - l; ++i){
            if ((mask>>i)&1) sum += a[l + i];
        }
        g[h].insert(sum % m);
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    work(1, (n + 1) / 2, 0);
    if ((n + 1) / 2 < n) work((n + 1) / 2 + 1, n, 1);
    int ans = 0;
    for (auto key : g[0]){
        ans = max(ans, key);
        int max_delta = m - key - 1;
        auto it = g[1].upper_bound(max_delta);
        if (it == g[1].begin()) continue;
        it--;
        ans = max(ans, key + (*it));
    }
    for (auto key : g[1]){
        ans = max(ans, key);
        int max_delta = m - key - 1;
        auto it = g[0].upper_bound(max_delta);
        if (it == g[0].begin()) continue;
        it--;
        ans = max(ans, key + (*it));
    }
    cout << ans << '\n';
    return 0;
}