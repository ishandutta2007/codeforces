#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 3e5 + 9;
vector<int> adj[MxN + 9];
int cnt[MxN + 9];

bool f() {

    int n, m;
    cin >> n >> m;


    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    multiset<int> ms;


    for (int i = 1; i <= n; ++i)
        ms.insert(cnt[i] = (int) adj[i].size());


    for (int i = 1; i <= n; ++i) {
        for (int x : adj[i]) {
            ms.erase(ms.find(cnt[x]));
            ms.insert(--cnt[x]);
        }

        ms.erase(ms.find(cnt[i]));

        if (ms.empty() || *ms.rbegin() + cnt[i] == m)
            return true;

        ms.insert(cnt[i]);

        for (int x : adj[i]) {
            ms.erase(ms.find(cnt[x]));
            ms.insert(++cnt[x]);
        }
    }

    return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cout << (f() ? "YES" : "NO");
    return 0;
}