#include<cstdio>
#include<algorithm>
using namespace std;
struct point {
	long long A, B;
	bool operator<(const point &p)const {
		return A != p.A ? A<p.A : B>p.B;
	}
}w[201000], st[201000];
int n, top;
bool Over(point a, point b, point c) {
	return (a.B - b.B)*(c.A - a.A) >= (a.B - c.B)*(b.A - a.A);
}
int main() {
	int i;
	scanf("%d", &n);
	long long x, y;
	for (i = 1; i <= n; i++) {
		scanf("%lld%lld", &x, &y);
		w[i] = { -x, y - x * x };
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n; i++) {
		if (top && st[top].A == w[i].A)continue;
		while (top>1 && Over(st[top - 1], st[top], w[i]))top--;
		st[++top] = w[i];
	}
	printf("%d\n", top - 1);
}