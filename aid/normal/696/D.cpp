#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int SIGMA = 26;

struct Node {
    int go[SIGMA], val, link;
};

const int MAXN = 205;
Node trie[MAXN];
int vals[MAXN], freeNode;
long long a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
string s[MAXN];

int newNode() {
    for(int i = 0; i < SIGMA; i++)
        trie[freeNode].go[i] = -1;
    trie[freeNode].val = 0;
    trie[freeNode].link = -1;
    return freeNode++;
}

void add(const string &s, int val) {
    int v = 0;
    for(size_t i = 0; i < s.length(); i++) {
        if(trie[v].go[s[i] - 'a'] == -1)
            trie[v].go[s[i] - 'a'] = newNode();
        v = trie[v].go[s[i] - 'a'];
    }
    trie[v].val += val;
}

void buildAho(int n) {
    freeNode = 0;
    newNode();
    for(int i = 0; i < n; i++)
        add(s[i], vals[i]);
    queue<int> q;
    for(int i = 0; i < SIGMA; i++)
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
        for(int i = 0; i < SIGMA; i++)
            if(trie[v].go[i] == -1)
                trie[v].go[i] = trie[trie[v].link].go[i];
            else {
                trie[trie[v].go[i]].link = trie[trie[v].link].go[i];
                q.push(trie[v].go[i]);
            }
    }
}

void matPow(int n, long long p) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            b[i][j] = (i == j? 0 : -1);
    while(p) {
        if(p & 1) {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++) {
                    c[i][j] = -1;
                    for(int k = 0; k < n; k++)
                        if(b[i][k] != -1 && a[k][j] != -1)
                            c[i][j] = max(c[i][j], b[i][k] + a[k][j]);
                }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    b[i][j] = c[i][j];
        }
        p >>= 1ll;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                c[i][j] = -1;
                for(int k = 0; k < n; k++)
                    if(a[i][k] != -1 && a[k][j] != -1)
                        c[i][j] = max(c[i][j], a[i][k] + a[k][j]);
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = c[i][j];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = b[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long l;
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        cin >> vals[i];
    for(int i = 0; i < n; i++)
        cin >> s[i];
    buildAho(n);
    int m = freeNode;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            a[i][j] = -1;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < SIGMA; j++)
            a[i][trie[i].go[j]] = trie[trie[i].go[j]].val;
    matPow(m, l);
    long long ans = a[0][0];
    for(int i = 1; i < m; i++)
        ans = max(ans, a[0][i]);
    cout << ans << '\n';
    return 0;
}