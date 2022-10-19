#include<bits/stdc++.h>
using namespace std;

vector<int> mp;
map<pair<int, int>, pair<int, int>> tr; 

int solve(set<int> &cur, int l, int r) {
    if (cur.empty()) return 0;
    int n = cur.size() / 2;
    int ans = 1e9;
    if (mp[l] == r) {
        cur.erase(l);
        cur.erase(r);
        return solve(cur, l + 1, r - 1);
    }
    vector<pair<int, int>> u, v;
    u.push_back({l, mp[l]});
    v.push_back({r, mp[r]});
    int rr = mp[l], ll = mp[r];
    cur.erase(l);
    cur.erase(r);
    cur.erase(mp[l]);
    cur.erase(mp[r]);
    // cout << cur.size() << ' ' << rr << ' ' << ll  << endl;
    while (cur.size() > rr - ll - 1) {
        while (true) {
            if (cur.empty()) break;
            int foo = *cur.begin();
            if (foo > ll) break;
            cur.erase(foo);
            if (u.back().second < mp[foo]) return ans;
            cur.erase(mp[foo]);
            u.push_back({foo, mp[foo]});
        }
        rr = u.back().second;
        while (true) {
            if (cur.empty()) break;
            int foo = *cur.rbegin();
            if (foo < rr) break;
            cur.erase(foo);
            if (v.back().second > mp[foo]) return ans;
            cur.erase(mp[foo]);
            v.push_back({foo, mp[foo]});
        }
        // rr = u.back().second;
        ll = v.back().second;
        if (ll > rr) break;
    }
    // cout << "--------" << l << ' ' << r << endl;
    // for (auto e : u) {
    //     cout << e.first << ' ' << e.second << endl;
    // }
    // cout << "-------------" << endl;
    // for (auto e : v) {
    //     cout << e.first << ' ' << e.second << endl;
    // }
    if (ll > rr) return ans;
    int cnt = 0;
    for (auto e : u) {
        // cout << tr[e].first << ' ' << tr[e].second << e.first << ' ' << e.second << endl;
        if (e != tr[e]) cnt++;
    }
    for (auto e : v) {
        if (e != tr[e]) cnt++;
    }
    // cout << cnt << endl;
    int nn = cur.size() / 2;
    int foo = solve(cur, ll + 1, rr - 1);
    if (foo == 1e9) return ans;
    foo = min(foo, nn - foo);
    cnt = min(cnt, (n - nn) - cnt);
    return foo + cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<pair<int, int>> a;
    mp.resize(2 * n + 1);
    for (int i = 0; i < n; i++) {
        pair<int, int> e;
        a.insert(e);
        cin >> e.first >> e.second;
        mp[e.first] = e.second;
        mp[e.second] = e.first;
        tr[e] = e;
        tr[make_pair(e.second, e.first)] = e;
    }
    // cout << tr[{6, 4}].first <<' ' << tr[{6, 4}].second << endl;
    set<int> cur;
    for (int i = 1; i <= 2 * n; i++) cur.insert(i);
    int ans = solve(cur, 1, 2 * n);
    cout << (ans == 1e9 ? -1 : ans) << '\n';

    return 0;
}