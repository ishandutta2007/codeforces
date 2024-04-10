#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define int ll

vector<vector<int>> arr;

map<int, int> ans, pref2, sum2, suf2;

int get_suf(int i) {
    if (suf2.count(i)) {
        return suf2[i];
    }
    vector<int> pref(arr[i].size() + 1);
    for (int j = 1; j < pref.size(); j++) {
        pref[j] = arr[i][j - 1] + pref[j - 1];
    }
    int max_ans = LLONG_MIN;
    for (int j = 0; j < (int) arr[i].size(); j++) {
        max_ans = max(max_ans, pref.back() - pref[j]); 
    }
    return suf2[i] = max_ans;
}

int get_sum(int i) {
    if (sum2.count(i))
        return sum2[i];
    int ans = 0;
    for (int el : arr[i])
        ans += el;
    sum2[i] = ans;
    return ans;
}

int get_ans(int i) {
    if (ans.count(i))
        return ans[i];
    vector<int> pref(arr[i].size() + 1);
    for (int j = 1; j < pref.size(); j++) {
        pref[j] = arr[i][j - 1] + pref[j - 1];
    }
    int ans2 = arr[i][0];
    int mn = 0;
    for (int i = 1; i < pref.size(); i++) {
        ans2 = max(ans2, pref[i] - mn);
        mn = min(mn, pref[i]);
    }
    return ans[i] = ans2;;
}

int get_pref(int i) {
    if (pref2.count(i))
        return pref2[i];
    vector<int> pref(arr[i].size() + 1);
    for (int j = 1; j < pref.size(); j++) {
        pref[j] = arr[i][j - 1] + pref[j - 1];
    }
    int ans = arr[i][0];
    int mn = 0;
    for (int i = 1; i < pref.size(); i++) {
        ans = max(ans, pref[i]);
        mn = min(mn, pref[i]);
    }
    return pref2[i] = ans;
}


void solve() {
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        arr[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> arr[i][j];
    }
    ll max_ans = LLONG_MIN;
    int best_left = 0;
    vector<int> inds(m);
    for (int i = 0; i < m; i++) {
        cin >> inds[i];
        inds[i]--;
    }
    for (auto i : inds) {
        max_ans = max(max_ans, get_ans(i));
        max_ans = max(max_ans, best_left + get_pref(i));
        best_left = max(best_left + get_sum(i), get_suf(i));
    }
    cout << max_ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}