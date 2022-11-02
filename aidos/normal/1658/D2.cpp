#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
string s;
const  int mod = 998244353;
int b[maxn];
int cnt[2][17][2][17];
int cnt2[2][17][2][17];
int bit(int x, int k) {
    return (x>>k) & 1;
}
vector<int> g[44], gr[44];
void add_edge(int u, int v) {
    gr[u].push_back(v);
    g[v].push_back(u);
}
int used[44];
int comp[44];
vector<int> ord;
void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    ord.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gr[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

int solve_2SAT() {
    int n = 17 * 2;
    ord.clear();
    for(int i = 0; i < n; i++) {
        used[i] = 0;
        comp[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }
    for (int i = 0, j = 0; i < n; ++i) {
        int v = ord[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }
    int ans=  0;
    for (int i = 0; i < n; i += 2) {
        if(comp[i] == comp[i+1]) return -1;
        if(comp[i] > comp[i + 1]) {
            ans |= (1<<(i/2));
        }
    }
    return ans;
}
void solve(){
    int l, r;
    cin>>l>>r;
    n = r-l+1;
    int cur = 0;
    ord.clear();
    for(int i = 0; i < 40; i++) {
        g[i].clear();
        gr[i].clear();
    }
    memset(cnt, 0, sizeof cnt);
    memset(cnt2, 0, sizeof cnt2);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = i + l;
        for(int j = 0; j < 17; j++) {
            for(int k = 0; k < 17; k++) {
                cnt[bit(a[i], j)][j][bit(a[i], k)][k]++;
            }
        }
        for(int j = 0; j < 17; j++) {
            for(int k = 0; k < 17; k++) {
                cnt2[bit(b[i], j)][j][bit(b[i], k)][k]++;
            }
        }
    }
    for(int i = 0; i < 17; i++) {
        if(cnt[0][i][0][i] != cnt2[0][i][0][i] || cnt[1][i][1][i] != cnt2[1][i][1][i] ) {
            add_edge(i * 2 + 0, i * 2 + 1);
        }
        if(cnt[0][i][0][i] != cnt2[1][i][1][i] || cnt[1][i][1][i] != cnt2[0][i][0][i] ) {
            add_edge(i * 2 + 1, i * 2 + 0);
        }
    }
    for(int i = 0; i < 17; i++) {
        for(int t = 0; t < 2; t++) {
            for(int k = 0; k < 17; k++) {
                if(i == k) {
                    continue;
                }
                int bad = 0;
                for(int j = 0; j < 2; j++) {

                    for(int x = 0; x < 2; x++) {
                        if (cnt[x][i][j][k] != cnt2[x ^ t][i][j][k]) {
                            bad = 1;
                        }
                    }
                }

                if(bad) {
                    add_edge(i * 2 + t, k * 2 + 1);
                }
                bad = 0;
                for(int j = 0; j < 2; j++) {

                    for(int x = 0; x < 2; x++) {
                        if (cnt[x][i][j][k] != cnt2[x ^ t][i][j^1][k]) {
                            bad = 1;
                        }
                    }
                }

                if(bad) {
                    add_edge(i * 2 + t, k * 2 + 0);
                }
            }
        }
    }
    int d = solve_2SAT();
    cout << d << "\n";
    return;
    for(int i = 0; i < n; i++) {
        cout << (a[i]^d) << " ";
    }
    cout << "\n";
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}