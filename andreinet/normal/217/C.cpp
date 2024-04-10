#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

struct Table {
    bool can0, can1, canv;
    bool dp[2];
};

Table combine(const Table& left, const Table& right, char op) {
    bool can0, can1, canv;
    bool dp[2] = {false, false};
    if (op == '&') {
        can0 = left.can0 || right.can0 ||
            (left.canv && right.canv);
        can1 = left.can1 && right.can1;
        canv = (left.can1 && right.canv) || 
            (left.canv && right.can1) ||
            (left.canv && right.canv);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                dp[i & j] |= left.dp[i] & right.dp[j];
            }
        }
    } else if (op == '|') {
        can0 = left.can0 && right.can0;
        can1 = left.can1 || right.can1 || (left.canv && right.canv);
        canv = (left.can0 && right.canv) ||
            (left.canv && right.can0) || 
            (left.canv && right.canv);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                dp[i | j] |= left.dp[i] & right.dp[j];
            }
        }
    } else if (op == '^') {
        can0 = (left.can0 && right.can0) ||
            (left.can1 && right.can1) ||
            (left.canv && right.canv);
        can1 = (left.can1 && right.can0) ||
            (left.can0 && right.can1) || 
            (left.canv && right.canv);
        canv = (left.canv && (right.can0 || right.can1)) ||
            (right.canv && (left.can0 || left.can1));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                dp[i ^ j] |= left.dp[i] & right.dp[j];
            }
        }
    } else {
        throw;
    }
    return Table{can0, can1, canv, {dp[0], dp[1]}};
}

pair<Table, int> eval(const string& s, int index) {
    if (s[index] == '0') {
        return make_pair(Table{true, false, false, {true, false}}, index + 1);
    } else if (s[index] == '1') {
        return make_pair(Table{false, true, false, {false, true}}, index + 1);
    } else if (s[index] == '?') {
        return make_pair(Table{false, false, true, {true, true}}, index + 1);
    } else if (s[index] == '(') {
        Table left;
        tie(left, index) = eval(s, index + 1);
        char op = s[index];
        Table right;
        tie(right, index) = eval(s, index + 1);
        return make_pair(combine(left, right, op), index + 1);
    } else {
        throw;
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    Table v = eval(s, 0).first;
    if (v.canv && v.dp[0] && v.dp[1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}