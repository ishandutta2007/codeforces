#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

const int N = 300;
const int INF = 1e9;
int n, m, p, it, jt, dp[N][N], t1[4 * N][4 * N], t2[4 * N][4 * N], t3[4 * N][4 * N], t4[4 * N][4 * N];
vector<pii> lvl[N*N];

inline void build_y (int t[][4 * N], int a[][N], int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry)
		if (lx == rx)
			t[vx][vy] = a[lx][ly];
		else
			t[vx][vy] = min(t[vx*2][vy], t[vx*2+1][vy]);
	else {
		int my = (ly + ry) / 2;
		build_y (t, a, vx, lx, rx, vy*2, ly, my);
		build_y (t, a, vx, lx, rx, vy*2+1, my+1, ry);
		t[vx][vy] = min(t[vx][vy*2], t[vx][vy*2+1]);
	}
}

inline void build_x (int t[][4 * N], int a[][N], int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		build_x (t, a, vx*2, lx, mx);
		build_x (t, a, vx*2+1, mx+1, rx);
	}
	build_y (t, a, vx, lx, rx, 1, 0, m-1);
}

inline int sum_y (int t[][4 * N], int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return INF;
	if (ly == tly && try_ == ry)
		return t[vx][vy];
	int tmy = (tly + try_) / 2;
	return min(sum_y (t, vx, vy*2, tly, tmy, ly, min(ry,tmy)),
		sum_y (t, vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry));
}

inline int sum_x (int t[][4 * N], int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return INF;
	if (lx == tlx && trx == rx)
		return sum_y (t, vx, 1, 0, m-1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return min(sum_x (t, vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry),
		sum_x (t, vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry));
}

inline void update_y (int t[][4 * N], int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx)
			t[vx][vy] = new_val;
		else
			t[vx][vy] = min(t[vx*2][vy], t[vx*2+1][vy]);
	}
	else {
		int my = (ly + ry) / 2;
		if (y <= my)
			update_y (t, vx, lx, rx, vy*2, ly, my, x, y, new_val);
		else
			update_y (t, vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
		t[vx][vy] = min(t[vx][vy*2], t[vx][vy*2+1]);
	}
}

inline void update_x (int t[][4 * N], int vx, int lx, int rx, int x, int y, int new_val) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		if (x <= mx)
			update_x (t, vx*2, lx, mx, x, y, new_val);
		else
			update_x (t, vx*2+1, mx+1, rx, x, y, new_val);
	}
	update_y (t, vx, lx, rx, 1, 0, m-1, x, y, new_val);
}

int main()
{
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++)
        for(int j = 0, x; j < m; j++) {
            cin >> x;
            lvl[x - 1].pb({i, j});
            dp[i][j] = INF;
            if(x == p)
                it = i, jt = j;
        }
    build_x(t1, dp, 1, 0, n-1);
    build_x(t2, dp, 1, 0, n-1);
    build_x(t3, dp, 1, 0, n-1);
    build_x(t4, dp, 1, 0, n-1);
    for(pii e : lvl[0])
        dp[e.ff][e.ss] = e.ff + e.ss;
    for(int w = 1; w < p; w++) {
        for(pii e : lvl[w - 1]) {
            update_x(t1, 1, 0, n-1, e.ff, e.ss, dp[e.ff][e.ss] - e.ff + e.ss);
            update_x(t2, 1, 0, n-1, e.ff, e.ss, dp[e.ff][e.ss] - e.ff - e.ss);
            update_x(t3, 1, 0, n-1, e.ff, e.ss, dp[e.ff][e.ss] + e.ff - e.ss);
            update_x(t4, 1, 0, n-1, e.ff, e.ss, dp[e.ff][e.ss] + e.ff + e.ss);
        }
        for(pii e : lvl[w])
            dp[e.ff][e.ss] = min(
                                 min(
                                     sum_x(t1, 1, 0, n-1, 0, e.ff, e.ss, m-1) + e.ff - e.ss,
                                     sum_x(t2, 1, 0, n-1, 0, e.ff, 0, e.ss) + e.ff + e.ss
                                    ),
                                 min(
                                     sum_x(t3, 1, 0, n-1, e.ff, n-1, 0, e.ss) - e.ff + e.ss,
                                     sum_x(t4, 1, 0, n-1, e.ff, n-1, e.ss, m-1) - e.ff - e.ss
                                    )
                                );
        for(pii e : lvl[w - 1]) {
            update_x(t1, 1, 0, n-1, e.ff, e.ss, INF);
            update_x(t2, 1, 0, n-1, e.ff, e.ss, INF);
            update_x(t3, 1, 0, n-1, e.ff, e.ss, INF);
            update_x(t4, 1, 0, n-1, e.ff, e.ss, INF);
        }
    }
    cout << dp[it][jt];
    return 0;
}