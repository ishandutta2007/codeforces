#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

vector<pair<int, int>> tree[MAXN];

int DFS(int node, int parent) {
    int answer = 0;
    for (const auto& son: tree[node]) {
        if (son.first != parent) {
            answer = max(answer, son.second + DFS(son.first, node));
        }
    }
    return answer;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y, c; cin >> x >> y >> c;
        tree[x].push_back(make_pair(y, c));
        tree[y].push_back(make_pair(x, c));
    }
    cout << DFS(0, -1) << '\n';
}