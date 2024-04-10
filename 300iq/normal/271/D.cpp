#include <bits/stdc++.h>

using namespace std;

const int MAXV = 2500000;

bool cost[26];

int to[MAXV][26];
bool mark[MAXV];
int sz = 0;
int k;

void add(string s) {
    int v = 0;
    for (int i = 0; i < (int) s.length(); i++) {
        if (to[v][s[i] - 'a'] == -1)
            to[v][s[i] - 'a'] = ++sz;
        v = to[v][s[i] - 'a'];
    }
}

void dfs(int v, int cnt) {
    if (cnt <= k) mark[v] = 1;
    for (int i = 0; i < 26; i++) 
        if (to[v][i] != -1)
            dfs(to[v][i], cnt + cost[i]);
}

int main() {
    for (int i = 0; i < MAXV; i++) 
        for (int j = 0; j < 26; j++)
            to[i][j] = -1;
    string s, ct;
    cin >> s;
    cin >> ct;
    cin >> k;
    for (int i = 0; i < (int) ct.length(); i++) 
        cost[i] = (ct[i] == '0' ? 1 : 0);
    string t = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        t = s[i] + t;
        add(t);
    }
    dfs(0, 0);
    int ans = 0;
    for (int i = 1; i < MAXV; i++)
        ans += mark[i];
    cout << ans << endl;
}