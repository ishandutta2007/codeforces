#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[100005];
int b[100005];
unordered_map < int, int > use;

main(){
    //freopen("input.txt", "r");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, sum = 0;
    cin >> n >> m;
    set < int > Q;
    int imax = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
        use[a[i]] += (m - 1);
        imax = max(imax, a[i]);
        Q.insert(a[i]);
    }
    for (int j = 1; j <= m; ++j) cin >> b[j];
    for (int j = 1; j <= m; ++j){
        if (b[j] < imax){
            cout << -1 << '\n';
            return 0;
        }
    }
    int ans = sum * m;
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= m; ++i){
        if (Q.find(b[i]) != Q.end()) continue;
        auto it = Q.upper_bound(b[i]);
        if (it == Q.begin()){
            cout << -1 << '\n';
            return 0;
        }
        it--;
        ans += (b[i] - (*it));
        use[(*it)]--;
        if (use[(*it)] == 0) Q.erase((*it));
    }
    cout << ans << '\n';
    return 0;
}