#include <bits/stdc++.h>
#ifndef WIN32
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

typedef bitset<170> Status;

#define ll long long

const int M = 53000;

int cs;
Status Q[M];
int nxt[M][10];
unordered_map<Status, int> G;

int extend(Status& bs) {
	return (!G.count(bs)) ? (Q[G[bs] = ++cs] = bs, cs) : (G[bs]);
}
void bfs() {
	Status* cur = new Status;
	static Status snxt;
	cur->reset();
	cur->set(0);
	extend(*cur);
	for (int i = 1; i <= cs; i++) {
		cur = Q + i;
		for (int j = 0; j < 10; j++) {
			snxt = *cur << j | *cur >> j;
			for (int k = 0; k <= j; k++) {
				if (cur->test(k)) {
					snxt.set(j - k);
				}
			}
			nxt[i][j] = extend(snxt);
		}
	}
}

int lowbit(Status& x) {
	for (int i = 0; i < 10; i++) {
		if (x.test(i)) {
			return i;
		}
	}
	assert(false);
	return 10;
}

int lb[M];
ll f[11][20][M];
void init_dp() {
	for (int i = 1; i <= cs; i++) {
		lb[i] = lowbit(Q[i]);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 1; j <= cs; j++) {
			f[i][0][j] = (lb[j] <= i);
		}
		for (int j = 1; j <= 19; j++) {
			for (int k = 1; k <= cs; k++) {
				for (int c = 0; c < 10; c++) {
					f[i][j][k] += f[i][j - 1][nxt[k][c]];
				}
			}
		}
	} 
}

ll solve(ll n, int k) {
	if (!n) {
		return 1;
	}
	static int bit[24];
	ll _n = n;
	memset(bit, 0, sizeof(bit));
	for (int i = 1; _n; _n /= 10) {
		bit[i++] = _n % 10;
	}
	int s = 1;
	ll rt = 0;
	for (int i = 19; i; i--) {
		for (int j = 0; j < bit[i]; j++) {
			rt += f[k][i - 1][nxt[s][j]];
		}
		s = nxt[s][bit[i]];
	}
	return rt += f[k][0][s];
}

int T, k;
int main() {
	bfs();
	init_dp();
	scanf("%d", &T);
	ll l, r;
	while (T--) {
		scanf(Auto""Auto"%d", &l, &r, &k);
		ll ans = solve(r, k) - solve(l - 1, k);
		printf(Auto"\n", ans);;
	}
	return 0;
}