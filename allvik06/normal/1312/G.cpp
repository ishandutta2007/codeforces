#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <iomanip>
#include <array>
#include <deque>
#include <cmath>
#include <complex>
#include <queue>
#include <iomanip>

using namespace std;
const int INF = 1e9;

struct node {
    map <char, int> nxt;
    int cnt_term = 0, ind = -1, dp = INF;
};

vector <node> all;

void dfs(int v) {
    if (all[v].ind != -1) all[v].cnt_term = 1;
    for (auto i : all[v].nxt) {
        dfs(i.second);
        all[v].cnt_term += all[i.second].cnt_term;
    }
}

void calc_dp(int v, int mn) {
    if (all[v].ind != -1) all[v].dp = min(all[v].dp, mn + 1);
    int cnt = (all[v].ind != -1);
    for (auto i : all[v].nxt) {
        all[i.second].dp = all[v].dp + 1;
        calc_dp(i.second, min(mn, all[v].dp) + cnt);
        cnt += all[i.second].cnt_term;
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, k;
    cin >> n;
    all.emplace_back();
    for (int i = 1; i <= n; ++i) {
        int p;
        char c;
        cin >> p >> c;
        all[p].nxt[c] = (int)all.size();
        all.emplace_back();
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        all[x].ind = i;
    }
    dfs(0);
    all[0].dp = 0;
    calc_dp(0, INF);
    vector <int> ans(k);
    for (int i = 1; i <= n; ++i) {
        if (all[i].ind != -1) ans[all[i].ind] = all[i].dp;
    }
    for (int i : ans) cout << i << " ";
}

/*

 */