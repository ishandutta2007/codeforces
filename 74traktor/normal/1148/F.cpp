#include <bits/stdc++.h>

using namespace std;

#define int long long
vector < pair < int, int > > g[65];
int sum = 0;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, v, m;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> v >> m;
        sum += v;
        int last = 0;
        for (int j = 0; j < 63; ++j){
            if ((m&(1ll<<j)) > 0) last = j;
        }
        g[last].push_back({m, v});
    }
    int ans = 0;
    for (int i = 0; i < 63; ++i){
        int check = 0;
        for (auto key : g[i]){
            int x = (key.first&ans);
            int cnt = 0;
            for (int j = 0; j < 63; ++j){
                if ((x&(1ll<<j)) > 0) cnt++;
            }
            if (cnt % 2) check -= key.second;
            else check += key.second;
        }
        if (check > 0 && sum > 0) ans += (1ll<<i);
        else if (check < 0 && sum < 0) ans += (1ll<<i);
    }
    cout << ans << '\n';
    return 0;
}