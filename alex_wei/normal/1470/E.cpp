#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll read() {
	ll x = 0; char s = getchar();
	while(!isdigit(s)) s = getchar();
	while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
	return x;
}
void print(int x) {
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}

const int N = 3e4 + 5;
const ll inf = 2e18;

bool Mbe;
int n, k, q, p[N];
ll f[N][5], g[N][5];
__int128 h[N][5];
void add(ll &x, ll y) {x = min(inf, x + y);}

bool Med;
int main() {
	int T = read();
	while(T--) {
		memset(h, 0, sizeof(h));
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g)); 
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++) p[i] = read();
		for(int i = 0; i <= k; i++) f[n + 1][i] = 1;
		for(int i = n; i; i--)
			for(int j = 0; j <= k; j++) { 
				for(int L = 1; L <= j; L++) {
					int l = i, r = l + L;
					if(r > n) continue;
					if(p[l] > p[r]) add(f[i][j], f[r + 1][j - L] + g[r + 1][j - L]);
					else add(g[i][j], f[r + 1][j - L] + g[r + 1][j - L]);
				} h[i][j] = f[i][j], add(f[i][j], f[i + 1][j]), add(g[i][j], g[i + 1][j]);
			}
		for(int i = 1; i <= n + 1; i++) for(int j = 0; j <= k; j++) h[i][j] += h[i - 1][j];
		for(int i = 1; i <= q; i++) {
			ll y = read(), x = read();
			if(x > f[1][k] + g[1][k]) {puts("-1"); continue;}
			vector <pair <int, int>> op;
			int cur = 1, curk = k;
			while(cur <= n && curk) {
				int l = cur, r = n + 1;
				if(x > f[cur][curk]) {
					x -= f[cur][curk];
					int l = cur, r = n;
					while(l < r) {
						int m = l + r + 1 >> 1;
						if(g[m][curk] < x) r = m - 1;
						else l = m;
					} x -= g[l + 1][curk], cur = l;
					vector <int> pos;
					for(int j = 1; j <= curk; j++) {
						int r = cur + j;
						if(r > n) break;
						if(p[r] > p[cur]) pos.push_back(r);
					} sort(pos.begin(), pos.end(), [&](int x, int y) {return p[x] < p[y];});
					for(auto it : pos) {
						int res = curk - (it - cur);
						ll tot = f[it + 1][res] + g[it + 1][res];
						if(x > tot) x -= tot;
						else {
							op.push_back({cur, it});
							cur = it + 1, curk = res;
							break;
						}
					}
				} else {
					if(h[n][curk] - h[cur - 1][curk] < x) break;
					int l = cur, r = n;
					while(l < r) {
						int m = l + r >> 1;
						if(h[m][curk] - h[cur - 1][curk] < x) l = m + 1;
						else r = m;
					} x -= h[l - 1][curk] - h[cur - 1][curk], cur = l;
					vector <int> pos;
					for(int j = 1; j <= curk; j++) {
						int r = cur + j;
						if(r > n) break;
						if(p[cur] > p[r]) pos.push_back(r);
					} sort(pos.begin(), pos.end(), [&](int x, int y) {return p[x] < p[y];});
					for(auto it : pos) {
						int res = curk - (it - cur);
						ll tot = f[it + 1][res] + g[it + 1][res];
						if(x > tot) x -= tot;
						else {
							op.push_back({cur, it});
							cur = it + 1, curk = res;
							break;
						}
					}
				}
			}
			for(auto it : op) reverse(p + it.first, p + it.second + 1);
			print(p[y]), putchar('\n');
			for(auto it : op) reverse(p + it.first, p + it.second + 1);
		}
	}
	return 0;
}