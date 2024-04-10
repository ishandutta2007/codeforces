#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define iii pair<ii, int>

const int N = 500005;

int n;
int l[N], r[N];

struct DSU {
    int n;
    vector<int> p;

    DSU(int _n) {
        n = _n;
        p.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }

    int root(int x) {
        return (p[x] == x) ? x : (p[x] = root(p[x]));
    }

    void merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return;
        p[x] = y;
    }

    bool inTheSameSet(int x, int y) {
        return (root(x) == root(y));
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<ii> s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        s.pb({l[i], i});
    }
    sort(all(s));
    DSU dsu = DSU(n);
    set<ii> v;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        v.insert({r[s[i].y], s[i].y});
        auto id = v.lower_bound(make_pair(s[i].x, 0));
        for (auto it = id; it != v.end(); it++) {
            if (it -> first >= r[s[i].y]) break;
            int id1 = it->second;
            int id2 = s[i].y;
            if (dsu.inTheSameSet(id1, id2)) {
                return cout << "NO", 0;
            } else {
                dsu.merge(id1, id2);
                cnt++;
            }
        }
    }
    if (cnt == n - 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}