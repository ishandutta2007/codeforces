#include <bits/stdc++.h>

using namespace std;

int p[105];
int s[105];
int cnt[105];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i){
        cin >> s[i];
        cnt[s[i]] = max(cnt[s[i]], p[i]);
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i){
        int x;
        cin >> x;
        if (cnt[s[x]] != p[x]) ans++;
    }
    cout << ans << '\n';
    return 0;
}