#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int SIGMA = 20;

struct Node {
    int go[SIGMA], val, link;
};

const int MAXN = 205, MAXK = 505, MOD = 1000 * 1000 * 1000 + 7;
Node trie[MAXN];
int vals[MAXN], dp[MAXN][MAXN][MAXK][2][2], freeNode;
vector<int> aa[MAXN];

istream &operator>>(istream &in, vector<int> &a) {
    int n;
    in >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        in >> a[i];
    return in;
}

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

int newNode() {
    for(int i = 0; i < SIGMA; i++)
        trie[freeNode].go[i] = -1;
    trie[freeNode].val = 0;
    trie[freeNode].link = -1;
    return freeNode++;
}

void add(const vector<int> &a, int val) {
    int v = 0;
    for(size_t i = 0; i < a.size(); i++) {
        if(trie[v].go[a[i]] == -1)
            trie[v].go[a[i]] = newNode();
        v = trie[v].go[a[i]];
    }
    trie[v].val += val;
}

void buildAho(int n, int m) {
    freeNode = 0;
    newNode();
    for(int i = 0; i < n; i++)
        add(aa[i], vals[i]);
    queue<int> q;
    for(int i = 0; i < m; i++)
        if(trie[0].go[i] == -1)
            trie[0].go[i] = 0;
        else {
            trie[trie[0].go[i]].link = 0;
            q.push(trie[0].go[i]);
        }
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        trie[v].val += trie[trie[v].link].val;
        for(int i = 0; i < m; i++)
            if(trie[v].go[i] == -1)
                trie[v].go[i] = trie[trie[v].link].go[i];
            else {
                trie[trie[v].go[i]].link = trie[trie[v].link].go[i];
                q.push(trie[v].go[i]);
            }
    }
}

int solve(int m, int k, const vector<int> &r) {
    int len = r.size(), nodes = freeNode;
    for(int i = 0; i <= len; i++)
        for(int j = 0; j < nodes; j++)
            for(int l = 0; l <= k; l++)
                for(int zero = 0; zero < 2; zero++)
                    for(int le = 0; le < 2; le++)
                        dp[i][j][l][zero][le] = 0;
    dp[0][0][0][0][0] = 1;
    for(int i = 0; i < len; i++)
        for(int j = 0; j < nodes; j++)
            for(int l = 0; l <= k; l++)
                for(int zero = 0; zero < 2; zero++)
                    for(int le = 0; le < 2; le++) {
                        for(int d = !zero; d < (le? m : r[i]); d++) {
                            int toj = trie[j].go[d],
                                tol = l + trie[toj].val;
                            if(tol <= k)
                                add(dp[i + 1][toj][tol][1][1],
                                    dp[i][j][l][zero][le]);
                        }
                        if(!zero)
                            add(dp[i + 1][j][l][zero][1],
                                dp[i][j][l][zero][le]);
                        if(!le) {
                            int toj = trie[j].go[r[i]], tol = l + trie[toj].val;
                            if(tol <= k)
                                add(dp[i + 1][toj][tol][1][le],
                                    dp[i][j][l][zero][le]);
                        }
                    }
    int res = 0;
    for(int j = 0; j < nodes; j++)
        for(int l = 0; l <= k; l++)
            add(res, dp[len][j][l][1][1]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l, r;
    cin >> l >> r;
    for(int i = (int)r.size() - 1; i >= 0; i--)
        if(r[i] + 1 == m)
            r[i] = 0;
        else {
            r[i]++;
            break;
        }
    if(r[0] == 0) {
        r[0] = 1;
        r.push_back(0);
    }
    for(int i = 0; i < n; i++)
        cin >> aa[i] >> vals[i];
    buildAho(n, m);
    cout << (solve(m, k, r) + MOD - solve(m, k, l)) % MOD << '\n';
    return 0;
}