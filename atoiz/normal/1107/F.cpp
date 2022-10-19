#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

typedef long long ll;
static const int maxn = 507;
static const ll inf = 1e13;

struct KM
{
    int n, qu[maxn], fr, rr, mx[maxn], my[maxn], prv[maxn];
    ll slk[maxn], lx[maxn], ly[maxn], w[maxn][maxn];
    bool vx[maxn], vy[maxn];

    void mch(int y) { while (y) swap(y, mx[my[y] = prv[y]]); }
	void bfs(int x)
	{
        for (int i = 1; i <= n; ++i) vx[i] = vy[i] = 0, slk[i] = inf;
        fr = rr = 0; vx[qu[++rr] = x] = 1;
        while (true) {
            while (fr < rr) {
                x = qu[++fr]; ll d;
                for (int y = 1; y <= n; ++y) if (!vy[y] && (d = lx[x] + ly[y] - w[x][y]) <= slk[y]) {
                    prv[y] = x;
                    if (!d) {
                        if (!my[y]) return mch(y);
                        vx[qu[++rr] = my[y]] = vy[y] = 1;
                    } else slk[y] = d;
                }
            }

            int y; ll d = inf+1;
            for (int i = 1; i <= n; ++i) if (!vy[i] && slk[i] < d) d = slk[y = i];
            for (int i = 1; i <= n; ++i) {
                if (vx[i]) lx[i] -= d;
                if (vy[i]) ly[i] += d;
                else slk[i] -= d;
            }

			if (!my[y]) return mch(y);
			vx[qu[++rr] = my[y]] = vy[y] = 1;
        }
	}

	ll ask()
	{
        for (int i = 1; i <= n; ++i) mx[i] = my[i] = ly[i] = 0, lx[i] = *max_element(w[i]+1, w[i]+n+1);
		for (int i = 1; i <= n; ++i) bfs(i);
        return accumulate(lx+1, lx+n+1, accumulate(ly+1, ly+n+1, 0ll));
	}
} km;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; km.n = n;
    ll a, b, k;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b >> k;
        for (int j = 1; j <= n; ++j) km.w[i][j] = max(0ll, a - b * min(k, j-1ll));
    }
    cout << km.ask() << endl;
}