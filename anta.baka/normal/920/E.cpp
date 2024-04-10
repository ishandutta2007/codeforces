#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 3e5;

int n, m;
set<pair<int, int>> ban;
vector<int> siz;
set<int> alive;

bool ok(int u, int v) {
    if(u > v) swap(u, v);
    return ban.find({u, v}) == ban.end();
}

void go(int v) {
    vector<int> vec;
    for(int to : alive)
        if(ok(v, to))
            vec.push_back(to);
    for(int to : vec) alive.erase(to);
    siz.back() += vec.size();
    for(int to : vec) go(to);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if(u > v) swap(u, v);
        ban.insert({u, v});
    }
    for(int u = 0; u < n; u++) alive.insert(u);
    for(int u = 0; u < n; u++) if(alive.find(u) != alive.end()) {
        alive.erase(u); siz.push_back(1); go(u);
    }
    sort(all(siz));
    cout << sz(siz) << '\n';
    for(int x : siz) cout << x << ' ';
}