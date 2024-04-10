#include <bits/stdc++.h>

using namespace std;

int n, m, k, q;
int x[250000], y[250000], t[250000];
int a[500][500];

bool can(int tt) {
    memset(a, 0, sizeof(a));
    for(int i = 0; i < q; i++)
        if(t[i] <= tt)
            a[x[i]][y[i]] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(i) a[i][j] += a[i - 1][j];
            if(j) a[i][j] += a[i][j - 1];
            if(i && j) a[i][j] -= a[i - 1][j - 1];
            if(i + 1 < k || j + 1 < k) continue;
            int s = a[i][j];
            if(i + 1 != k) s -= a[i - k][j];
            if(j + 1 != k) s -= a[i][j - k];
            if(i + 1 != k && j + 1 != k) s += a[i - k][j - k];
            if(s == k * k) return true;
        }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> k >> q;
    for(int i = 0; i < q; i++) cin >> x[i] >> y[i] >> t[i], x[i]--, y[i]--;
    if(!can(1e9)) return cout << -1, 0;
    int bl = 0, br = 1e9;
    while(bl < br) {
        int bm = (bl + br) / 2;
        if(can(bm)) br = bm;
        else bl = bm + 1;
    }
    cout << bl;
}