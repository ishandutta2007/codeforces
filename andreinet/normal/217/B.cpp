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
    cin.tie(0);

    int n, r;
    cin >> n >> r;
    
    const int INF = 0x3f3f3f3f;
    int ans = INF;
    vector<pair<int, int>> fans;
    vector<pair<int, int>> v;
    for (int m = 1; m < max(r, 2); ++m) {
        int nr1 = m, nr2 = r;
        v.clear();
        while (nr1 != 0 && nr2 != 0) {
            if (nr1 > nr2) {
                v.push_back(make_pair(nr1 / nr2, 0));
                nr1 %= nr2;
            } else {
                v.push_back(make_pair(nr2 / nr1, 1));
                nr2 %= nr1;
            }
        }
        if (nr1 + nr2 != 1) {
            continue;
        }
        if (nr1 != 0) {
            for (pair<int, int>& p: v) {
                p.second ^= 1;
            }
        }
        reverse(v.begin(), v.end());
        if (SZ(v) > 0 && v[0].first > 1) {
            v.insert(v.begin() + 1, make_pair(v[0].first - 1, v[0].second ^ 1));
            for (int i = 2; i < SZ(v); ++i) {
                v[i].second ^= 1;
            }
            v[0].first = 1;
        }
        int cost = 0;
        int steps = 0;
        for (const pair<int, int>& p: v) {
            cost += p.first - 1;
            steps += p.first;
        }
        if (steps != n) {
            continue;
        }
        if (ans > cost) {
            ans = cost;
            fans = v;
        }
    }
    if (ans == INF) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << '\n';
        string s;
        for (const pair<int, int>& p: fans) {
            int cnt = p.first;
            char c = p.second == 1 ? 'B': 'T';
            while (cnt > 0) {
                cnt--;
                s += c;
            }
        }
        cout << s << '\n';
    }
}