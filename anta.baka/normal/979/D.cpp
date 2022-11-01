#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5, INF = 1e9;

int q;
vector<int> d[maxn];
bool was[maxn];
vector<vector<int>> t0(maxn, vector<int>(1, -1)), t1(maxn, vector<int>(1, -1));
vector<vector<int>> lo(maxn, vector<int>(1, INF));

inline void add(int x, int pos) { //  x   t[pos]
    int v = 0;
    lo[pos][v] = min(lo[pos][v], x);
    for(int i = 16; i >= 0; i--)
        if(x & (1 << i)) {
            if(t1[pos][v] == -1) {
                t1[pos][v] = sz(t0[pos]);
                t0[pos].push_back(-1);
                t1[pos].push_back(-1);
                lo[pos].push_back(INF);
            }
            v = t1[pos][v];
            lo[pos][v] = min(lo[pos][v], x);
        } else {
            if(t0[pos][v] == -1) {
                t0[pos][v] = sz(t0[pos]);
                t0[pos].push_back(-1);
                t1[pos].push_back(-1);
                lo[pos].push_back(INF);
            }
            v = t0[pos][v];
            lo[pos][v] = min(lo[pos][v], x);
        }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    for(int i = 1; i <= maxn; i++)
        for(int j = i; j <= maxn; j += i)
            d[j - 1].push_back(i);
    cin >> q;
    while(q--) {
        int ty; cin >> ty;
        if(ty == 1) {
            int u; cin >> u;
            if(!was[u - 1]) {
                was[u - 1] = true;
                for(int x : d[u - 1]) add(u, x - 1);
            }
        } else {
            int x, k, s; cin >> x >> k >> s;
            if(x % k || lo[k - 1][0] > s - x) {
                cout << -1 << '\n';
                continue;
            }
            int v = 0, cur = 0;
            for(int i = 16; i >= 0; i--) {
                int to = 1;
                if(x & (1 << i)) to = 0;
                if(to) {
                    if(t1[k - 1][v] == -1 || lo[k - 1][t1[k - 1][v]] > s - x) to = !to;
                } else {
                    if(t0[k - 1][v] == -1 || lo[k - 1][t0[k - 1][v]] > s - x) to = !to;
                }
                cur = cur * 2 + to;
                if(to) v = t1[k - 1][v];
                else v = t0[k - 1][v];
            }
            cout << cur << '\n';
        }
    }

//    for(int i = 1; i <= maxn; i++)
//        for(int j = i; j <= maxn; j += i)
//            d[j - 1].push_back(i);
//    for(int u = 1; u <= maxn; u++) {
//            if(!was[u - 1]) {
//                was[u - 1] = true;
//                for(int x : d[u - 1]) add(u, x - 1);
//            }
//    }
//    cout << (.0 + clock()) / CLOCKS_PER_SEC;
}