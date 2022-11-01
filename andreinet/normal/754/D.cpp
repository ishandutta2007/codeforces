#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> left(n), right(n);
    vector<pair<int, int>> ins, outs;
    vector<int> all;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        all.push_back(l);
        all.push_back(r);
        ins.push_back(make_pair(l, i));
        outs.push_back(make_pair(r, i));
        left[i] = l;
        right[i] = r;
    }
    sort(ins.begin(), ins.end());
    sort(outs.begin(), outs.end());

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    int iIndOut = 0, jInd = 0;
    multiset<int> sj;
    int ans = 0;
    for (int i = 0, j = 0; i < SZ(all); ++i) {
        while (iIndOut < n && outs[iIndOut].first < all[i]) {
            int p = outs[iIndOut++].second;
            auto it = sj.find(p);
            if (it != sj.end()) {
                sj.erase(it);
            }
        }
        while (jInd < n && ins[jInd].first <= all[j]) {
            int p = ins[jInd++].second;
            if (right[p] >= all[i]) {
                sj.insert(p);
            }
        }
        while (j < i && SZ(sj) < k) {
            j++;
            while (jInd < n && ins[jInd].first <= all[j]) {
                int p = ins[jInd++].second;
                if (right[p] >= all[i]) {
                    sj.insert(p);
                }
            }
        }
        if (SZ(sj) >= k) {
            ans = max(ans, all[i] - all[j] + 1);
        }
    }
    sj.clear();
    iIndOut = 0;
    jInd = 0;
    vector<int> fans;
    for (int i = 0, j = 0; i < SZ(all); ++i) {
        while (iIndOut < n && outs[iIndOut].first < all[i]) {
            int p = outs[iIndOut++].second;
            auto it = sj.find(p);
            if (it != sj.end()) {
                sj.erase(it);
            }
        }
        while (jInd < n && ins[jInd].first <= all[j]) {
            int p = ins[jInd++].second;
            if (right[p] >= all[i]) {
                sj.insert(p);
            }
        }
        while (j < i && SZ(sj) < k) {
            j++;
            while (jInd < n && ins[jInd].first <= all[j]) {
                int p = ins[jInd++].second;
                if (right[p] >= all[i]) {
                    sj.insert(p);
                }
            }
        }
        if (SZ(sj) >= k && ans == all[i] - all[j] + 1) {
            fans = vector<int>(sj.begin(), sj.end());
            break;
        }
    }
    fans.resize(k);

    cout << ans << '\n';
    if (ans == 0) {
        for (int i = 1; i <= k; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        for (int p: fans) {
            cout << p + 1 << ' ';
        }
        cout << '\n';
    }
}