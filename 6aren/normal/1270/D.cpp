#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int a[505];

ii query(set<int> s) {
    cout << "? ";
    for (auto e : s) {
        cout << e << ' ';
    }
    cout << endl;
    ii res;
    cin >> res.x >> res.y;
    a[res.x] = res.y;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 1; i <= k; i++) {
        s.insert(i);
    }
    int mn = 1e9 + 1;
    for (int i = k + 1; i <= n; i++) {
        ii u = query(s);
        mn = min(mn, u.y);
        s.erase(u.x);
        s.insert(i);
    }
    ii u = query(s);
    mn = min(mn, u.y);
    s.erase(u.x);
    int ans = 1;
    set<int> t;
    int sm = 1e9 + 1, bg = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) {
            t.insert(i);
            sm = min(sm, a[i]);
            bg = max(bg, a[i]);
        }
        if (t.size() == 2) break;
    }
    set<int> ss;
    for (auto e : s) ss.insert(e);
    for (auto e : t) ss.insert(e);
    for (auto e : s) {
        ss.erase(e);
        auto u = query(ss);
        if (u.y == bg) ans++;
        ss.insert(e);
    }
    cout << "! " << ans << endl;
    return 0;
}
/*
4 3 3
2 0 1 9
*/