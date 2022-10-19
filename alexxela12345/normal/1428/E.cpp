#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long

int cut(int x, int n) {
    int lowest = x / n;
    int highest = lowest + 1;
    int cnthighest = x % n;
    int cntlowest = n - cnthighest;
    return lowest * lowest * cntlowest + highest * highest * cnthighest;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == k) {
        int ans = 0;
        for (int &el : a) {
            ans += el * el;;
        }
        cout << ans << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    vector<int> cnt(n, 1);
    set<pair<int, int>> ss;
    for (int i = 0; i < n; i++) {
        if (a[i] != 1) {
            ss.insert({cut(a[i], 2) - cut(a[i], 1), i});
        }
    }
    int need = k - n;
    while (need) {
        need--;
        auto pp = *ss.begin();
        ss.erase(ss.begin());
        cnt[pp.second]++;
        if (cnt[pp.second] != a[pp.second]) {
            ss.insert({cut(a[pp.second], cnt[pp.second] + 1) - cut(a[pp.second], cnt[pp.second]), pp.second});
        }
    }
    /*  while (true) {
        bool was = 0;
        for (int i = 0; i < n - 1; i++) {
            while (cnt[i] > 1 && cnt[i + 1] != a[i + 1] && cut(a[i], cnt[i]) + cut(a[i + 1], cnt[i + 1]) > cut(a[i], cnt[i] - 1) + cut(a[i + 1], cnt[i + 1] + 1)) {
               cnt[i]--;
               cnt[i + 1]++;
               was = 1;
            }
        }
        for (int i = n - 1; i > 0; i--) {
            while (cnt[i] > 1 && cnt[i - 1] != a[i - 1] && cut(a[i], cnt[i]) + cut(a[i - 1], cnt[i - 1]) > cut(a[i], cnt[i] - 1) + cut(a[i - 1], cnt[i - 1] + 1)) {
                cnt[i]--;
                cnt[i - 1]++;
                was = 1;
            }
        }
        if (!was)
            break;
    }*/
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cut(a[i], cnt[i]);
    }
    cout << ans << endl;
}