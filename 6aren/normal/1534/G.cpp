#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pos.push_back({x + y, x - y});
    }

    sort(pos.begin(), pos.end());

    multiset<int> l_pos, r_pos;
    int l_offset = 0, r_offset = 0, min_cost = 0;

    int pre = -1;
    for (auto position : pos) {
        int x = position.first;
        int y = position.second;
        if (pre == -1) {
            l_pos.insert(y);
            r_pos.insert(y);
            pre = x;
            continue;
        }
        int dis = x - pre;
        pre = x;
        l_offset -= dis;
        r_offset += dis;
        int l_bound = l_offset + *l_pos.rbegin();
        int r_bound = r_offset + *r_pos.begin();
        assert(r_bound >= l_bound);
        if (y >= l_bound && y <= r_bound) {
            l_pos.insert(y - l_offset);
            r_pos.insert(y - r_offset);
        } else if (y < l_bound) {
            auto foo = *l_pos.rbegin();
            r_pos.insert(foo + l_offset - r_offset);
            min_cost += abs(y - (*l_pos.rbegin() + l_offset)) / 2;
            l_pos.erase(l_pos.find(foo));
            l_pos.insert(y - l_offset);
            l_pos.insert(y - l_offset);
        } else if (y > r_bound) {
            auto foo = *r_pos.begin();
            l_pos.insert(foo + r_offset - l_offset);
            min_cost += abs(y - (*r_pos.begin() + r_offset)) / 2;
            r_pos.erase(r_pos.find(foo));
            r_pos.insert(y - r_offset);
            r_pos.insert(y - r_offset);
        }
    }
    
    cout << min_cost << endl;

    return 0;
}