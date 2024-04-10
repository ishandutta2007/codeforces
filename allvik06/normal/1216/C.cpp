#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

struct p {
    int x1, y1, x2, y2;
};

signed main() {
    p a, b, c, d, e;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> c.x1 >> c.y1 >> c.x2 >> c.y2;
    d.x1 = max(a.x1, b.x1);
    d.y1 = max(a.y1, b.y1);
    d.x2 = min(a.x2, b.x2);
    d.y2 = min(a.y2, b.y2);
    e.x1 = max(a.x1, c.x1);
    e.y1 = max(a.y1, c.y1);
    e.x2 = min(a.x2, c.x2);
    e.y2 = min(a.y2, c.y2);
    if (e.y1 == a.y1 && d.y1 == a.y1) {
        if (e.x1 > d.x1) {
            swap(e, d);
        }
        if (e.x1 == a.x1 && d.x1 == a.x1) {
            if ((e.x2 == a.x2 && e.y2 == a.y2) || (d.x2 == a.x2 && d.y2 == a.y2)) {
                cout << "NO";
            }
            else {
                cout << "YES";
            }
        }
        else if (e.x1 == a.x1) {
            if (e.y2 == a.y2) {
                if (e.x2 == a.x2) {
                    cout << "NO";
                }
                else {
                    if (e.x2 >= d.x1) {
                        if (d.x2 == a.x2 && d.y2 == a.y2) {
                            cout << "NO";
                        }
                        else {
                            cout << "YES";
                        }
                    }
                    else {
                        cout << "YES";
                    }
                }
            }
            else {
                cout << "YES";
            }
        }
        else {
            cout << "YES";
        }
    }
    else if (d.y1 == a.y1) {
        if (d.x1 == a.x1 && d.y2 == a.y2 && d.x2 == a.x2) {
            cout << "NO";
        }
        else if (d.x1 == a.x1 && d.x2 == a.x2) {
            if (e.y1 <= d.y2) {
                if (e.x1 == a.x1 && e.x2 == a.x2 && e.y2 == a.y2) {
                    cout << "NO";
                }
                else {
                    cout << "YES";
                }
            }
            else {
                cout << "YES";
            }
        }
        else {
            cout << "YES";
        }
    }
    else if (e.y1 == a.y1) {
        if (e.x1 == a.x1 && e.y2 == a.y2 && e.x2 == a.x2) {
            cout << "NO";
        }
        else if (e.x1 == a.x1 && e.x2 == a.x2) {
            if (d.y1 <= e.y2) {
                if (d.x1 == a.x1 && d.x2 == a.x2 && d.y2 == a.y2) {
                    cout << "NO";
                }
                else {
                    cout << "YES";
                }
            }
            else {
                cout << "YES";
            }
        }
        else {
            cout << "YES";
        }
    }
    else {
        cout << "YES";
    }
}