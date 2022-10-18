#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];
map < int, int > L, R, cnt;
map < int, vector < int > > pos;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, ans;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        L.clear(), R.clear(), pos.clear(), cnt.clear();
        set < int > Q;
        for (int i = 1; i <= n; ++i) {
            pos[a[i]].push_back(i);
            cnt[a[i]]++;
            Q.insert(a[i]);
            if (L.find(a[i]) == L.end()) L[a[i]] = i;
            R[a[i]] = i;
        }
        vector < int > T;
        for (auto key : Q) T.push_back(key);
        for (int i = 0; i < (int)T.size();) {
            int sum = cnt[T[i]], d = R[T[i]], lef = i;
            i++;
            while (i < (int)T.size() && L[T[i]] > d) {
                sum += cnt[T[i]];
                d = R[T[i]];
                ++i;
            }
            if (lef > 0) {
                int lst = T[lef - 1];
                sum += (lower_bound(pos[lst].begin(), pos[lst].end(), L[T[lef]]) -  pos[lst].begin());
            }
            if (i != (int)T.size()) {
                int nxt = T[i];
                int start = lower_bound(pos[nxt].begin(), pos[nxt].end(), d) - pos[nxt].begin();
                sum += ((int)pos[nxt].size() - start);
            }
            ans = min(ans, n - sum);
        }
        cout << ans << '\n';
    }
    return 0;
}