#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 50005;
const int MOD = 1000000007;

int n, a[N];
long long m;
unordered_map<int, int> mp[32];
vector<int> depth[35];
long long ans = 0;

struct Trie {
    int val;
    int dep;
    int next[2];
    int cnt[32];
    int npass;
    Trie() {
        val = 0;
        dep = 0;
        next[0] = next[1] = -1;
        npass = 0;
        for (int i = 0; i <= 30; i++) cnt[i] = 0;
    }
};

vector<Trie*> trie;

void insert(int x) {
    int cur = 0;
    int val = 0;
    for (int i = 30; i >= 0; i--) {
        if (bit(x, i)) trie[0]->cnt[i]++;
    }
    for (int i = 30; i >= 0; i--) {
        int c = bit(x, i);
        if (c) {
            val += (1 << i);
        }
        if (trie[cur]->next[c] == -1) {
            trie[cur]->next[c] = trie.size();
            trie.pb(new Trie());
            trie.back()->val = val;
            trie.back()->dep = trie[cur]->dep - 1;
        }
        cur = trie[cur]->next[c];
        trie[cur]->npass++;
        for (int j = 30; j >= 0; j--) {
            if (bit(x, j)) {
                trie[cur]->cnt[j]++;
            }
        }
    }
}

void dfs(int u) {
    mp[trie[u]->dep][trie[u]->val] = u;
    for (int i = 0; i < 2; i++) {
        if (trie[u]->next[i] == -1) continue;
        int v = trie[u]->next[i];
        dfs(v);
    }
}

pair<long long, long long> calc(int dep, int val) {
    pair<int, long long> res = {0, 0};
    for (auto u : depth[dep]) {
        int val1 = trie[u]->val;
        int val2 = val ^ val1;
        if (mp[dep][val2] == 0) continue;
        int foo = mp[dep][val1];
        int bar = mp[dep][val2];
        res.x += trie[foo]->npass * trie[bar]->npass;
        for (int j = 30; j >= 0; j--) {
            res.y += 1LL * trie[foo]->cnt[j] * (trie[bar]->npass - trie[bar]->cnt[j]) % MOD * (1 << j) % MOD; 
        }
    }
    res.x /= 2;
    return res;
} 

void solve(int dep, long long rem, int val) {
    if (dep == 0) {
        ans = (ans + rem * val % MOD) % MOD;
        return;
    }
    auto foo = calc(dep - 1, val + (1 << (dep - 1)));
    if (foo.x >= rem) {
        solve(dep - 1, rem, val + (1 << (dep - 1)));
    } else {
        ans = (ans + foo.y) % MOD;
        solve(dep - 1, rem - foo.x, val);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    Trie* tmp = new Trie();
    trie.pb(tmp);
    cin >> n >> m;
    trie[0]->dep = 31;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        insert(a[i]);
    }
    dfs(0);
    for (int i = 0; i < sz(trie); i++) {
        depth[trie[i]->dep].pb(i);
    }
    solve(31, m, 0);
    cout << ans;
    return 0;
}