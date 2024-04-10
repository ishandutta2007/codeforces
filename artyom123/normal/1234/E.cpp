#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector <int> x(m);
    for (auto &c : x) {
        cin >> c;
    }
    long long ans = 0;
    for (int i = 0; i < m - 1; i++) {
        ans += abs(x[i] - x[i + 1]);
    }
    cout << ans << " ";
    vector <vector<int>> g(n + 1);
    vector <pair<int, int>> p;
    for (int i = 0; i < m - 1; i++) {
        g[x[i]].push_back(x[i + 1]);
        g[x[i + 1]].push_back(x[i]);
        p.push_back({min(x[i], x[i + 1]), max(x[i], x[i + 1])});
    }
    for (auto &c : g) {
        sort(c.begin(), c.end());
    }
    vector <vector<long long>> pr(n + 1);
    for (int i = 0; i <= n; i++) {
        pr[i].resize(g[i].size());
        if (pr[i].size() == 0) {
            continue;
        }
        pr[i][0] = g[i][0];
        for (int j = 1; j < pr[i].size(); j++) {
            pr[i][j] = pr[i][j - 1] + g[i][j];
        }
    }
    int l = 0;
    int cnt = 0;
    vector <int> now(n + 1);
    sort(p.begin(), p.end());
    for (int i = 2; i <= n; i++) {
        while (l < p.size() && p[l].first < i) {
            if (p[l].second <= i) {
                l++;
                continue;
            }
            now[p[l].second]++;
            l++;
            cnt++;
        }
        cnt -= now[i];
        long long tmp = ans;
        tmp -= cnt;
        long long cnt_more = g[i].end() - upper_bound(g[i].begin(), g[i].end(), i);
        tmp += cnt_more * (i - 1);
        long long cnt_less = lower_bound(g[i].begin(), g[i].end(), i) - g[i].begin();
        if (cnt_less > 0) {
            tmp -= cnt_less * i - pr[i][cnt_less - 1];
            tmp += pr[i][cnt_less - 1];
        }
        cout << tmp << " ";
    }
    return 0;
}