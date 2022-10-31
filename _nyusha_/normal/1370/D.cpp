#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn], good[maxn], pref[maxn], suff[maxn];
pair < int, int > b[maxn];

inline int oks(int n, int k, int x) {
    for (int i = 1; i <= n; ++i) good[i] = 0;
    for (int i = 1; i <= n; ++i) {
        if (b[i].first <= x) good[b[i].second] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1];
        if (good[i]) {
            pref[i] = max(pref[i], 1);
            if (i >= 2) pref[i] = max(pref[i], pref[i - 2] + 2);
        }
    }
    for (int i = n; i >= 1; --i) {
        suff[i] = suff[i + 1];
        if (good[i]) {
            suff[i] = max(suff[i], 1);
            if (i + 1 <= n) suff[i] = max(suff[i], suff[i + 2] + 2);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= x) {
            if (pref[i - 1] + 1 + suff[i + 1] >= k) return 1;
        }
    }
    return 0;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) b[i] = {a[i], i};
    sort(b + 1, b + n + 1);
    set < int > Q;
    for (int i = 1; i <= n; ++i) Q.insert(a[i]);
    vector < int > t;
    for (auto key : Q) t.push_back(key);
    int lef = -1, righ = (int)t.size();
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (oks(n, k, t[mid])) righ = mid;
        else lef = mid;
    }
    cout << t[righ];
    return 0;
}