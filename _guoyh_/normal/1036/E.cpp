# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 1051;
int n;
ll ans;
set <pair <int, int> > st;
bool flag[MAXN];
int ax[MAXN], ay[MAXN], bx[MAXN], by[MAXN], p[MAXN], q[MAXN];
int gcd(int u, int v){
	if (v == 0) return u;
	else return gcd(v, u % v);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d%d%d", ax + i, ay + i, bx + i, by + i);
		if (ax[i] > bx[i]){
			swap(ax[i], bx[i]);
			swap(ay[i], by[i]);
		}
	}
	for (int i = 1; i <= n; i++){
		int g = gcd(abs(ax[i] - bx[i]), abs(ay[i] - by[i]));
		ans += g + 1;
		p[i] = (bx[i] - ax[i]) / g;
		q[i] = (by[i] - ay[i]) / g;
		// printf("pq %d %d %d\n", i, p[i], q[i]);
		// printf("ans %lld\n", ans);
	}
	for (int i = 1; i <= n; i++){
		st.clear();
		for (int j = i + 1; j <= n; j++){
			// printf("ij %d %d\n", i, j);
			if (1ll * (by[j] - ay[j]) * (bx[i] - ax[i]) == 1ll * (by[i] - ay[i]) * (bx[j] - ax[j])) continue;
			if (1ll * p[i] * q[j] - 1ll * p[j] * q[i] == 0) continue;
			if ((1ll * q[j] * (ax[j] - ax[i]) - 1ll * p[j] * (ay[j] - ay[i])) % (1ll * p[i] * q[j] - 1ll * p[j] * q[i])) continue;
			ll k1 = (1ll * q[j] * (ax[j] - ax[i]) - 1ll * p[j] * (ay[j] - ay[i])) / (1ll * p[i] * q[j] - 1ll * p[j] * q[i]);
			ll k2 = (q[j] == 0) ? ((k1 * p[i] + ax[i] - ax[j]) / p[j]) : ((k1 * q[i] + ay[i] - ay[j]) / q[j]);
			// printf("k1 %lld\n", k1);
			if (k1 < 0) continue;
			if (p[i] == 0 && k1 > (by[i] - ay[i]) / q[i]) continue;
			if (p[i] != 0 && k1 > (bx[i] - ax[i]) / p[i]) continue;
			if (k2 < 0) continue;
			if (p[j] == 0 && k2 > (by[j] - ay[j]) / q[j]) continue;
			if (p[j] != 0 && k2 > (bx[j] - ax[j]) / p[j]) continue;
			if (st.find(make_pair(ax[i] + k1 * p[i], ay[i] + k1 * q[i])) != st.end()) continue;
			st.insert(make_pair(ax[i] + k1 * p[i], ay[i] + k1 * q[i]));
			ans--;
			// printf("ans %lld\n", ans);
		}
	}
	printf("%lld\n", ans);
	return 0;
}