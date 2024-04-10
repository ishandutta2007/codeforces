#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIGMA = 26;

struct Node {
    int go[SIGMA];
    vector<int> v[2];
};

const int MAXN = 100 * 1000 + 5, MAXLEN = 800 * 1000 + 5;
char used[2][MAXN];
int ans[MAXN], freeNode;
Node trie[MAXLEN];

int newNode() {
    for(int i = 0; i < SIGMA; i++)
        trie[freeNode].go[i] = -1;
    return freeNode++;
}

void add(string &s, int id, int t) {
    int v = 0;
    trie[v].v[t].push_back(id);
    for(size_t i = 0; i < s.length(); i++) {
        if(trie[v].go[s[i] - 'a'] == -1)
            trie[v].go[s[i] - 'a'] = newNode();
        v = trie[v].go[s[i] - 'a'];
        trie[v].v[t].push_back(id);
    }
}

int dfs(int v, int dep) {
    int res = 0;
    for(int i = 0; i < SIGMA; i++)
        if(trie[v].go[i] != -1)
            res += dfs(trie[v].go[i], dep + 1);
    vector<int> vec[2];
    for(int i = 0; i < 2; i++)
        for(size_t j = 0; j < trie[v].v[i].size(); j++)
            if(!used[i][trie[v].v[i][j]])
                vec[i].push_back(trie[v].v[i][j]);
    int k = min(vec[0].size(), vec[1].size());
    res += dep * k;
    for(int i = 0; i < k; i++) {
        ans[vec[0][i]] = vec[1][i];
        used[0][vec[0][i]] = true;
        used[1][vec[1][i]] = true;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    newNode();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(s, i, 0);
    }
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(s, i, 1);
    }
    cout << dfs(0, 0) << '\n';
    for(int i = 0; i < n; i++)
        cout << i + 1 << ' ' << ans[i] + 1 << '\n';
    return 0;
}