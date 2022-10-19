#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G(1, {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1});
vector<int> p(1, -1);

void add(string & s, int num) {
    int cur = 0;
    for (char i : s) {
        if (G[cur][i - '0'] == -1) {
            G[cur][i - '0'] = G.size();
            G.push_back({-1,-1,-1,-1,-1,-1,-1,-1,-1,-1});
            p.push_back(-1);
        }
        cur = G[cur][i - '0'];
        if (p[cur] == -1)
            p[cur] = num;
        if (p[cur] != num)
            p[cur] = -2;
    }
}

vector<string> ans;
string cur_s = "";

void dfs(int v) {
    //cout << cur_s << ' ' << p[v] << endl;
    if (p[v] != -1 && p[v] != -2)
        if (ans[p[v]] == "kek" || ans[p[v]].size() > cur_s.size())
            ans[p[v]] = cur_s;
    for (int i = 0; i <= 9; ++i)
        if (G[v][i] != -1) {
            cur_s.push_back('0' + i);
            dfs(G[v][i]);
            cur_s.pop_back();
        }
}

int main() {
    int n;
    cin >> n;
    ans.resize(n, "kek");
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int t = 0; t < 9; ++t) {
            add(s, i);
            //cout << "added " << s << endl;
            reverse(s.begin(), s.end());
            s.pop_back();
            reverse(s.begin(), s.end());
        }
    }
    dfs(0);
    for (string i : ans)
        cout << i << endl;
}