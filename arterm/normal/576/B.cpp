#include <bits/stdc++.h>

using namespace std;

const int M = 100100;

int n, p[M];
bool ans = false;
vector<pair<int, int>> edg;
bool used[M];
vector<vector<int>> c;

void read() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
}

void kill() {
    for (int i = 1; i <= n; ++i) 
        if (p[i] == i) {
            ans = true;
            for (int j = 1; j <= n; ++j)
                if (i != j)
                    edg.emplace_back(i, j);
            return;
        }

    for (int i = 1; i <= n; ++i)
        if (!used[i]) {
            int x = i;
            used[i] = true;
            c.push_back(vector<int>());
            c.back().push_back(x);
            while (!used[p[x]]) {
                x = p[x];
                used[x] = true;
                c.back().push_back(x);
            }
        }

    sort(c.begin(), c.end(), 
        [](const vector<int> &a, const vector<int> &b) -> bool {
            return a.size() < b.size();
        }
    );

    assert(c.front().size() >= 2);
    if (c.front().size() > 2)
        return;

    auto dim = c.front();
    edg.emplace_back(dim[0], dim[1]);

    for (int j = 1; j < (int) c.size(); ++j) {
        auto x = c[j];
        if (x.size() % 2 == 1)
            return;
        else {
            for (int i = 0; i < (int) x.size(); ++i)
                edg.emplace_back(dim[i % 2], x[i]);
        }
    }

    ans = true;
}

void finish() {
    if (!ans) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto e : edg)
            cout << e.first << " " << e.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    kill();
    finish();
    return 0;
}