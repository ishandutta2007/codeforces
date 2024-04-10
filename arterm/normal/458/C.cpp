#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

#define M 100100
#define T 10001


int n;
vector<int> g[M], s[M];
int tc[4 * M], ts[4 * M];

void read() {
    cin >> n;
    for (int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i < M; ++i) {
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
    }
}

void upd(int v) {
    tc[v] = tc[2 * v] + tc[2 * v + 1];
    ts[v] = ts[2 * v] + ts[2 * v + 1];
}

void add(int v, int l, int r, int pos, int val) {

    tc[v] += pos;
    ts[v] += pos * val;

    if (l + 1 == r)
        return;

    int m = (l + r) / 2;
    if (val < m)
        add(2 * v, l, m, pos, val);
    else
        add(2 * v + 1, m, r, pos, val);
}

int get(int v, int l, int r, int sum) {
    if (sum == 0)
        return 0;

    if (tc[v] == sum)
        return ts[v];

    if (l + 1 == r) {
        return sum * l;
    }

    int m = (l + r) / 2;

    if (sum <= tc[2 * v])
        return get(2 * v, l, m, sum);

    return ts[2 * v] + get(2 * v + 1, m, r, sum - tc[2 * v]);
}

void pre() {
    for (int i = 1; i < M; ++i) {
        for (int j = 0; j < (int) g[i].size(); ++j) {
            s[j + 1].push_back(g[i][j]);
            add(1, 0, T, 1, g[i][j]);
        }  
    }
}

void kill() {
    int st = g[0].size(), ans = 2000000000, sum = 0, bon;
    int k = n;
    while (k >= 0) {
        for (auto & x : s[k]) {
            sum += x;
            st++;
            add(1, 0, T, -1, x);
        }
        bon = (st >= k ? 0 : get(1, 0, T, k - st));
        //cerr << k << "! " << bon << "\n";
        ans = min(ans, sum + bon);
        --k;
    }

    cout << ans << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    pre();
    kill();

    return 0;
}