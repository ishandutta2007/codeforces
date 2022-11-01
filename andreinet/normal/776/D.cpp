#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005;

vector<int> S[NMAX], D[NMAX];
int A[NMAX];
bool usedS[NMAX], usedD[NMAX];

int values[NMAX];

void dfsGetS(int, vector<int>&, vector<int>&);

void dfsGetD(int node, vector<int>& nodes, vector<int>& ed) {
    usedD[node] = true;
    ed.push_back(node);
    for (int to: D[node]) {
        if (!usedS[to]) {
            dfsGetS(to, nodes, ed);
        }
    }
}

void dfsGetS(int node, vector<int>& nodes, vector<int>& ed) {
    usedS[node] = true;
    nodes.push_back(node);
    for (int to: S[node]) {
        if (!usedD[to]) {
            dfsGetD(to, nodes, ed);
        }
    }
}

void dfsPutS(int);

void dfsPutD(int node) {
    usedD[node] = true;
    for (int to: D[node]) {
        if (!usedS[to]) {
            dfsPutS(to);
        }
    }
}

void dfsPutS(int node) {
    int cval = A[node];
    usedS[node] = true;
    for (int to: S[node]) {
        if (usedD[to]) {
            cval ^= values[to];
        }
    }
    for (int to: S[node]) {
        if (!usedD[to]) {
            values[to] = cval;
            dfsPutD(to);
        }
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

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        A[i] ^= 1;
    }
    for (int i = 1; i <= m; ++i) {
        int k;
        cin >> k;
        D[i] = vector<int>(k);
        for (int& p: D[i]) {
            cin >> p;
            S[p].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!usedS[i] && A[i] == 1) {
            vector<int> nodes, ed;
            dfsGetS(i, nodes, ed);
            bool ok = false;
            for (int put: {0, 1}) {
                for (int p: ed) {
                    usedD[p] = false;
                }
                for (int p: nodes) {
                    usedS[p] = false;
                }
                usedD[S[i][put]] = true;
                values[S[i][put]] = 1;
                dfsPutS(i);
                dfsPutD(S[i][put]);
                bool worked = true;
                for (int node: nodes) {
                    int cval = A[node];
                    for (int to: S[node]) {
                        cval ^= values[to];
                    }
                    if (cval) {
                        worked = false;
                        break;
                    }
                }
                if (worked) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}