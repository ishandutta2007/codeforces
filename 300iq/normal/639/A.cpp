#include <bits/stdc++.h>

using namespace std;

int t[150003];

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    multiset <pair <int, int> > cur;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int type = 0, id = 0;
    for (int i = 0; i < q; i++) {
        cin >> type >> id;
        if (type == 1) {
            cur.insert(make_pair(t[id - 1], id - 1));
            if ((int) cur.size() > k) {
                cur.erase(cur.begin());
            }
        } else {
            if (cur.find(make_pair(t[id - 1], id - 1)) == cur.end()) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
}