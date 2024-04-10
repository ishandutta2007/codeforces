#include <bits/stdc++.h>
 
using namespace std;

const int N = 1e6 + 10;

typedef pair <string, int> pii;

#define x first
#define y second

string s;
vector <string> dep[N];
pii p[N];
int m = 0, mx = -1;
stack <pii> st;
int l[N], r[N];
bitset <N> vis;
int pointer;

void dfs (int u, int deep) {
    vis[u] = 1;
    mx = max(mx, deep);
    dep[deep].push_back(p[u].x);
    for (int j = 0; j < p[u].y; ++j) {
        dfs(++pointer, deep + 1);
    }
}

int main (int argc, char const *argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> s;
    s += ',';
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        pii z;
        z.x = "";
        z.y = 0;
        int j = i;
        while (j < n and s[j] != ',') {
            z.x += s[j];
            ++j;
        }
        ++j;
        while (j < n and s[j] != ',') {
            z.y *= 10, z.y += (s[j] - '0');
            ++j;
        }
        i = j;
        p[++m] = z;
    }
    for (int i = 1; i <= m; ++i) {
        // cout << p[i].x << " " << p[i].y << endl;
        l[i] = i + 1;
        r[i] = i + p[i].y;
    }
    for (int i = 1; i <= m; ++i) {
        if (!vis[i]) {
            pointer = i;
            dfs(i, 1);
        }
    }
    cout << mx << '\n';
    for (int i = 1; i <= mx; ++i) {
        for (int j = 0; j < (int) dep[i].size(); ++j) {
            cout << dep[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}