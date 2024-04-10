#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
int n, m;
vector < vector<int> > a;

void out(vector<int> d) {

}
void check(vector<int> b) {
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(b[j] != a[i][j]) cnt++;
        }
        if(cnt > 2) return;
    }
    cout << "Yes\n";
    for(int x: b) cout << x << " ";
    exit(0);
}

void solve(int x, int y) {
    vector<int> b = a[0];
    vector<int> d;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(j == x || j == y) continue;
            if(a[0][j] != a[i][j]) cnt++;
        }
        if(cnt == 0) continue;
        if(cnt >= 3) return;
        if(cnt == 2) {
            b[x] = a[i][x];
            b[y] = a[i][y];
            check(b);
            return;
        }
        d.push_back(i);
    }
    map<int, int> cnt;
    map < int, vector<int> > T;
    for(int pos: d) {
        cnt[a[pos][y]]++;
        T[a[pos][x]].push_back(pos);
    }
    for(auto [value, positions]: T) {
        for(auto pos: positions) {
            cnt[a[pos][y]]--;
            if(cnt[a[pos][y]]==0) cnt.erase(a[pos][y]);
        }
        if(cnt.size()==0) {
            b[x] = value;
            b[y] = value;
            check(b);
        }
        if(cnt.size() == 1) {
            b[x] = value;
            b[y] = cnt.begin()->first;
            check(b);
        }
        for(auto pos: positions) {
            cnt[a[pos][y]]++;
        }
    }

}
void solve() {
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        a[i].resize(m);
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    check(a[0]);
    for(int i = 1; i < n; i++) {
        vector<int> g;
        for(int j = 0; j < m; j++) {
            if(a[i][j] != a[0][j]) g.push_back(j);
        }
        if(g.size() >= 5) {
            break;
        }
        if(g.size() <= 2) continue;

        for(int j = 0; j < g.size(); j++) {
            for(int k = 0; k < g.size(); k++) {
                solve(g[j], g[k]);
            }
        }
        break;
    }
    cout << "No\n";
}
int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}