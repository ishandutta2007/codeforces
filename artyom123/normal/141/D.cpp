#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

struct my{
    int x, d, t, p;
};

int main() {
    int n, l;
    cin >> n >> l;
    vector <my> a(n);
    vector <int> c;
    c.push_back(0);
    c.push_back(l);
    map <pair<int, int>, int> tr;
    int ind = 0;
    for (auto &l : a) {
        cin >> l.x >> l.d >> l.t >> l.p;
        if (l.x - l.p >= 0) {
            c.push_back(l.x - l.p);
            if (tr.find({l.x - l.p, l.x + l.d}) == tr.end()) {
                tr[{l.x - l.p, l.x + l.d}] = ind;
            } else {
                int ind1 = tr[{l.x - l.p, l.x + l.d}];
                if (a[ind1].p + a[ind1].t > a[ind].p + a[ind].t) {
                    tr[{l.x - l.p, l.x + l.d}] = ind;
                }
            }
        }
        c.push_back(l.x + l.d);
        ind++;
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    map <int, int> ma;
    for (int i = 0; i < c.size(); i++) {
        ma[c[i]] = i;
    }
    vector <vector<pair<int, int>>> g(c.size());
    for (int i = 0; i < c.size() - 1; i++) {
        g[i].push_back({i + 1, c[i + 1] - c[i]});
        g[i + 1].push_back({i, c[i + 1] - c[i]});
    }
    for (int i = 0; i < n; i++) {
        if (a[i].x - a[i].p < 0) {
            continue;
        }
        g[ma[a[i].x - a[i].p]].push_back({ma[a[i].x + a[i].d], a[i].p + a[i].t});
    }
    int v = c.size();
    set <pair<int, int>> s;
    vector <int> d(v, INF);
    d[0] = 0;
    s.insert({0, 0});
    vector <int> p(v, -1);
    while (s.size()) {
        int cur = s.begin()->second;
        s.erase(s.begin());
        for (auto &to : g[cur]) {
            if (d[to.first] > d[cur] + to.second) {
                p[to.first] = cur;
                s.erase({d[to.first], to.first});
                d[to.first] = d[cur] + to.second;
                s.insert({d[to.first], to.first});
            }
        }
    }
    vector <int> path;
    int cur = v - 1;
    while (cur != -1) {
        path.push_back(c[cur]);
        cur = p[cur];
    }
    reverse(path.begin(), path.end());
    cout << d[v - 1] << "\n";
    vector <int> ans;
    for (int i = 0; i < path.size() - 1; i++) {
        if (tr.find({path[i], path[i + 1]}) != tr.end()) {
            if (path[i + 1] - path[i] >= a[tr[{path[i], path[i + 1]}]].p + a[tr[{path[i], path[i + 1]}]].t) {
                ans.push_back(tr[{path[i], path[i + 1]}] + 1);
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto &c : ans) {
        cout << c << " ";
    }
    return 0;
}