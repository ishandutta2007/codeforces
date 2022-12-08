#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int MAXN = 300000;

map<int, int> mapa;
map<pair<int, int>, vector<int>> pos;
vector<int> g[MAXN];
int ptr[MAXN];
int used[MAXN];

void euler(int v, vector<int> &res) {
    used[v] = true;
    for (; ptr[v] < sz(g[v]); ) {
        ++ptr[v];
        int u = g[v][ptr[v] - 1];
        euler(u, res);
        res.push_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    int k = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(all(b));
    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            continue;
        }
        ++m;
        if (!mapa.count(b[i])) {   
            mapa[b[i]] = k++;
        }
    }
    if (m > s) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            continue;
        }
        a[i] = mapa[a[i]];
        b[i] = mapa[b[i]];
        g[b[i]].push_back(a[i]);
        pos[{b[i], a[i]}].push_back(i);
    }
    vector<vector<int>> cycles;
    for (int i = 0; i < k; ++i) {
        if (!used[i]) {
            vector<int> arr;
            euler(i, arr);
            reverse(all(arr));
            cycles.push_back({});
            for (int i = 0; i < sz(arr); ++i) {
                int j = (i + 1) % sz(arr);
                cycles.back().push_back(pos[{arr[i], arr[j]}].back());
                pos[{arr[i], arr[j]}].pop_back();
            }
        }
    }
    vector<vector<int>> res;
    if (s - m > 1 && sz(cycles) > 1) {
        int len = min(sz(cycles), s - m);   
        res.push_back({});
        vector<int> newcycle;
        for (int i = sz(cycles) - len; i < sz(cycles); ++i) {
            res.back().push_back(cycles[i].back());
            for (int j : cycles[i]) {
                newcycle.push_back(j);
            }
        }
        reverse(all(res.back()));
        for (int i = 0; i < len; ++i) {
            cycles.pop_back();
        }
        cycles.push_back(newcycle);
    }

    for (int i = 0; i < sz(cycles); ++i) {
        res.push_back(cycles[i]);
    }
    cout << sz(res) << endl;
    for (int i = 0; i < sz(res); ++i) {
        cout << sz(res[i]) << endl;
        for (int j : res[i]) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}