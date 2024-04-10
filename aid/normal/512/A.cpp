#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 105, SIGMA = 26;
char used[SIGMA];
string s[MAXN];
vector<int> g[SIGMA], ans;
bool bad = false;

void dfs(int v) {
    used[v] = 1;
    for(size_t i = 0; i < g[v].size(); i++)
        if(used[g[v][i]] == 1)
            bad = true;
        else if(!used[g[v][i]])
            dfs(g[v][i]);
    used[v] = 2;
    ans.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n - 1; i++) {
        int pos = 0;
        while(pos < (int)s[i].length() && pos < (int)s[i + 1].length() &&
              s[i][pos] == s[i + 1][pos])
            pos++;
        if(pos == (int)s[i].length())
            continue;
        if(pos == (int)s[i + 1].length()) {
            cout << "Impossible\n";
            return 0;
        }
        g[s[i][pos] - 'a'].push_back(s[i + 1][pos] - 'a');
    }
    for(int i = 0; i < SIGMA; i++)
        if(!used[i])
            dfs(i);
    if(bad) {
        cout << "Impossible\n";
        return 0;
    }
    for(int i = SIGMA - 1; i >= 0; i--)
        cout << char(ans[i] + 'a');
    cout << '\n';
    return 0;
}