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
    string s;
    cin >> n >> s;

    int cnt = 0;
    vector<int> ans;
    for (char c: s) {
        if (c == 'W') {
            if (cnt != 0) {
                ans.push_back(cnt);
            }
            cnt = 0;
        } else {
            cnt++;
        }
    }
    if (cnt > 0) {
        ans.push_back(cnt);
    }
    cout << SZ(ans) << '\n';
    for (int p: ans) {
        cout << p << ' ';
    }
    cout << '\n';
}