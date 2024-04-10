#include<stdio.h>
#include<algorithm>
using namespace std;
struct point {
	long long x, y;
	bool operator <(const point &p)const {
		return x != p.x ? x<p.x : y<p.y;
	}
}w[2010];
struct Vec {
	long long x, y;
	int a, b;
	bool operator <(const Vec &p)const {
		return y*p.x < p.y*x;
	}
}P[2200100];
int n, cnt, Num[3010], ord[3010];
long long S;
long long get(point a, point b, point c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}
void Print(point a) {
	printf("%lld %lld\n", a.x, a.y);
}
bool Go1(int x, int y, int st, int ed) {
	int b = st, e = ed, mid;
	while (b <= e) {
		mid = (b + e) >> 1;
		long long t = get(w[x], w[y], w[Num[mid]]);
		if (t < 0)t = -t;
		if (t == S * 2) {
			puts("Yes");
			Print(w[x]);
			Print(w[y]);
			Print(w[Num[mid]]);
			return true;
		}
		if (t < S * 2) e = mid - 1;
		else b = mid + 1;
	}
	return false;
}
bool Go2(int x, int y, int st, int ed) {
	int b = st, e = ed, mid;
	while (b <= e) {
		mid = (b + e) >> 1;
		long long t = get(w[x], w[y], w[Num[mid]]);
		if (t < 0)t = -t;
		if (t == S * 2) {
			puts("Yes");
			Print(w[x]);
			Print(w[y]);
			Print(w[Num[mid]]);
			return true;
		}
		if (t > S * 2) e = mid - 1;
		else b = mid + 1;
	}
	return false;
}
int main() {
	int i, j;
		scanf("%d%lld", &n,&S);
		for (i = 1; i <= n; i++) {
			scanf("%lld%lld", &w[i].x, &w[i].y);
		}
		sort(w + 1, w + n + 1);
		cnt = 0;
		for (i = 1; i <= n; i++) {
			for (j = i + 1; j <= n; j++) {
				P[cnt].x = w[j].x - w[i].x;
				P[cnt].y = w[j].y - w[i].y;
				P[cnt].a = i, P[cnt].b = j;
				cnt++;
			}
		}
		sort(P, P + cnt);
		for (i = 1; i <= n; i++)Num[i] = ord[i] = i;
		for (i = cnt - 1; i >= 0; i--) {
			int a = P[i].a, b = P[i].b;
			swap(Num[ord[a]], Num[ord[b]]);
			swap(ord[a], ord[b]);
			if (Go1(a, b, 1, min(ord[a], ord[b]))) return 0;
			if (Go2(a, b, max(ord[a], ord[b]), n))return 0;
		}
		puts("No");
}