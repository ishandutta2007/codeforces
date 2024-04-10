#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define right _right
#define left _left
using namespace std;

typedef unsigned long long ll;

mt19937 rnd(228);

const int N = 2e5 + 10;

int dsu[N];
int first[N];
set <int> right[N], left[N];
int last[N];


int get(int v) {
    if (v == dsu[v]) return v;
    else return dsu[v] = get(dsu[v]);
}

void uni(int u, int v) {
    u = get(u), v = get(v);
    if (u == v) return;
    if (right[u].size() + left[u].size() < right[v].size() + left[v].size()) swap(u, v);
    last[u] = max(last[u], last[v]);
    first[u] = min(first[u], first[v]);
    dsu[v] = u;
    for (auto c : left[v]) {
        left[u].insert(c);
    }
    for (auto c : right[v]) {
        right[u].insert(c);
    }
}


int main() {
    //freopen("a.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    set <int> sicks;
    for (int i = 0; i <= n; i++) dsu[i] = i, last[i] = i, sicks.insert(i), first[i] = i;
    vector <char> sick(n, true);
    vector <char> def_sick(n, false);
    auto dope = [&] (int l, int r) {
        auto it = sicks.lower_bound(l);
        if (it == prev(sicks.end()) || *next(it) > r) {
            def_sick[*it] = true;
        }
    };
    auto check = [&] (int l, int r) {
        if (sick[l]) {
            if (!left[l].empty())
                dope(*left[l].rbegin(), l);
            if (!right[l].empty())
                dope(l, *right[l].begin());
            return;
        }
        int x = get(l);
        l = first[x], r = last[x];
        while (!right[x].empty() && *right[x].begin() <= r) {
            right[x].erase(right[x].begin());
        }
        while (!left[x].empty() && *left[x].rbegin() >= l) {
            left[x].erase(--left[x].end());
        }
        if (!right[x].empty()) {
            dope(l, *right[x].begin());
        }
        if (!left[x].empty()) {
            dope(*left[x].rbegin(), r);
        }
    };
    auto kill = [&] (int l, int r) {
        auto it = sicks.lower_bound(l);
        while (it != sicks.end() && *it <= r) {
            sick[*it] = false;
            if (*it - 1 >= 0 && !sick[*it - 1]) uni(*it, *it - 1);
            if (*it + 1 < n && !sick[*it + 1]) uni(*it, *it + 1);
            sicks.erase(*it);
            it = sicks.lower_bound(l);
        }
        check(l, r);
    };
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            if (x == 0) {
                kill(l, r);
            } else {
                left[get(r)].insert(l);
                right[get(l)].insert(r);
                check(l, last[get(l)]);
            }
        } else {
            int id;
            cin >> id;
            id--;
            if (!sick[id]) cout << "NO\n";
            else if (def_sick[id]) cout << "YES\n";
            else cout << "N/A\n";
        }
    }
}