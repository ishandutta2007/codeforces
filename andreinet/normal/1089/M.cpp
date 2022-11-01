#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int gr[9][9];
int g2[9][9];
bool used[9];
vector<int> order;
int cc[9];
int ccsize[9];
vector<int> cc_nodes[9];

void dfs1(int node) {
    used[node] = true;
    for (int i = 0; i < 9; ++i) {
        if (gr[node][i] && !used[i]) {
            dfs1(i);
        }
    }
    order.push_back(node);
}

void dfs2(int node, int curr_cc) {
    used[node] = false;
    cc[node] = curr_cc;
    ccsize[curr_cc]++;
    cc_nodes[curr_cc].push_back(node);
    for (int i = 0; i < 9; ++i) {
        if (gr[i][node] && used[i]) {
            dfs2(i, curr_cc);
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

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> gr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    int ncc = 0;
    for (int i = n - 1; i >= 0; --i) {
        int node = order[i];
        if (used[node]) {
            dfs2(node, ncc++);
        }
    }
    int r = 5, c = ncc * 5 + (n - ncc), z = ncc * 2;
    cout << c << ' ' << r << ' ' << z << '\n';
    vector<vector<string>> a(z, vector<string>(r, string(c, '.')));
    for (int i = 1; i < z; i += 2) {
        fill(a[i].begin(), a[i].end(), string(c, '#'));
    }
    for (int i = 0, have = 0; i < ncc; ++i) {
        for (int j = 0; j < z; j += 2) {
            for (int p = 1; p <= ccsize[i]; ++p) {
                a[j][1][have + p + 1] = '#';
                a[j][3][have + p + 1] = '#';
                a[j + 1][2][have + p + 1] = '.';
            }
            a[j][1][have + 1] = '#';
            a[j][2][have + 1] = '#';
            a[j][3][have + 1] = '#';
            a[j][1][have + ccsize[i] + 2] = '#';
            a[j][2][have + ccsize[i] + 2] = '#';
            a[j][3][have + ccsize[i] + 2] = '#';
        }
        have += 4 + ccsize[i];
    }
    for (int i = 0, have = 0; i < ncc; ++i) {
        for (int p = 1; p <= ccsize[i]; ++p) {
            a[2 * i + 1][2][have + p + 1] = '#';
            a[2 * i][2][have + p + 1] = (char) (cc_nodes[i][p - 1] + '1');
        }
        a[2 * i][2][have + 1] = '.';
        have += 4 + ccsize[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (gr[i][j] && cc[i] != cc[j]) {
                g2[cc[i]][cc[j]] = 1;
            }
        }
    }
    
    for (int i = 0, have = 0; i < ncc; ++i) {
        for (int k = 0; k < i; ++k) {
            if (g2[k][i]) {
                a[2 * k][2][have + 1] = '.';
            }
        }
        have += 4 + ccsize[i];
    }
    for (auto& m: a) {
        for (auto& row: m) {
            cout << row << '\n';
        }
        cout << '\n';
    }
}