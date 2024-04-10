#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 5e5 + 5;
int a[maxn], out[maxn];
int pref_ans[maxn], suff_ans[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0, pos = 1, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector < pair < int, int > > Q;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            sum += a[i], Q.push_back({a[i], 1});
        }
        else {
            sum += a[i];
            int cnt = 1;
            while ((int)Q.size() > 0 && a[i] <= Q.back().first) {
                cnt += Q.back().second;
                sum -= Q.back().second * (Q.back().first - a[i]);
                Q.pop_back();
            }
            Q.push_back({a[i], cnt});
        }
        pref_ans[i] = sum;
    }
    sum = 0;
    Q = {};
    for (int i = n; i >= 1; --i) {
        if (i == n) {
            sum += a[i], Q.push_back({a[i], 1});
        }
        else {
            sum += a[i];
            int cnt = 1;
            while ((int)Q.size() != 0 && a[i] <= Q.back().first) {
                cnt += Q.back().second;
                sum -= Q.back().second * (Q.back().first - a[i]);
                Q.pop_back();
            }
            Q.push_back({a[i], cnt});
        }
        suff_ans[i] = sum;
    }
    for (int i = 1; i <= n; ++i) {
        int cur = pref_ans[i] + suff_ans[i] - a[i];
        if (cur > ans) {
            ans = cur, pos = i;
        }
    }
    int x = a[pos];
    for (int i = pos; i >= 1; --i) {
        x = min(x, a[i]);
        out[i] = x;
    }
    x = a[pos];
    for (int i = pos; i <= n; ++i) {
        x = min(x, a[i]);
        out[i] = x;
    }
    for (int i = 1; i <= n; ++i) cout << out[i] << " ";
    return 0;
}