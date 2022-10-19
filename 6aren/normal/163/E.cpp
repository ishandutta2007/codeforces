#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 1000005;

int n, k;
string s[N];
int en[N];
int in[N], out[N], timer = 0;
vector<int> g[N];

struct Trie {
    char pch;
    int link = -1;
    int par;
    int nx[26];
    bool finish = 0;
    Trie(char pch = '$', int par = -1) {
        this->pch = pch;
        this->par = par;
        memset(nx, -1, 26 * 4);
    }
};

vector<Trie> tr(1);

void insert(string s, int id) {
    int cur = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (tr[cur].nx[c] == -1) {
            tr[cur].nx[c] = tr.size();
            tr.pb(Trie(ch, cur));
        } 
        cur = tr[cur].nx[c];
    }
    tr[cur].finish = 1;
    en[id] = cur;
}

int go(int u, char ch);

int getlink(int u) {
    if (tr[u].link != -1) return tr[u].link;
    if (u == 0 || tr[u].par == 0) tr[u].link = 0;
    else tr[u].link = go(getlink(tr[u].par), tr[u].pch);
    return tr[u].link;
}

int go(int u, char ch) {
    int c = ch - 'a';
    if (tr[u].nx[c] != -1) return tr[u].nx[c];
    else if (u != 0) return go(getlink(u), ch);
    else return 0;
}

void dfs(int u) {
    in[u] = ++timer;
    for (int e : g[u]) {
        dfs(e);
    }
    out[u] = timer;
}

struct BIT {
    vector<int> bit;
    int maxn;
    
    BIT(int n) {
        bit.resize(n + 2, 0);
        maxn = n + 1;
    }

    void update(int k, int val) {
        for (int i = k; i < maxn; i += (i & (-i))) {
            bit[i] += val;
        }
    }

    int get(int k) {
        int res = 0;
        for (int i = k; i > 0; i -= (i & (-i))) {
            res += bit[i];
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    set<int> citizens;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
        insert(s[i], i); 
        citizens.insert(i);
    }
    for (int i = 1; i < tr.size(); i++) {
        g[getlink(i)].pb(i);
    }
    dfs(0);
    BIT bit = BIT(tr.size() + 2);
    for (int i = 1; i < tr.size(); i++) {
        if (tr[i].finish) {
            bit.update(in[i], 1);
            bit.update(out[i] + 1, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        string que;
        cin >> que;
        if (que[0] == '+') {
            int id = stoi(que.substr(1, que.size()));
            if (citizens.count(id)) continue;
            citizens.insert(id);
            int u = en[id];
            bit.update(in[u], 1);
            bit.update(out[u] + 1, -1);
        } else if (que[0] == '-') {
            int id = stoi(que.substr(1, que.size()));
            if (!citizens.count(id)) continue;
            citizens.erase(id);
            int u = en[id];
            bit.update(in[u], -1);
            bit.update(out[u] + 1, 1);
        } else {
            long long ans = 0;
            int cur = 0;
            for (int i = 1; i < que.size(); i++) {
                char ch = que[i];
                cur = go(cur, ch);
                // cout << cur << ' ' << bit.get(in[cur]) << endl;
                ans += bit.get(in[cur]);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}