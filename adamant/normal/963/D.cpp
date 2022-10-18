#include <bits/stdc++.h>

using namespace std;

#define link albba


const int mod = 1e9 + 9;

const int maxn = 1e5 + 42, sigma = 26;
int to[maxn][sigma], link[maxn], slink[maxn];
int sz = 1;

int add_string(string s) {
    int v = 0;
    for(auto c: s) {
        c -= 'a';
        if(!to[v][c]) {
            to[v][c] = sz++;
        }
        v = to[v][c];
    }
    slink[v] = v;
    return v;
}


int que[maxn];
int s = 0, t = 1;
void push_links() {
    while(s < t) {
        int v = que[s++];
        int u = link[v];
        if(!slink[v]) {
            slink[v] = slink[u];
        }
        for(int c = 0; c < sigma; c++) {
            if(to[v][c]) {
                link[to[v][c]] = v ? to[u][c] : 0;
                que[t++] = to[v][c];
            } else {
                to[v][c] = to[u][c];
            }
        }
    }
}

vector<int> pos[maxn];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    int que[n], ver[n];
    string str[n];
    for(int i = 0; i < n; i++) {
        int m;
        string t;
        cin >> m >> t;
        que[i] = m;
        str[i] = t;
        ver[i] = add_string(t);
    }
    push_links();
    int v = 0;
    for(int i = 0; i < s.size(); i++) {
        s[i] -= 'a';
        v = to[v][s[i]];
        for(int u = slink[v]; u; u = slink[link[u]]) {
            pos[u].push_back(i);
        }
    }
    int ans[n];
    for(int i = 0; i < n; i++) {
        ans[i] = -1;
        int v = ver[i];
        for(int j = que[i] - 1; j < pos[v].size(); j++) {
            int len = pos[v][j] - pos[v][j - (que[i] - 1)] + int(str[i].size());
            if(ans[i] == -1 || ans[i] > len) {
                ans[i] = len;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
}