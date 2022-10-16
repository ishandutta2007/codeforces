#include <iostream>
#include <string>

using namespace std;

const int SIGMA = 4;

struct Node {
    Node *go[SIGMA];

    Node() {
        for(int i = 0; i < SIGMA; i++)
            go[i] = 0;
    }
};

const int K = 10;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
long long dp[SIGMA][SIGMA], dppow2[SIGMA][SIGMA],
    dppow[SIGMA][SIGMA], mulRes[SIGMA][SIGMA];
string path;

Node *go(Node *v, char c) {
    if(!v->go[c - 'A'])
        v->go[c - 'A'] = new Node;
    return v->go[c - 'A'];
}

void dfs(Node *v) {
    int d = path.length();
    for(int i = 0; i < SIGMA; i++)
        if(v->go[i]) {
            path += char('A' + i);
            dfs(v->go[i]);
            path = path.substr(0, d);
        }
        else {
            dp[path[0] - 'A'][i] = min(dp[path[0] - 'A'][i], (long long)d);
            for(int j = 0; j < SIGMA; j++)
                dp[path[0] - 'A'][j] = min(dp[path[0] - 'A'][j],
                                           (long long)(d + 1));
        }
}

void matMul(long long a[SIGMA][SIGMA], long long b[SIGMA][SIGMA]) {
    for(int i = 0; i < SIGMA; i++)
        for(int j = 0; j < SIGMA; j++) {
            mulRes[i][j] = INF;
            for(int k = 0; k < SIGMA; k++)
                mulRes[i][j] = min(mulRes[i][j], a[i][k] + b[k][j]);
        }
}

void matPow(long long p) {
    for(int i = 0; i < SIGMA; i++)
        for(int j = 0; j < SIGMA; j++)
            dppow[i][j] = 0;
    for(int i = 0; i < SIGMA; i++)
        for(int j = 0; j < SIGMA; j++)
            dppow2[i][j] = dp[i][j];
    while(p) {
        if(p & 1) {
            matMul(dppow, dppow2);
            for(int i = 0; i < SIGMA; i++)
                for(int j = 0; j < SIGMA; j++)
                    dppow[i][j] = mulRes[i][j];
        }
        matMul(dppow2, dppow2);
        for(int i = 0; i < SIGMA; i++)
            for(int j = 0; j < SIGMA; j++)
                dppow2[i][j] = mulRes[i][j];
        p >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    long long n;
    string t;
    cin >> n >> t;
    int m = t.length();
    Node *root = new Node;
    for(int i = 0; i < m; i++) {
        Node *v = root;
        for(int j = i; j < m && j < i + K; j++)
            v = go(v, t[j]);
    }
    for(int i = 0; i < SIGMA; i++)
        for(int j = 0; j < SIGMA; j++)
            dp[i][j] = K;
    dfs(root);
    long long l = 0, r = n;
    while(l < r - 1) {
        long long mid = (l + r) / 2;
        matPow(mid);
        bool b = true;
        for(int i = 0; i < SIGMA; i++)
            for(int j = 0; j < SIGMA; j++)
                if(dppow[i][j] < n)
                    b = false;
        if(b)
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
    return 0;
}