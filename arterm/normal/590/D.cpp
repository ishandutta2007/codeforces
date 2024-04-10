#include <bits/stdc++.h>


using namespace std;

#define y1 ladsafkl
#define y2 slkdfaslkfjla

#define x first
#define y second
#define mp make_pair

typedef long double ld;

const int M = 155;
const int INF = 155000000;

int n, k, s, a[M];
int d[2][M][M * M];

void read() {
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void ini() {
    for (int j = 0; j < M; ++j)
        for (int i = 0; i < M * M; ++i) {
            d[0][j][i] = -INF;
            d[1][j][i] = INF;
        }
    d[0][0][0] = 0;
    d[1][0][0] = 0;
}

inline int fun(int id, int x, int y) {
    if (id == 0)
        return max(x, y);
    else
        return min(x, y);
}

void add(int w, int val, int id) {
    for (int j = n; j >= 1; --j)
        for (int s = n * n; s >= w; --s)
            d[id][j][s] = fun(id, d[id][j][s], d[id][j - 1][s - w] + val);
}


void kill() {
    for (int i = 0; i < k; ++i)
        add(k - i - 1, a[i], 0);
    for (int i = k; i < n; ++i)
        add(i - k, a[i], 1);
    
    for (int id = 0; id < 2; ++id)
        for (int j = 0; j <= n; ++j)
            for (int s = 1; s <= n * n; ++s)
                d[id][j][s] = fun(id, d[id][j][s], d[id][j][s - 1]);
    
    int ans = 0;
    for (int i = 0; i < k; ++i)
        ans += a[i];
    
    int sum = ans;

    for (int t = 1; t <= min(k, n - k); ++t) {
        int bon = t * (t - 1) / 2;
        for (int l = 0; l + t * t <= s && l + bon <= n * n; ++l) {
           int r = min(n * n - bon, s - t * t - l);
           ans = min(ans, sum - d[0][t][l + bon] + d[1][t][r + bon]);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(9);
    cout << fixed;

    read();
    ini();
    kill();
    return 0;
}