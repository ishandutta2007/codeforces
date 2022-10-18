#include <bits/stdc++.h>

using namespace std;

#define int long long

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    vector < pair < int, int > > a;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        int t = (int)sqrt(x);
        int w = t + 1;
        a.push_back({min(w * w - x, x - t * t), x});
    }
    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; ++i){
        ans += a[i].first;
    }
    for (int i = n / 2; i < n; ++i){
        if (a[i].first != 0) break;
        if (a[i].second == 0) ans += 2;
        else ans += 1;
    }
    cout << ans << '\n';
    return 0;
}