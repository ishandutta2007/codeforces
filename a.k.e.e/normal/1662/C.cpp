// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int P = 998244353, N = 205, S = 1e4 + 5;

int nw[N][N];

struct Mat{
    int n, m, w[N][N];
    void mul (const Mat &b) {
        memset(nw, 0, sizeof nw);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= b.m; j++)
                for (int k = 1; k <= m; k++)
                    nw[i][j] = (nw[i][j] + (LL)w[i][k] * b.w[k][j]) % P;
        for (int i = 1; i <= n; i++)
        	for (int j = 1; j <= n; j++)
        		w[i][j] = nw[i][j];
    }
} t[5];

int pos[S], id, d[N], n, m, k, g[N][N];

void inline del(int &x, int y) {
	x -= y;
	if (x < 0) x += P;
}

int c;

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

int main() {
    read(n), read(m), read(k);
    pos[0] = ++id;
    t[id].n = t[id].m = 2 * n;
    for (int i = 1; i <= 2 * n; i++)
    	t[id].w[i][i] = 1;
    pos[1] = ++id;
    t[id].n = t[id].m = 2 * n;
    for (int i = 1; i <= m; i++) {
  		int a, b; read(a), read(b);
  		t[id].w[a][b] = t[id].w[b][a] = 1;
  		d[a]++, d[b]++;
    	g[a][b] = g[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
    	if (!d[i]) continue;
    	t[id].w[i][i + n] = 1;
    	t[id].w[i + n][i] = P - d[i] + 1;
    }
    --k;
    while (k) {
    	if (k & 1) t[1].mul(t[2]);
    	t[2].mul(t[2]);
    	k >>= 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++)
    		if (g[j][i]) add(ans, t[1].w[i][j]);
    	add(ans, 1ll * t[1].w[i][i + n] * (P - d[i]) % P);
    }
    printf("%d\n", ans);
    return 0;
}