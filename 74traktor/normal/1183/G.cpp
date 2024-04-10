#include <bits/stdc++.h>

using namespace std;

#define int long long
int cnt[200005];
int cur[200005];
int f[200005];
vector < int > add[200005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n, x, y;
    cin >> q;
    for (int i = 1; i <= q; ++i){
        cin >> n;
        for (int j = 1; j <= n; ++j) cnt[j] = 0, cur[j] = 0, f[j] = 0, add[j] = {};
        for (int j = 1; j <= n; ++j){
            cin >> x >> y;
            cnt[x]++;
            f[x] += y;
        }
        for (int j = 1; j <= n; ++j) cur[cnt[j]]++, add[cnt[j]].push_back(f[j]);
        int ans = 0, sum = 0;
        multiset < int > Q;
        for (int j = n; j >= 1; --j){
            for (auto key : add[j]) Q.insert(key);
            if ((int)Q.size()){
                ans += j;
                sum += min((*Q.rbegin()), j);
                Q.erase(Q.find((*Q.rbegin())));
            }
        }
        cout << ans << " " << sum << '\n';
    }
    return 0;
}