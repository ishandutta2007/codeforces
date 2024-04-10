#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <map>
#include <set>

using namespace std;
const int INF = 1e9 + 1;

inline int ask(int a, int b, int c) {
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int pos1, pos2, val;
        val = ask(0, 1, 2);
        int _01 = ask(0, 1, 3);
        int _02 = ask(0, 2, 3);
        int _12 = ask(1, 2, 3);
        if (max({_01, _02, _12}) == val) {
            if (_01 == val) {
                pos1 = 0;
                pos2 = 1;
            } else if (_02 == val) {
                pos1 = 0;
                pos2 = 2;
            } else {
                pos1 = 1;
                pos2 = 2;
            }
        } else {
            val = max({_01, _02, _12});
            if (val == _01 && val == _02) pos1 = 0;
            else if (val == _01 && val == _12) pos1 = 1;
            else pos1 = 2;
            pos2 = 3;
        }
        for (int i = 4; i < n; ++i) {
            int other_num = 0;
            while (true) {
                if (other_num == pos1 || other_num == pos2) ++other_num;
                else break;
            }
            int val1 = ask(pos1, i, other_num);
            int val2 = ask(pos2, i, other_num);
            if (max(val1, val2) > val) {
                val = max(val1, val2);
                if (val == val1) pos2 = i;
                else pos1 = i;
            }
        }
        cout << "! " << pos1 + 1 << " " << pos2 + 1 << endl;
    }
}

/*

 */