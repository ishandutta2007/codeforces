#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define ll long long
#define int long long
#define ld long double
#define pii pair <int , int>
#define pll pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

const int maxn = 1e3 + 1 , N = 1e6 + 1 , SQ = 600 , base = 1999 , mod = 1e9 + 7 , INF = 1e18 , lg = 17;

int n , k , sz , cyclenumber , input[maxn];
vector <int> edges[30];
string s[maxn][maxn] , d[N];
bool mark[maxn];
bool vis[maxn];

void dfs(int v , int p) {
    mark[v] = 1;
    for (int u : edges[v]) {
        if (u == p) {
            ++cyclenumber;
        }
        if(!mark[u]) {
            dfs(u , p);
        }
    }
}

int32_t main() {
    FAST;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int page; cin >> page;
        for (int j = 0; j < k; ++j) {
            cin >> s[page][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            d[sz++] = s[i][j];
        }
    }
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < d[i].size(); ++j) {
            vis[d[i][j] - 'a'] = 1;
        }
    }
    for (int i = 0; i < sz - 1; ++i) {
        int idx = 0;
        string a = d[i] , b = d[i + 1];
        while(a[idx] == b[idx] && idx < a.size() && idx < b.size()) {
            idx++;
        }
        if(idx < a.size() && idx < b.size()) {
            edges[a[idx] - 'a'].PB(b[idx] - 'a');
            input[b[idx] - 'a']++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        dfs(i , i);
        fill (mark , mark + maxn , 0);
    }

    bool check1 = 0 , check2 = 0;

    for (int i = 0; i < sz - 1; ++i) {
        if(d[i].size() > d[i + 1].size()) {
            check1 = 1;
            int idx = 0;
            string a = d[i] , b = d[i + 1];
            while(a[idx] == b[idx] && idx < a.size() && idx < b.size()) {
                idx++;
            }
            if(idx == b.size()) {
                check2 = 1;
                break;
            }
        }
    }

    if (cyclenumber > 0 || (check1 && check2)) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        queue <int> q;
        for (int i = 0; i < 26; ++i) {
            if (input[i] == 0 && vis[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            for (int v : edges[u]) {
                input[v]--;
                if (input[v] == 0) {
                    q.push(v);
                }
            }
            cout << char(u + 'a');
            q.pop();
        }
        cout << '\n';
    }
}