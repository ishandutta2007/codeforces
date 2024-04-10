#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int a[maxn], t[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> t[i];
    multiset < pair < int, int > > Q;
    for (int i = 1; i <= n; ++i) Q.insert({t[i], a[i]});
    set < pair < int, int > > T;
    while ((int)Q.size() > 0) {
        auto p = (*Q.rbegin());
        Q.erase(Q.find(p));
        pair < int, int > cur = {p.second + 1, -1};
        auto it = T.upper_bound(cur);
        if (it == T.begin()) {
            T.insert({p.second, p.second});
            continue;
        }
        it--;
        int L = (*it).first, R = (*it).second;
        if (R < p.second) {
            T.insert({p.second, p.second});
            continue;
        }
        vector < pair < int, int > > dels;
        while (1) {
            dels.push_back((*it));
            if (it == T.end()) break;
            it++;
            if ((*it).first - 1 != R) {
                break;
            }
            R = (*it).second;
        }
        for (auto key : dels) T.erase(key);
        T.insert({L, R + 1});
        ans += (R + 1 - p.second) * p.first;
    }
    cout << ans << '\n';
    return 0;
}