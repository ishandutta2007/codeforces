#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = (a[i] & x);
    }
    int ans = -1;
    set <int> c;
    for (int i = 0; i < n; i++) {
        if (c.find(a[i]) != c.end()) {
            cout << 0;
            return 0;
        }
        c.insert(a[i]);
    }
    set <int> d;
    for (int i = 0; i < n; i++) {
        if (d.find(b[i]) != d.end()) {
            ans = 2;
        }
        d.insert(b[i]);
    }
    set < pair <int, bool> > e;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (e.find({a[i], 1}) != e.end()) {
            ans = 1;
        }
        if (e.find({b[i], 0}) != e.end()) {
            ans = 1;
        }
            e.insert({a[i], 0});
            continue;
        }
        if (e.find({a[i], 1}) != e.end()) {
            ans = 1;
        }
        e.insert({a[i], 0});
        if (e.find({b[i], 0}) != e.end()) {
            ans = 1;
        }
        e.insert({b[i], 1});
    }
    cout << ans;
    return 0;
}