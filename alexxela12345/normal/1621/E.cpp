#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

ldb key(vector<pair<int, int>> &a) {
    ldb sum = 0;
    int cnt = 0;
    for (auto &[b, c] : a) {
        sum += b;
        cnt++;
    }
    return sum / cnt;
}

int key2(vector<pair<int, int>> &a) {
    ll sum = 0;
    int cnt = 0;
    for (auto &[b, c] : a) {
        sum += b;
        cnt++;
    }
    return int((sum + cnt - 1) / cnt);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    arr.resize(m);
    reverse(arr.begin(), arr.end());
    n = m;
    vector<vector<pair<int, int>>> arr2(n);
    string ans;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        arr2[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> arr2[i][j].first;
            arr2[i][j].second = cur++;
        }
    }
    ans.resize(cur, '?');

    sort(arr2.begin(), arr2.end(), [&](auto a, auto b) {
        return key(a) < key(b);
    });
    vector<int> k2(n);
    for (int i = 0; i < n; i++) {
        k2[i] = key2(arr2[i]);
    }
    vector<int> pref1(n + 1);
    for (int i = 0; i < n; i++) {
        pref1[i + 1] = pref1[i];
        if (key2(arr2[i]) <= arr[i]) {
            pref1[i + 1]++; 
        }
    }
    vector<int> prefl(n + 1);
    for (int i = 1; i < n; i++) {
        prefl[i + 1] = prefl[i];
        if (key2(arr2[i]) <= arr[i - 1])
            prefl[i + 1]++;
    }
    vector<int> prefr(n + 1);
    for (int i = 0; i < n - 1; i++) {
        prefr[i + 1] = prefr[i];
        if (key2(arr2[i]) <= arr[i + 1])
            prefr[i + 1]++;
    }
    prefr.back() = prefr[prefr.size() - 2];
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (auto pp : arr2[i])
            sum += pp.first;
        int sz = arr2[i].size() - 1;
        for (auto pp : arr2[i]) {
            sum -= pp.first;
            int val = (sum + sz - 1) / sz;
            int j = lower_bound(k2.begin(), k2.end(), val) - k2.begin();
            if (i < j)
                j--;

            char &ans2 = ans[pp.second];
            if (i == j) {
                if (pref1[i] == i && val <= arr[i] && pref1[n] - pref1[i + 1] == n - i - 1) {
                    ans2 = '1';
                } else {
                    ans2 = '0';
                }
            } else if (i < j) {
                if (pref1[i] == i && val <= arr[j] && pref1[n] - pref1[j + 1] == n - 1 - j && prefl[j + 1] - prefl[i + 1] == j - i) {
                    ans2 = '1';
                } else {
                    ans2 = '0';
                }
            } else {
                if (pref1[j] == j && val <= arr[j] && pref1[n] - pref1[i + 1] == n - 1 - i && prefr[i] - prefr[j] == i - j) {
                    ans2 = '1';
                } else {
                    ans2 = '0';
                }
            }

            sum += pp.first;
        }
    }
    cout << ans << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}