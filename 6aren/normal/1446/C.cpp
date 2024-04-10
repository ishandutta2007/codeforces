#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

struct Trie {
    int nx[2];
    int cnt;
    Trie() {
        nx[0] = nx[1] = -1;
    }
};

vector<Trie> tr(1);
vector<int> dp;

void insert(int u) {
    int cur = 0;
    for (int i = 30; i >= 0; i--) {
        int c = bit(u, i);
        if (tr[cur].nx[c] == -1) {
            tr[cur].nx[c] = tr.size();
            tr.push_back(Trie());
        }
        cur = tr[cur].nx[c];
    }
    tr[cur].cnt = 1;
}

void dfs(int u) {
    if (tr[u].nx[0] == tr[u].nx[1]) {
        dp[u] = tr[u].cnt;
        return;
    }
    if (tr[u].nx[0] == -1) {
        dfs(tr[u].nx[1]);
        dp[u] = dp[tr[u].nx[1]];
        return;
    }
    if (tr[u].nx[1] == -1) {
        dfs(tr[u].nx[0]);
        dp[u] = dp[tr[u].nx[0]];
        return;
    }
    dfs(tr[u].nx[1]);
    dfs(tr[u].nx[0]);

    dp[u] = max(dp[tr[u].nx[0]] + 1, dp[tr[u].nx[1]] + 1);
    
}

int n, a[N];;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        insert(a[i]);
    }

    dp.resize(tr.size());
    dfs(0);

    cout << n - dp[0] << '\n';

    return 0;
}