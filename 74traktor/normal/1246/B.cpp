#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[100005];
int cnt[100005];
int inf = 1e9;
int go[5][1005];

int st(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        int q = st(a, b / 2);
        if (q == -1) return -1;
        if (q >= inf) return -1;
        return q * q;
    }
    int t = st(a, b - 1);
    if (t == -1) return -1;
    if (t - (inf * inf) / (double)a >= -0.00001) return -1;
    return t * a;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    set < int > used;
    for (int x = 1; x <= 100000; ++x) {
        int f = st(x, k);
        if (f == -1) break;
        used.insert(f);
    }
    for (int j = 2; j <= 3; ++j) {
        for (int i = 1; i <= 1000; ++i) go[j][i] = st(i, j);
    }
    int ans = 0;
    if (k <= 3) {
        for (int i = 1; i <= n; ++i) {
            //cout << "OK" << endl;
            int x = a[i], f = 1, j = 2;
            while (j * j <= x) {
                if (x % j == 0) {
                    int cnt = 0;
                    while (x % j == 0) {
                        x /= j;
                        cnt++;
                    }
                    for (int z = 0; z < (k - cnt % k) % k; ++z) {
                        f *= j;
                    }
                }
                ++j;
            }
            if (x != 1) {
                int cnt = 1;
                for (int z = 0; z < k - 1; ++z) f *= x;
            }
            //cout << f << endl;
            ans += cnt[f];
            for (int j = 1; go[k][j] <= a[i] && go[k][j] != -1; ++j) {
                if (a[i] % go[k][j] == 0) {
                    cnt[a[i] / go[k][j]]++;
                    //cout << "add " << i << " " << a[i] / go[j][k] << '\n';
                }
            }
        }
        cout << ans << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (auto key : used) {
            if (key % a[i] == 0 && key / a[i] <= 100000) ans += cnt[key / a[i]];
        }
        cnt[a[i]]++;
    }
    cout << ans << '\n';
    return 0;
}