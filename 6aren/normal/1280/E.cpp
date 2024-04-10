#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 320005;
const string out = "REVOLTING";

int r;
string s;
int n;
vector<int> g[4 * N];
int cnt[4 * N], type[4 * N];
int sz[4 * N], check[4 * N];
long long res[4 * N];

void dfs(int u) {
    if (type[u] == 0) {
        sz[u] = 1;
        return;
    } 
    int c1 = g[u][0];
    int c2 = g[u][1];
    dfs(c1);
    dfs(c2);
    if (type[u] == 1) {
        if (sz[c1] > sz[c2]) {
            sz[u] = sz[c2];
            check[c1] = 0;
        } else {
            sz[u] = sz[c1];
            check[c2] = 0;
        }
    } else if (type[u] == 2) {
        sz[u] = sz[c1] + sz[c2];
    }
}

void dfs2(int u, long long val) {
    if (type[u] == 0) {
        res[u] = val * check[u];
        return;
    }
    int c1 = g[u][0];
    int c2 = g[u][1];
    res[c1] = val * check[c1];
    res[c2] = val * check[c2];
    dfs2(c1, val * check[c1]);
    dfs2(c2, val * check[c2]);
}

void solve() {
    cin >> r;
    getline(cin, s);
    if (s.size() == 2) {
        cout << out << ' ' << r << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        type[i] = 0;
    }
    n = 0;
    stack<int> st;
    stack<int> st2;
    int cur = 0;
    for (auto u : s) {
        if (u == '(') {
            n++;
            st2.push(n);
            st.push(n);
        } 
        if (u == '*') {
            n++;
            cnt[++cur] = n;
            g[st.top()].pb(n);
        }
        if (u == 'S') {
            if (g[st.top()].size() < 2) type[st.top()] = 1;
            else {
                n++;
                int v = g[st.top()][1];
                g[st.top()][1] = n;
                type[n] = 1;
                g[n].pb(v);
                st.push(n);
            }
        }
        if (u == 'P') {
            if (g[st.top()].size() < 2) type[st.top()] = 2;
            else {
                n++;
                int v = g[st.top()][1];
                g[st.top()][1] = n;
                type[n] = 2;
                g[n].pb(v);
                st.push(n);
            }
        }
        if (u == ')') {
            while (st.top() != st2.top()) {
                st.pop();
            }
            int v = st.top();
            st.pop();
            st2.pop();
            if (st.size()) g[st.top()].pb(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        check[i] = 1;
    }
    dfs(1);
    dfs2(1, 1LL * sz[1] * r);
    cout << out << ' ';
    cur = 0;
    for (auto u : s) {
        if (u == '*') {
            cur++;
            //cout << cnt[cur] << endl;
            cout << res[cnt[cur]] << ' ';
        }
    }
    cout << '\n';
    // for (int i = 1; i <= n; i++) {
    //     cout << i << " : ";
    //     for (auto u : g[i]) {
    //         cout << u << ' ';
    //     }
    //     cout << type[i] << ' ' << check[i];
    //     cout << endl;
    // }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
    return 0;
}