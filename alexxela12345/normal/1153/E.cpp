#include <bits/stdc++.h>
using namespace std;

int query(int x1, int y1, int x2, int y2) {
    x1++;
    y1++;
    x2++;
    y2++;
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int kek;
    cin >> kek;
    return kek;
}

int main() {
    int n;
    cin >> n;
    vector<int> rr, cc;
    for (int i = 0; i < n; i++) {
        int k = query(i, 0, i, n - 1);
        if (k % 2 == 1) {
            rr.push_back(i);
        }
        k = query(0, i, n - 1, i);
        if (k % 2 == 1) {
            cc.push_back(i);
        }
    }
    if (rr.size() == 2) {
        if (cc.size() == 2) {
            if (query(rr[0], cc[0], rr[0], cc[0]) % 2 == 1) {
                cout << "! " << rr[0] + 1 << " " << cc[0] + 1 << " " << rr[1] + 1 << " " << cc[1] + 1 << endl;
            } else {
                cout << "! " << rr[0] + 1 << " " << cc[1] + 1 << "  " << rr[1] + 1 << "  " << cc[0] + 1 << endl;
            }
        } else {
            int l = 0;
            int r = n;
            while (r - l > 1)  {
                int m = l + (r - l) / 2;
                if (query(rr[0], l, rr[0], m - 1) % 2 == 1) {
                    r = m;
                } else {
                    l = m;
                }
            }
            cout << "! " << rr[0] + 1 << " " << l  + 1<< " " << rr[1] + 1 << " " << l + 1<< endl;
        }
    } else {
        int l = 0;
        int r = n;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (query(l, cc[0], m - 1, cc[0]) % 2 == 1) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << "! " << l + 1 << " " << cc[0] + 1 << " " << l + 1 << " " << cc[1] + 1 << endl;
    }

        


    return 0;
}