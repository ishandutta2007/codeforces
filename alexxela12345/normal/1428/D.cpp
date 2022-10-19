#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> dx = {-1, 0, 1,  0};
vector<int> dy = {0,  1, 0, -1};

int sign(int x) {
    if (x == 0)
        return 0;
    return abs(x) / x;
}

vector<int> get(int n, vector<pair<int, int>> arr) {
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        int dir = 0;
        int cnt = 0;
        int x = n + 1;
        int y = i;
        while (true) {
            bool was = false;
            int mintime = 1e9;
            int xx = -1;
            int yy = -1;
            for (auto &el : arr) {
                if (el.first == x && sign(el.second - y) == dy[dir] && dx[dir] == 0) {
                    if (abs(el.second - y) < mintime) {
                        mintime = abs(el.second - y);
                        xx = el.first;
                        yy = el.second;
                    }
                    was = 1;
                } else if (sign(el.first - x) == dx[dir] && el.second == y && dy[dir] == 0) {
                    if (abs(el.first - x) < mintime) {
                        mintime = abs(el.first - x);
                        xx = el.first;
                        yy = el.second;
                    }
                    was = 1;
                }
            }
            if (!was)
                break;
            dir++;
            if (dir == 4)
                dir = 0;
            cnt++;
            x = xx;
            y = yy;
        }
        ans[i - 1] = cnt;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> nonpairx3;
    set<int> nonpairx23;
    vector<pair<int, int>> ans;
    int first = n;
    vector<int> lowest(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            continue;
        }
        if (a[i] == 1) {
            ans.push_back({first, i + 1});
            lowest[i] = first;
            first--;
            nonpairx23.insert(i + 1);
            continue;
        }
        if (a[i] == 2) {
            int x = -1;
            if (!nonpairx23.empty()) {
                x = *nonpairx23.begin();
                nonpairx23.erase(nonpairx23.begin());
            }
            if (x == -1) {
                cout << -1 << endl;
                return 0;
            }
            ans.push_back({lowest[x - 1], i + 1});
            lowest[i] = lowest[x - 1];
            nonpairx3.insert(i + 1);
            continue;
        } else {
            int x = -1;
            if (!nonpairx3.empty()) {
                x = *nonpairx3.begin();
                nonpairx3.erase(nonpairx3.begin());
            } else if (!nonpairx23.empty()) {
                x = *nonpairx23.begin();
                nonpairx23.erase(nonpairx23.begin());
            }
            if (x == -1) {
                cout << -1 << endl;
                return 0;
            }
            ans.push_back({first, i + 1});
            ans.push_back({first, x});
            lowest[i] = first;
            first--;
            nonpairx3.insert(i + 1);
            continue;
        }
    }
    map<int, int> cntrow, cntcol;
    for (auto &el : ans) {
        cntrow[el.first]++;
        cntcol[el.second]++;
        assert(el.first >= 1 && el.first <= n);
        assert(el.second >= 1 && el.second <= n);
    }
    for (auto &el : cntrow) {
        assert(el.second <= 2);
    }
    for (auto &el : cntcol) {
        assert(el.second <= 2);
    }
    //assert(get(n, ans) == a);
    //cout << "YES" << endl;
    //return 0;
    cout << ans.size() << endl;
    for (auto &el : ans) {
        cout << el.first << " " << el.second << '\n';
    }
}