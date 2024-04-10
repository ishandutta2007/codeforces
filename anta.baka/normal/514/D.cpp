//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5, INF = 1e9;

int n, m, k, a[maxn][5], t[5][maxn][17], lg[maxn + 1];

inline int get(int l, int r) {
    int ret = 0, h = lg[r - l + 1];
    for(int i = 0; i < m; i++) ret += max(t[i][l][h], t[i][r - (1 << h) + 1][h]);
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 2; i <= maxn; i++) lg[i] = lg[i >> 1] + 1;
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) t[j][i][0] = a[i][j];
        for(int u = 1; u < 17; u++)
            for(int i = 0; i + (1 << u) - 1 < n; i++)
                t[j][i][u] = max(t[j][i][u - 1], t[j][i + (1 << (u - 1))][u - 1]);
    }
    int l = 0, r = -1;
    for(int i = 0; i < n; i++) {
        if(get(i, i) > k) continue;
        int lf = 0, rg = i;
        while(lf < rg) {
            int md = (lf + rg) >> 1;
            if(get(md, i) <= k) rg = md;
            else lf = md + 1;
        }
        if(i - lf > r - l) l = lf, r = i;
    }
    if(r == -1) {
        for(int i = 0; i < m; i++) cout << 0 << ' ';
        return 0;
    }
    int h = lg[r - l + 1];
    for(int i = 0; i < m; i++) {
        cout << max(t[i][l][h], t[i][r - (1 << h) + 1][h]) << ' ';
    }
}