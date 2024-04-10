#include <bits/stdc++.h>

using namespace std;

#define int long long
int mod = 998244353;
int const maxn = 3e5 + 5;
int cnt[maxn];
int inf = 1e18;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector < pair < int, int > > Q;
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        Q.push_back({a, b});
    }
    sort(Q.begin(), Q.end());
    cnt[1] = 1;
    for (int i = 2; i <= n; ++i) {
        cnt[i] = cnt[i - 1] * i % mod;
    }
    int cur = 1, tmp1 = 1;
    for (int j = 1; j < n; ++j) {
        if (Q[j].first == Q[j - 1].first) cur++;
        else {
            tmp1 = tmp1 * cnt[cur] % mod;
            cur = 1;
        }
    }
    tmp1 = tmp1 * cnt[cur] % mod;
    int tmp2 = 1;
    cur = 1;
    for (int i = 0; i < n; ++i) {
        pair < int, int > copies = Q[i];
        Q[i] = {copies.second, copies.first};
    }
    sort(Q.begin(), Q.end());
    for (int j = 1; j < n; ++j) {
        if (Q[j].first == Q[j - 1].first) cur++;
        else {
            tmp2 = tmp2 * cnt[cur] % mod;
            cur = 1;
        }
    }
    tmp2 = tmp2 * cnt[cur] % mod;
    int tmp3 = 1, last = -1 * inf;
    vector < int > used;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || Q[i].first == Q[i - 1].first) used.push_back(Q[i].second);
        else {
            sort(used.begin(), used.end());
            if (used[0] < last) tmp3 = 0;
            cur = 1;
            for (int j = 1; j < (int)used.size(); ++j) {
                if (used[j] == used[j - 1]) cur++;
                else {
                    tmp3 = tmp3 * cnt[cur] % mod;
                    cur = 1;
                }
            }
            tmp3 = tmp3 * cnt[cur] % mod;
            last = used.back();
            used = {Q[i].second};
        }
    }
    sort(used.begin(), used.end());
    if (used[0] < last) tmp3 = 0;
    cur = 1;
    for (int j = 1; j < (int)used.size(); ++j) {
        if (used[j] == used[j - 1]) cur++;
        else {
            tmp3 = tmp3 * cnt[cur] % mod;
            cur = 1;
        }
    }
    //cout << cnt[n] << " " << tmp1 << " " << tmp2 << " " << tmp3 << '\n';
    tmp3 = tmp3 * cnt[cur] % mod;
    cout << (cnt[n] - tmp1 - tmp2 + tmp3 + 7 * mod) % mod;
    return 0;
}