#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 100100;

set<int> g[MAXN];

set<int> setik;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    setik.erase(s);

    while (!q.empty()) {
        int v = q.front();  
        q.pop();

        vector<int> to;
        for (int u : setik) {
            if (!g[v].count(u)) {
                to.push_back(u);
            }
        }

        for (int u : to) {
            setik.erase(u);
            q.push(u);
        }
    }
}

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].insert(v);
        g[v].insert(u);
    }

    for (int i = 0; i < n; ++i) {
        setik.insert(i);
    }

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (setik.count(i)) {
            ++cnt;
            bfs(i);
        }
    }

    cout << cnt - 1 << endl;



#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}