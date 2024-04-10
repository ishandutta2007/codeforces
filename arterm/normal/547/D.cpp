#include <bits/stdc++.h>

using namespace std;

const int M = 500500;

int n;
map<pair<int, int>, int> num;
vector<int> g[M];
int even = 0, odd = 1;
set<pair<int, int>> used;
int col[M];

void read() {
    cin >> n;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        x = 2 * x + 1;
        y = 2 * y + 2;
        g[x].push_back(y);
        g[y].push_back(x);
        num[make_pair(x, y)] = num[make_pair(y, x)] = i + 1;
    }
}

void modify() {
    for (int i = 1; i < M; i += 2)
        if (g[i].size() % 2 == 1) {
            g[odd].push_back(i);
            g[i].push_back(odd);
        }

    for (int i = 2; i < M; i += 2)
        if (g[i].size() % 2 == 1) {
            g[even].push_back(i);
            g[i].push_back(even);
        }

    if (g[odd].size() % 2 == 1) {
        g[odd].push_back(even);
        g[even].push_back(odd);
    }
}

void euler(int v, int color) {
    while (!g[v].empty() && used.find(make_pair(g[v].back(), v)) != used.end()) {
        g[v].pop_back();
    }
    if (!g[v].empty()) {
        int to = g[v].back();
        g[v].pop_back();
        used.emplace(v, to);
        col[num[make_pair(v, to)]] = color;
        euler(to, 1 - color);
    }
}

int main() {
    read();
    modify();
    for (int i = 0; i < M; ++i)
        if (!g[i].empty())
            euler(i, 0);
    for (int i = 1; i <= n; ++i)
        cout << (col[i] ? "r":"b");
    cout << "\n";
    return 0;
}