#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (auto &c : w) cin >> c;
    vector<vector<int>> lol(n);
    vector<pair<int, int>> ho(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        lol[x].pb(i);
        lol[y].pb(i);
        w[x]--; w[y]--;
        ho[i] = {x, y};
    }
    set<int> kek;
    for (int i = 0; i < n; i++) {
        if (w[i] < 0) continue;
        for (auto &c : lol[i]) kek.insert(c);
    }
    vector<int> usd(m);
    vector<int> ans;
    while (kek.size()) {
        int ha = *kek.begin();
        kek.erase(ha);
        if (usd[ha]) continue;
        usd[ha] = 1;
        w[ho[ha].fi]++;
        if (w[ho[ha].fi] == 0) {
            for (auto &c : lol[ho[ha].fi]) kek.insert(c);
        }
        w[ho[ha].se]++;
        if (w[ho[ha].se] == 0) {
            for (auto &c : lol[ho[ha].se]) kek.insert(c);
        }
        ans.pb(ha);
    }
    if (ans.size() < m) cout << "DEAD";
    else {
        cout << "ALIVE\n";
        reverse(all(ans));
        for (auto &c : ans) cout << c + 1 << " ";
    }
    return 0;
}