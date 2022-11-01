#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
#ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> a;
    string s;
    cin >> s;

    vector<int> black, white;
    int pos = 0;
    for (char c: s) {
        ++pos;
        if (c == '1') {
            if (white.empty()) {
                cout << "-1\n";
                return 0;
            } else {
                a[white.back()].push_back(pos);
                black.push_back(white.back());
                white.pop_back();
            }
        } else if (c == '0') {
            if (black.empty()) {
                white.push_back(SZ(a));
                a.push_back(vector<int>());
                a.back().push_back(pos);
            } else {
                a[black.back()].push_back(pos);
                white.push_back(black.back());
                black.pop_back();
            }
        }
    }
    if (!black.empty()) {
        cout << "-1\n";
        return 0;
    }
    cout << a.size() << '\n';
    for (const vector<int>& v: a) {
        cout << v.size() << ' ';
        for (int x: v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}