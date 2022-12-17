#include <bits/stdc++.h>
using namespace std;

const string day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<bool, 7>> ok(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        while (t--) {
            string s;
            cin >> s;
            ok[i][find(day, day + 7, s) - day] = 1;
        }
    }
    vector<int> h(m);
    for (int &x : h) {
        cin >> x;
    }
    vector nxt(7, vector<int>(m));
    for (int d = 0; d < 7; d++) {
        for (int i = m - 1, j = m - 1; ~i; i--) {
            int t = h[i] / 7 * 7 + d;
            if (t <= h[i]) t += 7;
            while (j >= i && h[j] > t) j--;
            if (j >= i && h[j] == t) nxt[d][i] = nxt[d][j];
            else nxt[d][i] = t;
        }
    }
    vector<int> ptr(7);
    int lst = 0;
    auto get = [&](int i) {
        int ans = INT_MAX;
        for (int d = 0; d < 7; d++) {
            if (!ok[i][d]) continue;
            int t = lst / 7 * 7 + d;
            if (t <= lst) t += 7;
            while (ptr[d] < m && h[ptr[d]] < t) ptr[d]++;
            int mn;
            if (ptr[d] == m || h[ptr[d]] != t) mn = t;
            else mn = nxt[d][ptr[d]];
            ans = min(ans, mn);
        }
        return ans;
    };
    vector<priority_queue<int, vector<int>, greater<>>> cand(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    vector<vector<int>> proj(k);
    vector<queue<pair<int, int>>> proc(n);
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        proj[i].resize(p);
        for (int &x : proj[i]) {
            cin >> x, x--;
        }
        reverse(proj[i].begin(), proj[i].end());
        int j = proj[i].back();
        q.emplace(get(j), j);
        proc[j].emplace(0, i);
    }
    vector<int> res(k), lst_tim(n);
    while (!q.empty()) {
        auto [t, i] = q.top(); q.pop();
        if (lst_tim[i] == t) {
            // if (!cand[i].empty() || !proc[i].empty()) {
            //     q.emplace(get(i), i);
            // }
            continue;
        }
        while (!proc[i].empty() && proc[i].front().first < t) {
            cand[i].push(proc[i].front().second);
            proc[i].pop();
        }
        if (cand[i].empty()) continue;
        lst = lst_tim[i] = t;
        int j = cand[i].top();
        cand[i].pop();
        proj[j].pop_back();
        if (!proj[j].empty()) {
            int k = proj[j].back();
            q.emplace(get(k), k);
            proc[k].emplace(t, j);
        } else {
            res[j] = t;
        }
        if (!cand[i].empty()) {
            q.emplace(get(i), i);
        }
    }
    for (int x : res) {
        cout << x << " ";
    }
    return 0;
}