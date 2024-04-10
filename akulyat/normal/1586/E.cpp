#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
    mt19937 rng(1033);
#else
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n, m;
vector<vector<int>> e;
vector<int> cnt;
vector<int> p;

void DFS(int v) {
    for (auto u : e[v]) {
        if (p[u] == -1) {
            p[u] = v;
            DFS(u);
        }
    }
}

void solve() {
    cin >> n >> m;
    e.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    p.resize(n, -1);
    p[0] = 0;
    DFS(0);

    cnt.resize(n, 0);
    int q;
    cin >> q;
    vector<vector<int>> paths;
    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        vector<int> pa(1, a), pb(1, b);
        while (pa.back() != 0)
            pa.push_back(p[pa.back()]);
        while (pb.back() != 0)
            pb.push_back(p[pb.back()]);
        int r = -1;
        while (pa.back() == pb.back()) {
            r = pa.back();
            pa.pop_back(), pb.pop_back();
        }
        pa.push_back(r);
        // pb.pop_back();
        reverse(pb.begin(), pb.end());
        for (auto i : pb)
            pa.push_back(i);
        paths.push_back(pa);
        cnt[a] += 1;
        cnt[b] += 1;
    }    
    int bad = 0;
    for (auto i : cnt)
        bad += (i & 1);

    if (!bad) {
        cout << "YES\n";
        for (auto path : paths) {
            cout << path.size() << '\n';
            for (auto i : path)
                cout << i + 1 << ' ';
            cout << '\n';
        }
    } else {
        cout << "NO\n";
        cout << bad / 2 << '\n';
    }
}

int main() {
    // viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int t = 1; 
    // cin >> t;
    while (t--)
        solve();

    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}