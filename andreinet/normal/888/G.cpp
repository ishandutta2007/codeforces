#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

struct Node {
    int link[2] = {-1, -1};
};

class Trie {
public:
    Trie(int _lvlMax) {
        nodes.push_back(Node());
        lvlMax = _lvlMax;
    }

    void add(int value) {
        int node = 0;
        for (int lvl = lvlMax; lvl >= 0; --lvl) {
            int b = !!(value & (1 << lvl));
            if (nodes[node].link[b] == -1) {
                int x = newNode();
                nodes[node].link[b] = x;
            }
            node = nodes[node].link[b];
        }
    }

    int getMin(int value) {
        int node = 0;
        int ans = 0;
        for (int lvl = lvlMax; lvl >= 0; --lvl) {
            int b = !!(value & (1 << lvl));
            if (nodes[node].link[b] == -1) {
                ans |= 1 << lvl;
                node = nodes[node].link[b ^ 1];
            } else {
                node = nodes[node].link[b];
            }
        }
        return ans;
    }
private:
    vector<Node> nodes;
    int lvlMax;
    int newNode() {
        nodes.push_back(Node());
        return SZ(nodes) - 1;
    }
};

int64_t ans = 0;

vector<int> a;

void solve(int left, int right, int lvl) {
    if (left > right) {
        return;
    }
    if (lvl == -1) {
        return;
    }
    int pos = left;
    while (pos <= right && (a[pos] & (1 << lvl)) == 0) {
        pos++;
    }
    solve(left, pos - 1, lvl - 1);
    solve(pos, right, lvl - 1);
    if (pos != left && pos != right + 1) {
        int minCost = 0x3f3f3f3f;
        Trie t(lvl);
        for (int i = left; i < pos; ++i) {
            t.add(a[i]);
        }
        for (int i = pos; i <= right; ++i) {
            minCost = min(minCost, t.getMin(a[i]));
        }
        ans += minCost;
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    a = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    solve(0, n - 1, 29);
    cout << ans << '\n';
}