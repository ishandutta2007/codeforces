#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector < int > good;
    good = {1, 2, 4, 5};
    int ok = 0;
    while (good.back() <= n) {
        int x = good[(int)good.size() - 2];
        good.push_back(2 * x + ok + 1);
        good.push_back(2 * x + ok + 2);
        ok = (ok^1);
    }
    for (auto key : good) {
        if (key == n) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}