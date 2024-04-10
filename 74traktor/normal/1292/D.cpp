#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int cnt[5005], bad[5005];
int pref[5005];
int go[5005];
ll inf = 1e18;
int good[5005][5005];
vector < int > lst[5005];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        x = max(x, 1);
        cnt[x]++;
    }
    vector < int > primes;
    for (int i = 2; i <= 5000; ++i) {
        int j = 2, x = i;
        while (j * j <= x) {
            if (x % j == 0) pref[i]++, x /= j, good[i][j]++;
            else ++j;
        }
        if (x == i) primes.push_back(i);
        if (x != 1) pref[i]++, good[i][x]++;
        pref[i] += pref[i - 1];
        for (int j = 1; j <= 5000; ++j) good[i][j] += good[i - 1][j];
        for (int j = 1; j <= 5000; ++j) if (good[i][j] > 0) lst[i].push_back(j);
    }
    for (int i = 1; i <= 5000; ++i) ans += (ll)cnt[i] * (ll)pref[i];
    int imin = 5005;
    int sum_bad = 0;
    set < int > Q;
    for (int i = 1; i <= 5000; ++i) {
        if (cnt[i] != 0) Q.insert(i);
    }
    while (1) {
        ll MX = inf;
        int to = -1;
        for (auto key : primes) {
            if (key <= imin) {
                ll was = ans + (ll)sum_bad;
                for (auto i : Q) {
                    int checks = 0;
                    if ((int)lst[i].size() != 0 && lst[i].back() > key) checks = 1;
                    if (checks || good[i][key] == 0) was += (ll)cnt[i];
                    else was -= (ll)cnt[i];
                }
                if (was < MX) MX = was, to = key;
            }
            else break;
        }
        if (MX >= ans) {
            cout << ans << '\n';
            return 0;
        }
        ans = MX;
        go[to]++, imin = to;
        vector < int > dels;
        for (auto i : Q) {
            int checks = 0;
            if ((int)lst[i].size() != 0 && lst[i].back() > to) checks = 1;
            if (!(checks || good[i][to] == 0)) {
                good[i][to]--;
                if (good[i][to] == 0) lst[i].pop_back();
            }
            else {
                sum_bad += cnt[i];
                dels.push_back(i);
            }
        }
        for (auto key : dels) Q.erase(key);
    }
    return 0;
}