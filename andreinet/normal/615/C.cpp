#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 2105, INF = 0x3f3f3f3f;

char A[NMAX], B[NMAX];
int dp[NMAX];
pair<int, int> pfrom[NMAX];

struct Node {
    int begin, end;
    Node *links[26];
    Node():
        begin(-1), end(-1), links{0} {}
};

void add(Node *node, char *S, int pos, int curr, int sign) {
    node->begin = pos;
    node->end = curr;
    if (*S == '\n' || *S == '\0') return;
    int n = *S - 'a';
    if (!node->links[n]) node->links[n] = new Node();
    add(node->links[n], S + sign, pos, curr + sign, sign);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    cin >> (A + 1) >> (B + 1);
    int n = strlen(A + 1);
    int m = strlen(B + 1);

    Node *root = new Node();
    for (int i = 1; i <= n; ++i) {
        add(root, A + i, i, i - 1, 1);
        add(root, A + i, i, i + 1, -1);
    }
    
    memset(dp, INF, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < m; ++i) {
        Node *node = root;
        for (int j = i + 1; j <= m; ++j) {
            node = node->links[B[j] - 'a'];
            if (!node) break;
            if (dp[j] > dp[i] + 1) {
                dp[j] = dp[i] + 1;
                pfrom[j] = {node->begin, node->end};
            }
        }
    }

    if (dp[m] == INF) {
        cout << "-1\n";
        return 0;
    }
    cout << dp[m] << '\n';
    vector<pair<int, int>> fans;
    for (int i = m, sz; i > 0; i -= sz) {
        fans.push_back(pfrom[i]);
        sz = pfrom[i].first - pfrom[i].second;
        if (sz < 0) sz = -sz;
        sz++;
    }
    reverse(fans.begin(), fans.end());
    for (auto& p: fans)
        cout << p.first << ' ' << p.second << '\n';
}