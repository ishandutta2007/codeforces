#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

int check(multiset<int> s1, multiset<int> s2) {
    int cnt = 0;
    while ((int)s1.size() && (int)s2.size()) {
        if (*s1.begin() == *s2.begin()) {
            cnt++;
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            continue;
        }
        if (*s1.begin() < *s2.begin()) {
            s1.erase(s1.begin());
            continue;
        }
        if (*s1.begin() > *s2.begin()) {
            s2.erase(s2.begin());
            continue;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> b(n);
        set<pair<int, int>> s;
        map<int, int> ma;
        vector<vector<int>> gist(n + 5);
        set<int> kek;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            int c = b[i];
            s.erase({ma[c], c});
            ma[c]++;
            s.insert({ma[c], c});
            gist[c].pb(i);
            kek.insert(c);
        }
        int need = -1;
        for (int i = 1; i <= n + 1; i++) {
            if (kek.find(i) == kek.end()) {
                need = i;
                break;
            }
        }
        vector<int> usd(n), a(n);
        for (int k = 0; k < x; k++) {
            auto tmp = *s.rbegin();
            s.erase(tmp);
            s.insert({tmp.fi - 1, tmp.se});
            usd[gist[tmp.se].back()] = 1;
            a[gist[tmp.se].back()] = tmp.se;
            gist[tmp.se].pop_back();
        }
        vector<pair<int, int>> lol;
        for (int i = 0; i < n; i++) {
            if (usd[i]) continue;
            lol.pb(b[i], i);
        }
        sort(all(lol));
        int delta = (n - x) / 2;
        for (int i = 0; i < n - x; i++) {
            a[lol[(i + delta) % (n - x)].se] = lol[i].fi;
        }
        gist.clear();
        gist.resize(n + 5);
        for (int i = 0; i < n; i++) {
            if (usd[i]) continue;
            if (a[i] != b[i]) gist[a[i]].pb(i);
        }
        for (int i = 0; i < n; i++) {
            if (usd[i]) continue;
            if (a[i] == b[i]) gist[a[i]].pb(i);
        }
        for (int k = 0; k < n - y; k++) {
            auto tmp = *s.rbegin();
            s.erase(tmp);
            s.insert({tmp.fi - 1, tmp.se});
            usd[gist[tmp.se].back()] = 1;
            a[gist[tmp.se].back()] = need;
            gist[tmp.se].pop_back();
        }
        int cntx = 0;
        multiset<int> s1, s2;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) cntx++;
            s1.insert(a[i]);
            s2.insert(b[i]);
        }
        int cnty = check(s1, s2);
        if (cntx == x && cnty == y) {
            cout << "YES\n";
            for (auto &c : a) cout << c << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}