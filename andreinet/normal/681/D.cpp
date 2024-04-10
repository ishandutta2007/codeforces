#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005;

vector<int> tree[NMAX];
vector<int> G[NMAX];
int father[NMAX];
int level[NMAX];

int add[NMAX];
int wish[NMAX];
bool isWish[NMAX];

void dfs(const int node, const int lastWish) {
    int nextWish;
    if (isWish[node]) {
        nextWish = node;
    } else {
        nextWish = lastWish;
    }
    for (int to: tree[node]) {
        dfs(to, nextWish);
        add[node] += add[to];
    }
    add[node]++;
    add[wish[node]]--;
    if (lastWish != -1) {
        if (add[node] > 0) {
            G[lastWish].push_back(node);
        } else {
            G[node].push_back(lastWish);
        }
    }
}

int snodes[NMAX], spos;
bool used[NMAX];

int priorities[NMAX];

void dfs2(int node) {
    used[node] = true;
    for (int to: G[node]) {
        if (!used[to]) {
            dfs2(to);
        }
    }
    if (isWish[node]) {
        snodes[spos++] = node;
    }
}

multiset<pair<int, int>> h;

bool check(int node) {
    if (isWish[node]) {
        h.insert(make_pair(priorities[node], node));
    }

    if (h.begin()->second != wish[node]) {
        return false;
    }
    for (int to: tree[node]) {
        if (!check(to)) {
            return false;
        }
    }

    if (isWish[node]) {
        h.erase(make_pair(priorities[node], node));
    }
    return true;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    memset(father, -1, sizeof father);
    for (int i = 0; i < m; ++i) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        father[q] = p;
        tree[p].push_back(q);
    }
    for (int i = 0; i < n; ++i) {
        cin >> wish[i];
        wish[i]--;
        isWish[wish[i]] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (father[i] == -1) {
            dfs(i, -1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i] && isWish[i]) {
            dfs2(i);
        }
    }
    reverse(snodes, snodes + spos);
    for (int i = 0; i < spos; ++i) {
        priorities[snodes[i]] = i;
    }
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        if (father[i] == -1) {
            ans &= check(i);
        }
    }
    if (ans) {
        cout << spos << '\n';
        for (int i = 0; i < spos; ++i) {
            cout << snodes[i] + 1 << '\n';
        }
    } else {
        cout << "-1\n";
    }
}