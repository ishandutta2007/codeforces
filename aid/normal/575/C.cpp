#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 25, MAXX = 1000 * 1000, INF = 1000 * 1000 * 1000 + 5;
int aa[2][MAXN][MAXN], a[MAXN][MAXN], v[MAXN][MAXN], u[MAXN][MAXN],
    p[MAXN][MAXN], prev[MAXN], minv[MAXN];
char used[MAXN];

void add(int t, int n, int row) {
    for(int i = 0; i <= n; i++) {
        minv[i] = INF;
        used[i] = false;
    }
    int cur = n;
    p[t][cur] = row;
    while(p[t][cur] != -1) {
        used[cur] = true;
        int nxt = -1;
        for(int i = 0; i <= n; i++)
            if(!used[i]) {
                if(minv[i] > a[p[t][cur]][i] - v[t][p[t][cur]] - u[t][i]) {
                    minv[i] = a[p[t][cur]][i] - v[t][p[t][cur]] - u[t][i];
                    prev[i] = cur;
                }
                if(nxt == -1 || minv[i] < minv[nxt])
                    nxt = i;
            }
        int delta = minv[nxt];
        for(int i = 0; i <= n; i++)
            if(used[i]) {
                v[t][p[t][i]] += delta;
                u[t][i] -= delta;
            }
            else
                minv[i] -= delta;
        cur = nxt;
    }
    while(cur < n) {
        p[t][cur] = p[t][prev[cur]];
        cur = prev[cur];
    }
}

int gen(int pos, int bal, int n) {
    if(abs(bal) > n - pos)
        return INF;
    if(pos == n)
        return -u[pos][n];
    int res = INF;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++)
            a[pos][j] = aa[i][pos][j];
        for(int j = 0; j <= n; j++) {
            v[pos + 1][j] = v[pos][j];
            u[pos + 1][j] = u[pos][j];
            p[pos + 1][j] = p[pos][j];
        }
        add(pos + 1, n, pos);
        res = min(res, gen(pos + 1, bal + (i? 1 : -1), n));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++) {
                cin >> aa[i][j][k];
                aa[i][j][k] = MAXX - aa[i][j][k];
            }
    for(int i = 0; i <= n; i++) {
        v[0][i] = 0;
        u[0][i] = 0;
        p[0][i] = -1;
    }
    cout << n * MAXX - gen(0, 0, n) << '\n';
    return 0;
}