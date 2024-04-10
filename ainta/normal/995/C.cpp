#include<cstdio>
#include<algorithm>
using namespace std;
struct point {
	int x, y, num;
	point operator +(const point &p)const {
		return { x + p.x,y + p.y };
	}
	point operator -(const point &p)const {
		return { x - p.x,y - p.y };
	}
	long long SZ() {
		return 1ll * x*x + 1ll * y*y;
	}
	bool operator<(const point &p)const {
		if ((x > 0 || (x == 0 && y > 0)) != (p.x > 0 || (p.x == 0 && p.y > 0)))return (x > 0 || (x == 0 && y > 0));
		return 1ll * y*p.x < 1ll*p.y*x;
	}
}w[101000], tw[101000], ori[101000];
int cnt;
int n, par[501000], pL[501000],m, tm, res[501000];
long long M2 = 1500000, M = 1000000;
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &w[i].x, &w[i].y);
		ori[i] = w[i];
		w[i].num = i;
	}
	sort(w + 1, w + n + 1);
	m = n;
	cnt = n;
	while (1) {
		tm = 0;
		for (i = 1; i <= m; i++) {
			if (i == m) {
				tw[++tm] = w[i];
				continue;
			}
			point tp = w[i] + w[i + 1];
			if (tp.SZ() > M*M) {
				tp = w[i] - w[i + 1];
				if (tp.SZ() > M*M) {
					tw[++tm] = w[i];
					continue;
				}
				tw[++tm] = tp;
				tw[tm].num = ++cnt;
				par[w[i].num] = cnt;
				par[w[i+1].num] = cnt;
				pL[w[i].num] = 1;
				pL[w[i+1].num] = -1;
			}
			else {
				tw[++tm] = tp;
				tw[tm].num = ++cnt;
				par[w[i].num] = cnt;
				par[w[i + 1].num] = cnt;
				pL[w[i].num] = 1;
				pL[w[i + 1].num] = 1;
			}
			i++;
		}
		for (i = 1; i <= tm; i++)w[i] = tw[i];
		if (m == tm)break;
		m = tm;
	}
	for (i = 0; i < (1 << m); i++) {
		point uu = { 0,0,0 };
		for (j = 1; j <= m; j++) {
			if ((i >> (j - 1)) & 1) uu = uu - w[j], res[w[j].num] = -1;
			else uu = uu + w[j], res[w[j].num] = 1;
		}
		if (uu.SZ() < M2*M2) {
			for (i = 1; i <= n; i++) {
				int x = i, ck = 1;
				while (par[x]){
					ck *= pL[x];
					x = par[x];
				}
				ck *= res[x];
				printf("%d ", ck);
			}
			return 0;
		}
	}
}