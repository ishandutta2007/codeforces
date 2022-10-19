#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cassert>
#include <array>

using namespace std;
#define int long long
vector <vector <int>> g;
vector <int> cnt1, cnt2, sum1, sum2, w;

void dfs1(int v, int p) {
    ++cnt1[v];
    sum2[v] = 1;
    for (int i : g[v]) {
        if (i == p) continue;
        dfs1(i, v);
        cnt1[v] += cnt2[i];
        sum1[v] += sum2[i];
        ++sum1[v];
        if (make_pair(cnt1[i], -sum1[i]) > make_pair(cnt2[i], -sum2[i])) {
            cnt2[v] += cnt1[i];
            sum2[v] += sum1[i] + 1;
        } else {
            cnt2[v] += cnt2[i];
            sum2[v] += sum2[i];
        }
    }
}

void calc1(int v, int p);

void calc2(int v, int p) {
    w[v] = 1;
    for (int i : g[v]) {
        if (i == p) continue;
        if (make_pair(cnt1[i], -sum1[i]) > make_pair(cnt2[i], -sum2[i])) {
            calc1(i, v);
        } else {
            calc2(i, v);
        }
    }
}

void calc1(int v, int p) {
    if (p != -1) w[v] = 1;
    for (int i : g[v]) {
        if (i == p) continue;
        w[v]++;
        calc2(i, v);
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (n == 2) {
        cout << "2 2\n1 1";
        return 0;
    }
    cnt1.resize(n);
    cnt2.resize(n);
    sum1.resize(n);
    sum2.resize(n);
    w.resize(n);
    dfs1(0, -1);
    if (make_pair(cnt1[0], -sum1[0]) > make_pair(cnt2[0], -sum2[0])) {
        cout << cnt1[0] << " " << sum1[0] << "\n";
        calc1(0, -1);
    } else {
        cout << cnt2[0] << " " << sum2[0] << "\n";
        calc2(0, -1);
    }
    for (int i = 0; i < n; ++i) cout << w[i] << " ";
}

/*

 */