# include <bits/stdc++.h>
# define ll long long
using namespace std;
int t;
ll n, m, x, y, vx, vy;
ll exgcd(ll a, ll b, ll &xx, ll &yy){
	if (b == 0){
		xx = 1;
		yy = 0;
		return a;
	}
	ll nx, ny;
	ll ans = exgcd(b, a % b, nx, ny);
	xx = ny;
	yy = nx - a / b * ny;
	return ans;
}
int main(){
	// freopen("pingpong.in", "r", stdin);
	// freopen("pingpong.out", "w", stdout);
	// scanf("%d", &t);
	t = 1;
	while (t--){
		scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &x, &y, &vx, &vy);
		if (vx == 0){
			if (x % n) printf("-1\n");
			else printf("%lld %lld\n", x, (vy > 0 ? m : 0));
			continue;
		}
		if (vy == 0){
			if (y % m) printf("-1\n");
			else printf("%lld %lld\n", (vx > 0 ? n : 0), y);
			continue;
		}
		ll p, q;
		ll d = x / vx - y / vy;
//		printf("d %lld\n", d);
		ll g = exgcd(n / vx, -m / vy, p, q);
		if (d % g){
			printf("-1\n");
			continue;
		}		
		p *= d / g;
		q *= d / g;
//		printf("pq %d %d\n", p, q);
//		printf("pn-x (pn-x)/vx %lld %lld\n", p * n - x, (p * n - x) / vx);
//		printf("qm-y (qm-y)/vy %lld %lld\n", q * m - y, (q * m - y) / vy);
		ll a, b;
		if (vx > 0){
			a = (x + n - 1) / n;
			b = p > a ? (p - a) / abs(-m / vy / g) : -((a - p + abs(-m / vy / g) - 1) / abs(-m / vy / g));
		} else {
			a = x / n;
			b = p > a ? (p - a + abs(-m / vy / g) - 1) / abs(-m / vy / g) : -((a - p) / abs(-m / vy / g));
		}
		if (-m / vy / g < 0) b = -b;
//		printf("ab %lld %lld\n", a, b);
		p -= b * (-m / vy / g);
		q += b * (n / vx / g);
//		printf("pq1 %d %d\n", p, q);
//		printf("pn-x (pn-x)/vx %lld %lld\n", p * n - x, (p * n - x) / vx);
//		printf("qm-y (qm-y)/vy %lld %lld\n", q * m - y, (q * m - y) / vy);
		if ((p % 2 + 2) % 2) printf("%lld ", n);
		else printf("0 ");
		if ((q % 2 + 2) % 2) printf("%lld\n", m);
		else printf("0\n");
	}
	return 0;
}