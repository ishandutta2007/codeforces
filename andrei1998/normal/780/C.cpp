#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2 * 100000 + 5;

vector <int> tree[NMAX];

int colors[NMAX];
void dfs(int node, int father) {
    const int colorFather = colors[father];
    const int colorNode = colors[node];

    int last = 1;
    for (auto it: tree[node])
        if (it != father) {
            while (last == colorFather || last == colorNode)
                ++ last;
            colors[it] = last ++;
        }

    for (auto it: tree[node])
        if (it != father)
            dfs(it, node);
}

int main() {
    ios_base :: sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    colors[1] = 1;
    int val = 2;
    for (auto it: tree[1])
        colors[it] = val ++;

    for (auto it: tree[1])
        dfs(it, 1);

    int mx = 0;
    for (int i = 1; i <= N; ++ i)
        mx = max(mx, colors[i]);
    cout << mx << endl;
    for (int i = 1; i <= N; ++ i)
        cout << colors[i] << " \n"[i == N];
    return 0;
}