#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> a, b;
vector <int> ord;
vector <bool> used;
vector <int> col;
int now = 0;
void r(int i, int j) {
    a[i^1].push_back(j);
    a[j^1].push_back(i);
    b[j].push_back(i^1);
    b[i].push_back(j^1);
}
void topsort(int v) {
    used[v] = true;
    for (int i : a[v]) {
        if (!used[i]) {
            topsort(i);
        }
    }
    ord.push_back(v);
}

void dfs(int v) {
    used[v] = true;
    col[v] = now;
    for (int i : b[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
}
signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    a.resize(2 * n);
    b.resize(2 * n);
    used.resize(2 * n);
    col.resize(2 * n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] > s[j]) {
                r(2 * i, 2 * j);
                r(2 * i + 1, 2 * j + 1);
            }
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (!used[i]) {
            topsort(i);
        }
    }
    reverse(ord.begin(), ord.end());
    used.assign(2 * n, false);
    for (int i : ord) {
        if (!used[i]) {
            dfs(i);
            ++now;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (col[2 * i] == col[2 * i + 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (col[2 * i] < col[2 * i + 1]) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    return 0;
}