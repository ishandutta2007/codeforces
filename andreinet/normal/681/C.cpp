#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

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
    vector<pair<string, int>> ops;
    priority_queue<int, vector<int>, greater<int>> q;
    while (n-- > 0) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            q.push(x);
            ops.push_back(make_pair(op, x));
        } else if (op == "removeMin") {
            if (q.empty()) {
                ops.push_back(make_pair("insert", 2));
            } else {
                q.pop();
            }
            ops.push_back(make_pair("removeMin", -1));
        } else {
            int x;
            cin >> x;
            while (!q.empty() && q.top() < x) {
                q.pop();
                ops.push_back(make_pair("removeMin", -1));
            }
            if (q.empty() || q.top() != x) {
                q.push(x);
                ops.push_back(make_pair("insert", x));
            }
            ops.push_back(make_pair("getMin", x));
        }
    }

    cout << SZ(ops) << '\n';
    for (const auto& p: ops) {
        cout << p.first;
        if (p.first != "removeMin") {
            cout << ' ' << p.second;
        }
        cout << '\n';
    }
}