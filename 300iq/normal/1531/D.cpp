#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e5 + 20;

pair <string, int> ans[4 * N][2];
string str[N];

void calc_leaf(int v, int i) {
    if (str[i] == "lock") {
        ans[v][0] = ans[v][1] = {"", 1};
    } else if (str[i] == "unlock") {
        ans[v][0] = ans[v][1] = {"", 0};
    } else {
        ans[v][0] = {str[i], 0};
        ans[v][1] = {"", 1};
    }
}

void recalc(int v) {
    for (int i = 0; i < 2; i++) {
        auto l = ans[v * 2 + 1][i];
        auto r = ans[v * 2 + 2][l.second];
        string ans_string = (r.first == "" ? l.first : r.first);
        int ans_type = r.second;
        ans[v][i] = {ans_string, ans_type};
    }
}

void upd(int v, int l, int r, int i) {
    if (r - l == 1) {
        calc_leaf(v, l);
    } else {
        int m = (l + r) / 2;
        if (i < m) {
            upd(v * 2 + 1, l, m, i);
        } else {
            upd(v * 2 + 2, m, r, i);
        }
        recalc(v);
    }
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        calc_leaf(v, l);
    } else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        recalc(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> str[i];
    build(0, 0, n);
    int t;
    cin >> t;
    auto ret = ans[0][0];
    if (ret.first == "") cout << "blue\n";
    else cout << ret.first << '\n';
    while (t--) {
        int i;
        cin >> i;
        string s;
        cin >> s;
        i--;
        str[i] = s;
        upd(0, 0, n, i);
        auto ret = ans[0][0];
        if (ret.first == "") cout << "blue\n";
        else cout << ret.first << '\n';
    }
}