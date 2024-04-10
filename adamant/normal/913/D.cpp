#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, T;
    cin >> n >> T;
    int a[n], t[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> t[i];
    }
    int p[n];
    iota(p, p + n, 0);
    sort(p, p + n, [&](int x, int y) {
        return a[x] > a[y];
    });
    multiset<pair<int, int>> problems;
    int ans = 0, sum = 0, res = 0;
    for(int i = 0; i < n; i++) {
        if(problems.size() && sum + t[p[i]] > T && prev(end(problems))->first > t[p[i]]) {
            sum -= prev(end(problems))->first;
            problems.erase(prev(end(problems)));
        }
        if(sum + t[p[i]] <= T) {
            problems.insert({t[p[i]], p[i]});
            sum += t[p[i]];
        }
        if(min(a[p[i]], (int)problems.size()) > ans) {
            ans = min(a[p[i]], (int)problems.size());
            res = i;
        }
    }
    cout << ans << endl;
    problems.clear();
    sum = 0;
    for(int i = 0; i < n; i++) {
        if(problems.size() && sum + t[p[i]] > T && prev(end(problems))->first > t[p[i]]) {
            sum -= prev(end(problems))->first;
            problems.erase(prev(end(problems)));
        }
        if(sum + t[p[i]] <= T) {
            problems.insert({t[p[i]], p[i]});
            sum += t[p[i]];
        }
        if(res == i) {
            cout << problems.size() << endl;
            for(auto it: problems) {
                cout << it.second + 1 << ' ';
            }
            return 0;
        }
    }
    return 0;
}