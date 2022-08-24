#include<cstdio>
#include<algorithm>
#include<set>
#define N_ 1010000
using namespace std;
set<int>Set;
int n, w[N_],K;
long long res, Mod = 1000000007;
struct point {
	int x, num;
	bool operator <(const point &p)const {
		return x < p.x;
	}
}P[N_];
long long Sum(int b, int e, int d) {
	return 1ll * (b + e) * ((e - b) / d + 1) / 2 % Mod;
}
long long Get(int d, int st) {
	if (d < st)return 0ll;
	int tp = d / (K - 1) * (K-1) + st;
	while (tp >= d)tp -= (K - 1);
	return Sum(st + 1, tp + 1, K - 1);
}
long long Calc2(int dx, int dy) {
	long long t = Get(dy, 0);
	int rr = (dx + dy) % (K - 1);
	t += Get(dy, rr);
	int tp = -1;
	if (dy != 0)tp = (dy - 1) / (K - 1);
	t += 1ll * (dx / (K - 1) - tp) * (dy + 1) % Mod;
	return t%Mod;
}
long long Calc(int bx, int ex, int by, int ey) {
	int i, j, r = 0;
	int dx = ex - bx, dy = ey - by ;
	if (dx < dy)swap(dx, dy);
	return Calc2(dx, dy);
}
void Put(int x) {
	auto it = Set.lower_bound(x);
	auto it2 = it;
	it2--;
	int b = *it2;
	int e = *it;
	res = (res + Calc(b + 1, x, x, e - 1)%Mod * w[x])%Mod;
	Set.insert(x);
}
int main() {
	int i;
	scanf("%d%d", &n,&K);
	Set.insert(0);
	Set.insert(n + 1);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		P[i] = { w[i],i };
	}
	sort(P + 1, P + n + 1);
	for (i = n; i >= 1; i--) {
		Put(P[i].num);
	}
	for (i = 1; i <= n; i++) {
		res = (res + Mod - w[i]) % Mod;
	}
	printf("%lld\n", res);
}