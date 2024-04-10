#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
int c[222][222];
int f[222][222];
int id[222];
int u[222];
int col[222];
int r[222];
int T;
int prime(int x) {
    for(int d = 2; d * d <= x; d++) {
        if(x %d == 0) return 0;
    }
    return 1;
}
bool dfs(int v) {
    if(v == n + 1) return 1;
    if(u[v] == T) return 0;
    u[v] = T;
    for(int i = 0; i <= n+1; i++) {
        if(c[v][i] > f[v][i] && dfs(i)) {
            f[v][i] ++;
            f[i][v] --;
            return 1;
        }
    }
    return 0;
}
vector<int> ord;
void dfs2(int v, int x) {
    col[v] = x;
    ord.emplace_back(r[v]);
    for(int i = 1; i <= n; i++) {
        if(col[i] == 0 && f[v][i] != 0) {
            dfs2(i, x);
        }
    }
}
void solve() {
    cin >> n;
    vector<int> e, o;
    for(int i=0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) {
            e.emplace_back(a[i]);
            id[i] = e.size();
            r[e.size()] = i;
        } else {
            o.emplace_back(a[i]);
            id[i] = o.size() + n/2;
            r[o.size() + n/2] = i;
        }
    }
    if(e.size() != o.size()) {
        cout << "Impossible\n";
        return;
    }
    for(int i = 0; i < (int)e.size(); i++) {
        for(int j = 0; j < (int)o.size(); j++) {
            if(prime(e[i] + o[j])) {
                c[i + 1][j + n/2 + 1] = 1;
            }
        }
    }
    for(int i = 1; i <= n/2; i++) {
        c[0][i] = 2;
        c[i + n/2][n + 1] = 2;
    }
    int ans = 0;
    T++;
    while(dfs(0)) {
        T++;
        ans++;
    }
    if(ans != n) {
        cout << "Impossible\n";
        return;
    }
    int sz = 0;
    vector< vector<int> > A;
    for(int i = 1; i <= n; i++) {
        if(col[i] > 0) continue;
        ++sz;
        ord.clear();
        dfs2(i, sz);
        A.emplace_back(ord);
    }
    cout << sz << "\n";
    for(auto d: A) {
        cout << d.size();
        for(int v: d) {
            cout << " "<<v + 1;
        }
        cout << "\n";
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}