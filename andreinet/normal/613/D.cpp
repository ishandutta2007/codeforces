#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

vector<int> G[NMAX];
int father[NMAX], level[NMAX];
int euler[2 * NMAX], elevel[2 * NMAX], epos;
int first[NMAX], last[NMAX];
int rmq[20][2 * NMAX], lg[2 * NMAX];

bool inQuery[NMAX];
bool used[NMAX];
int lcount[NMAX];

void dfs(int node, int prev) {
    father[node] = prev;
    level[node] = level[prev] + 1;

    euler[++epos] = node;
    first[node] = epos;
    elevel[epos] = level[node];

    for (int p: G[node]) {
        if (p == prev) continue;
        dfs(p, node);
        euler[++epos] = node;
        elevel[epos] = level[node];
    }
    last[node] = epos;
}

void buildRMQ() {
    for (int i = 2; i <= epos; ++i) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1; i <= epos; ++i) {
        rmq[0][i] = i;
    }
    for (int k = 1; (1 << k) <= epos; ++k) {
        int y = 1 << k - 1;
        for (int i = 1; i + (1 << k) - 1 <= epos; ++i) {
            rmq[k][i] = rmq[k - 1][i];
            if (elevel[rmq[k - 1][i + y]] < elevel[rmq[k][i]]) {
                rmq[k][i] = rmq[k - 1][i + y];
            }
        }
    }
}

int lca(int x, int y) {
    x = first[x];
    y = first[y];
    if (x > y) swap(x, y);
    int d = lg[y - x + 1];
    int r = rmq[d][x];
    if (elevel[rmq[d][y - (1 << d) + 1]] < elevel[r]) {
        r = rmq[d][y - (1 << d) + 1];
    }
    return euler[r];
}

struct cmp {
    bool operator()(const int a, const int b) const {
        return first[a] < first[b];
    }
};

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    buildRMQ();

    int q;
    cin >> q;

    while (q-- > 0) {
        int k;
        cin >> k;
        vector<int> nodes(k);
        for (int i = 0; i < k; ++i) {
            cin >> nodes[i];
            inQuery[nodes[i]] = true;
            used[nodes[i]] = true;
        }
        sort(nodes.begin(), nodes.end(), cmp());

        bool impossible = false;
        for (int i = 0; i < k; ++i) {
            if (inQuery[father[nodes[i]]]) {
                impossible = true;
            }
        }

        if (impossible) {
            cout << "-1\n";
            for (int i = 0; i < k; ++i) {
                inQuery[nodes[i]] = false;
                used[nodes[i]] = false;
            }
            continue;
        }
        
        for (int i = 1; i < k; ++i) {
            int x = lca(nodes[i - 1], nodes[i]);
            if (!used[x]) {
                nodes.push_back(x);
                used[x] = true;
            }
        }
        sort(nodes.begin(), nodes.end(), cmp());
        int ans = 0;

        vector<int> stk;
        for (int x: nodes) {
            while (!stk.empty() && first[x] > last[stk.back()]) {
                int l = stk.back();
                stk.pop_back();
                if (inQuery[l]) {
                    ans += lcount[l];
                    if (!stk.empty()) {
                        lcount[stk.back()]++;
                    }
                }
                else {
                    if (lcount[l] >= 2) {
                        ans++;
                    } else if(!stk.empty()) {
                        lcount[stk.back()] += lcount[l];
                    }
                }
            }
            stk.push_back(x);
        }
        while (!stk.empty()) {
            int l = stk.back();
            stk.pop_back();
            if (inQuery[l]) {
                ans += lcount[l];
                if (!stk.empty()) {
                    lcount[stk.back()]++;
                }
            }
            else {
                if (lcount[l] >= 2) {
                    ans++;
                } else if(!stk.empty()) {
                    lcount[stk.back()] += lcount[l];
                }
            }
        }


        cout << ans << '\n';
        for (int p: nodes) {
            inQuery[p] = false;
            used[p] = false;
            lcount[p] = 0;
        }
    }
}