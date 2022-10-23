# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXP = 106;
const int MAXN = 200061;
struct Line{
	ll k, b; // y=kx+b
};
Line q[MAXN];
int ql = 1, qr;
int n, m, p;
ll d[MAXN], sd[MAXN];
ll t[MAXN], st[MAXN];
ll f[MAXP][MAXN];
int main(){
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 2; i <= n; i++){
		scanf("%lld", d + i);
		sd[i] = sd[i - 1] + d[i];
	}
	for (int i = 1; i <= m; i++){
		int h;
		scanf("%d%lld", &h, t + i);
		t[i] -= sd[h];
	}
	sort(t + 1, t + m + 1);
	for (int i = 1; i <= m; i++) st[i] = st[i - 1] + t[i];
	for (int i = 1; i <= p; i++){
		ql = 1;
		qr = 0;
		q[++qr] = {0, 0};
		for (int j = 1; j <= m; j++){
			while (qr - ql + 1 >= 2 && t[j] * (q[ql].k - q[ql + 1].k) >= (q[ql + 1].b - q[ql].b)) ql++; // t[j] >= (b2 - b1) / (k1 - k2)
			f[i][j] = q[ql].k * t[j] + q[ql].b + j * t[j] - st[j];
			// printf("f %d %d %lld\n", i, j, f[i][j]);
			if (i == 1) continue;
			Line nw = (Line){-1ll * j, st[j] + f[i - 1][j]};
			while (qr - ql + 1 >= 2 && (q[qr].b - q[qr - 1].b) * (q[qr - 1].k - nw.k) >= (nw.b - q[qr - 1].b) * (q[qr - 1].k - q[qr].k)) qr--; // (b2 - b1) / (k1 - k2) >= (b3 - b1) / (k1 - k3)
			q[++qr] = nw;
		}
	}
	printf("%lld\n", f[p][m]);
	return 0;
}