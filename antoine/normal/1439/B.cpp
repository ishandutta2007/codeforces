#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int)1e5 + 9;
unordered_set<int> adj[MxN + 9];
queue<int> q;
int n, m, k;


void enqueue(const int);

void rem(int u) {
    assert(adj[u].size() <= k - 1);
    vector<int> adj_u(adj[u].begin(), adj[u].end());
    adj[u].clear();
    for(const int v : adj_u) {
        auto it = adj[v].find(u);
        if(it == adj[v].end())
            continue;
        adj[v].erase(it);
        enqueue(v);
    }
}


void enqueue(const int u) {
    if(adj[u].size() < k - 1)
        rem(u);
    else if(adj[u].size() == k - 1)
        q.push(u);
}

void f() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    if(k * (k - 1LL) > 2*m) {
        cout << "-1\n";
        return;
    }

    for(int i = 1; i <= n; ++i)
        enqueue(i);

    while(!q.empty()) {
        const int u = q.front();
        q.pop();
        assert(adj[u].size() <= k - 1);
        if(adj[u].size() < k - 1) {
            rem(u);
            continue;
        }
        bool ok = true;
        for(auto it1 = adj[u].begin(); it1 != adj[u].end() && ok; ++it1) {
            for(auto it2 = next(it1); it2 != adj[u].end() && ok; ++it2) {
                if (!adj[*it1].count(*it2)) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            cout << "2\n" << u;
            for(int x : adj[u])
                cout << ' ' << x;
            cout << '\n';
            return;
        }
        rem(u);
    }
    vector<int> v;
    for(int i = 1; i <= n; ++i)
        if(!adj[i].empty()) {
            v.push_back(i);
            assert(adj[i].size() >= k);
        }

    if(v.empty()) {
        cout << "-1\n";
        return;
    }

    cout << "1 " << v.size() << '\n';
    for(int x : v)
        cout << ' ' << x;
    cout << '\n';
    return;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;
    while (t--) {
        f();
        for(int i = 0; i <= n; ++i) {
            adj[i].clear();
        }
        q = queue<int>{};
    }

    return 0;
}