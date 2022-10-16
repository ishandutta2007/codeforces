#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int N;
int p[NMAX], v[NMAX];

vector <int> graph[NMAX];

long long int ans;
bool ok;

void dfs(int node, int father) {
    for (auto it: graph[node]) {
        if (it != father) {
            dfs(it, node);
        }
    }
    if (v[node] == -1) {
        int minim = 2E9;
        for (auto it: graph[node]) {
            if (it != father) {
                minim = min(minim, v[it] - v[p[node]]);
            }
        }

        if (minim < 0) {
            ok = false;
        }

        bool added = false;
        for (auto it: graph[node]) {
            if (it != father) {
                if (!added) {
                    ans += minim;
                    added = true;
                }
                ans += v[it] - v[p[node]] - minim;
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 2; i <= N; ++i) {
        cin >> p[i];
        graph[p[i]].push_back(i);
    }
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }

    ok = true;
    ans = v[1];
    dfs(1, 0);

    if (!ok) {
        cout << "-1\n";
    }
    else {
        cout << ans << '\n';
    }
    return 0;
}