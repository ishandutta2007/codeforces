#include <bits/stdc++.h>
#define int long long
using namespace std;
int time2 = 0;
vector <int> p;
vector <vector <int>> a;
vector <int> used;
vector <pair <int, int>> time1;
vector <vector <int>> bp;
vector <int> gl;
vector <vector <int>> gl1;

void dfs1(int v) {
    used[v] = 1;
    ++time2;
    time1[v].first = time2;
    for (int i = 0; i < a[v].size(); ++i) {
        if (!used[a[v][i]]) {
            gl[a[v][i]] = gl[v] + 1;
            dfs1(a[v][i]);
        }
    }
    ++time2;
    time1[v].second = time2;
}

int parent(int v, int k) {
    for (int i = 24; i >= 0; --i) {
        if (k >= (1 << i)) {
            v = bp[v][i];
            k -= (1 << i);
        }
    }
    return v;//
}

int binary_search1(int i, int x) {
    int l = -1, r = gl1[i].size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (gl1[i][m] >= x) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return r;
}

int binary_search2(int i, int x) {
    int l = -1, r = gl1[i].size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (gl1[i][m] <= x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return l;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    p.resize(n + 1);
    p[n] = n;
    a.resize(n);
    used.resize(n);
    time1.resize(n);
    bp.resize(n + 1);
    gl.resize(n);
    gl1.resize(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            p[i] = n;
        }
        else {
            p[i] = tmp - 1;
            a[i].push_back(tmp - 1);
            a[tmp - 1].push_back(i);
        }
    }
    for (int i = 0; i < n + 1; ++i) {
        bp[i].resize(25);
    }
    for (int i = 0; i < 25; ++i) {
        bp[n][i] = n;
    }
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0) {
                bp[j][i] = p[j];
            }
            else {
                bp[j][i] = bp[bp[j][i - 1]][i - 1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (p[i] == n) {
            gl[i] = 0;
            dfs1(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        gl1[gl[i]].push_back(time1[i].first);
    }
    for (int i = 0; i < n; ++i) {
        sort(gl1[i].begin(), gl1[i].end());
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int v, k;
        cin >> v >> k;
        --v;
        v = parent(v, k);
        if (v == n) {
            cout << 0 << " ";
        }
        else {
            int l = binary_search1(gl[v] + k, time1[v].first);
            int r = binary_search2(gl[v] + k, time1[v].second);
            cout << max((int)0, r - l) << " ";
        }
    }
}