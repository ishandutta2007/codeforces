#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nw(1 << n);
    iota(nw.begin(), nw.end(), 0);
    while (nw.size() > 1) {
        if (nw.size() == 2) {
            cout << "? " << nw[0] + 1 << ' ' << nw[1] + 1 << endl;
            int t;
            cin >> t;
            if (t == 2) {
                swap(nw[0], nw[1]);
            }
            nw.pop_back();
        } else {
            vector<int> nw_nw;
            for (int i = 0; i < (int)nw.size(); i += 4) {
                cout << "? " << nw[i] + 1 << ' ' << nw[i + 2] + 1 << endl;
                int t;
                cin >> t;
                if (t == 0) {
                    cout << "? " << nw[i + 1] + 1 << ' ' << nw[i + 3] + 1 << endl;
                    int t2;
                    cin >> t2;
                    if (t2 == 1) {
                        nw_nw.push_back(nw[i + 1]);
                    } else {
                        nw_nw.push_back(nw[i + 3]);
                    }
                } else {
                    if (t == 2) {
                        swap(nw[i], nw[i + 2]);
                        swap(nw[i + 1], nw[i + 3]);
                    }
                    cout << "? " << nw[i] + 1 << ' ' << nw[i + 3] + 1 << endl;
                    int t2;
                    cin >> t2;
                    if (t2 == 1) {
                        nw_nw.push_back(nw[i]);
                    } else {
                        nw_nw.push_back(nw[i + 3]);
                    }
                }
            }
            nw = nw_nw;
        }
    }
    cout << "! " << nw[0] + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}