#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;
const int mod = 998244353;

ll fact[MxN + 9];
vector<int> adj[MxN + 9];

ll f(const int u, const int parent) {
    ll res = fact[(int) adj[u].size()];
    for (int v : adj[u])
        if (v != parent) {
            res *= f(v, u);
            res %= mod;
        }
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    fact[0] = 1;
    for (int i = 1; i <= MxN; ++i) {
        fact[i] = fact[i - 1] * i % mod;
    }

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = n * fact[adj[1].size()] % mod;
    for (int x : adj[1]) {
        ans *= f(x, 1);
        ans %= mod;
    }

    cout << ans;

    return 0;
}