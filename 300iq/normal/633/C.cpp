#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1100000;
int to[MAXV][26];
bool leaf[MAXV];
int num[MAXV];
string guy[100000];
int dp[10000];
int sz = 1;

void add(string s, int i) {
    int v = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (to[v][s[i] - 'a'] == 0) {
            to[v][s[i] - 'a'] = sz++;
        }
        v = to[v][s[i] - 'a'];
    }
    leaf[v] = 1;
    num[v] = i;
}
int main() {
    int n, m;
    string s, f;
    cin >> n;
    cin >> s;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> f;
        guy[i] = f;
        string p = f;
        reverse(p.begin(), p.end());
        for (int i = 0; i < (int) p.size(); i++) {
            p[i] = tolower(p[i]);
        }
        add(p, i);
    }
    memset(dp, -1, sizeof dp);
    int v = 0;
    for (int j = 0; j < n; j++) {
        if (to[v][s[j] - 'a'] == 0) {
            break;
        } else {
            v = to[v][s[j] - 'a'];
            if (leaf[v]) {
                dp[j] = num[v];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int v = 0;
        if (dp[i] == -1) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (to[v][s[j] - 'a'] == 0) {
                break;
            } else {
                v = to[v][s[j] - 'a'];
                if (leaf[v]) {
                    dp[j] = num[v];
                }
            }
        }
    }
    int cur = n - 1;
    stack <string> ans;
    while (cur > -1) {
        ans.push(guy[dp[cur]]);
        cur = cur - (int) guy[dp[cur]].size();
    }
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}