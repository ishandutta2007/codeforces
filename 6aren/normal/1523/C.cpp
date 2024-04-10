#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &res) {
    cout << res[0];
    for (int i = 1; i < res.size(); i++) {
        cout << '.' << res[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) res.push_back(1);
            else {
                while (res.back() != x - 1) res.pop_back();
                res.back() = x;
            }
            print(res);
        }
    }

    return 0;
}