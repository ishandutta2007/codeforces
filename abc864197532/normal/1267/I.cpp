#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, del = 0;
        cin >> n;
        vector<int> sz(2 * n, 1), rts, tmp(2 * n);
        vector<vector<int>> ch(2 * n);
        iota(tmp.begin(), tmp.end(), 0);
        auto ask = [&](int i, int j) {
            cout << "? " << i + 1 << ' ' << j + 1 << endl;
            char c;
            cin >> c;
            if (c == '>') swap(i, j);
            ch[i].push_back(j), sz[i] += sz[j];
            return i;
        };
        while (del < n) {
            while (tmp.size() > 1) {
                rts.push_back(ask(tmp[tmp.size() - 2], tmp.back()));
                tmp.pop_back(), tmp.pop_back();
            }
            int i = rts.back();
            rts.pop_back();
            if (rts.empty()) rts.push_back(tmp.back()), tmp.pop_back();
            i = rts.back() = ask(i, rts.back());
            if (sz[i] > n) {
                ++del;
                rts.pop_back();
                for (int j : ch[i]) {
                    if (sz[j] == 1) tmp.push_back(j);
                    else rts.push_back(j);
                }
            }
        }
        cout << '!' << endl;
    }
}