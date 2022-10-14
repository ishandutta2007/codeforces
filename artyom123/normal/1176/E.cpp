#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

#define pb push_back

void dfs(int v, vector <int> &color, vector <vector<int>> &g, int now) {
    color[v] = now;
    for (auto &to : g[v]) {
        if (color[to] == 0) {
            if (now == 1) {
                dfs(to, color, g, 2);
            }
            else {
                dfs(to, color, g, 1);
            }
        }
    }
}

void print(vector <int> &a) {
    cout << a.size() << "\n";
    for (auto &c : a) {
        cout << c + 1 << " ";
    }
    cout << "\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            g[a - 1].pb(b - 1);
            g[b - 1].pb(a - 1);
        }
        vector <int> color(n);
        dfs(0, color, g, 1);
        vector <int> ans1;
        vector <int> ans2;
        for (int i = 0; i < n; i++) {
            if (color[i] == 1) {
                ans1.pb(i);
            }
            else {
                ans2.pb(i);
            }
        }
        if (ans1.size() <= ans2.size()) {
            print(ans1);
        }
        else {
            print(ans2);
        }
    }
    return 0;
}