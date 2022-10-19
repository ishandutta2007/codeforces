#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int>> a;
vector <bool> used;
vector <int> p;
pair <int, int> dfs(int v) {
    int flag = 0;
    used[v] = true;
    pair <int, int> now = {0, v};
    for (int i : a[v]) {
        if (!used[i]) {
            p[i] = v;
            pair <int, int> tmp = dfs(i);
            if (tmp.first >= now.first) {
                now = tmp;
            }
            flag = 1;
        }
    }
    return {now.first + flag, now.second};
}

signed main() {
    int n;
    cin >> n;
    a.resize(n);
    used.resize(n);
    p.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int o, k;
        cin >> o >> k;
        a[o - 1].push_back(k - 1);
        a[k - 1].push_back(o - 1);
    }
    int a1 = dfs(0).second;
    used.assign(n, false);
    pair <int, int> tmp1 = dfs(a1);
    int b1 = tmp1.second;
    used.assign(n, false);
    int now = b1;
    int c = -1, ans = 0;
    used[now] = true;
    while (now != a1) {
        used[p[now]] = true;
        pair <int, int> tmp = dfs(now);
        if (tmp.first > ans) {
            ans = tmp.first;
            c = tmp.second;
        }
        now = p[now];
    }
    if (c == -1) {
        for (int i = 0; i < n; ++i) {
            if (i != a1 && i != b1) {
                c = i;
                break;
            }
        }
    }
    cout << tmp1.first + ans << "\n" << a1 + 1 << " " << b1 + 1 << " " << c + 1;
    return 0;
}