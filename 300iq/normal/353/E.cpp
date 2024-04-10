#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 1e6 + 7;
int in[MAXN];
int out[MAXN];
vector <int> g[MAXN];
vector <int> gr[MAXN];
bool used[MAXN];

void dfs(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        dfs(to);
    }
}

void ds(int v) {
    used[v] = 1;
    for (auto to : gr[v]) {
        ds(to);
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '0') {
            g[i].pb((i + 1) % n);
            gr[(i + 1) % n].pb(i);
        } else {
            g[(i + 1) % n].pb(i);
            gr[i].pb((i + 1) % n);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i] && g[i].size() > 0 && gr[i].size() > 0) {
            dfs(i), ds(i), ans++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i), ds(i), ans++;
        }
    }
    printf("%d\n", ans);
}