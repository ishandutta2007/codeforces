#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

vector<int> pos[10];

int calc(int a, int b) {
    if (pos[a].size() == 0 || pos[b].size() == 0) return 0;
    if (pos[a][0] > pos[b][0]) swap(a, b);
    int t[2] = {a, b};
    int cur = 0;
    vector<int> res;
    res.push_back(-1);
    vector<int> u[2] = {pos[a], pos[b]};
    reverse(all(u[0]));
    reverse(all(u[1]));
    while (true) {
        if (u[cur].size() == 0) break;
        bool out = 0;
        while (u[cur].back() < res.back()) {
            u[cur].pop_back();
            if (u[cur].size() == 0) {
                out = true;
                break;
            }
        }
        if (out) break;
        res.push_back(u[cur].back());
        u[cur].pop_back();
        cur = 1 - cur;
    }
    int ans = res.size() - 1;
    return ans / 2 * 2;

}

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) pos[s[i] - '0'].pb(i);

    int ans = 1e9;

    for (int i = 0; i < 10; i++) ans = min(ans, (int) s.size() - (int) pos[i].size());

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) continue;
            ans = min(ans, (int) s.size() - calc(i, j));
        }
    }
    for (int i = 0; i < 10; i++) pos[i].clear();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) solve();
    return 0;   
}