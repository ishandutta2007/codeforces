#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> lists;
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            lists.push_back({1});
        } else {
            lists.push_back(lists.back());
            if (a[i] == 1) {
                lists.back().push_back(1);
            } else {
                int loc = -1;
                for (int j = i - 1; j >= 0; --j) {
                    if (!used[j] && lists[j].back() == a[i] - 1) {
                        loc = j;
                        break;
                    }
                }
                for (int j = loc; j <= i - 1; ++j) {
                    used[j] = true;
                }
                lists.back() = lists[loc];
                lists.back().back() = a[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < lists[i].size(); ++j) {
            cout << lists[i][j];
            if (j != lists[i].size() - 1) {
                cout << '.';
            }
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; 
    cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) {
        solve_case(tc);
    }
    return 0;
}