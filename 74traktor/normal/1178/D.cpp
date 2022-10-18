#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
    int i = 2;
    while (i * i <= x) {
        if (x % i == 0) return false;
        ++i;
    }
    return true;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector < pair < int, int > > out;
    for (int i = 1; i <= n; ++i) {
        int nxt = i + 1;
        if (nxt > n) nxt = 1;
        out.push_back({i, nxt});
    }
    set < int > used;
    for (int i = 1; i <= n; ++i) used.insert(i);
    for (int i = n; i <= n + 1000; ++i) {
        if (check(i)) break;
        int t1 = (*used.begin());
        used.erase(t1);
        int to = -1;
        for (auto key : used) {
            if (t1 + 1 == key) continue;
            if (t1 == n && key == 1) continue;
            if (t1 == 1 && key == n) continue;
            if (key + 1 == t1) continue;
            to = key;
            break;
        }
        out.push_back({t1, to});
        used.erase(to);
    }
    cout << out.size() << '\n';
    for (auto key : out) cout << key.first << " " << key.second << '\n';
    return 0;
}