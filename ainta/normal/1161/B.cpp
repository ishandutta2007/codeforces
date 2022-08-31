#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, vis[201000];
struct point {
	int b, e;
	bool operator <(const point &p)const {
		return b != p.b ? b < p.b : e < p.e;
	}
}w[201000], T[201000];
bool OK(int K) {
	int i;
	for (i = 0; i < m; i++) {
		int b = w[i].b + K, e = w[i].e + K;
		b %= n, e %= n;
		if (b == 0)b += n;
		if (e == 0)e += n;
		if (b > e)swap(b, e);
		T[i] = { b,e };
	}
	sort(T, T + m);
	for (i = 0; i < m; i++) {
		if (w[i].b != T[i].b || w[i].e != T[i].e)return false;
	}
	return true;
}
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &w[i].b, &w[i].e);
		if (w[i].b > w[i].e)swap(w[i].b, w[i].e);
	}
	sort(w, w + m);
	for (i = 2; i <= n; i++) {
		if (n%i == 0 && !vis[i]) {
			for (j = i; j <= n; j += i)vis[j] = 1;
			if (OK(n / i)) {
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
}