#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct point {
	long long x, y, a, b;
	bool operator <(const point &p)const {
		return y* p.x < p.y * x;
	}
	point operator -(const point &p)const {
		return { x - p.x,y - p.y };
	}
}w[1010], T[501000];
int n;
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld%lld", &w[i].x, &w[i].y);
	}
	int cnt = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (w[j].x > w[i].x || (w[j].x == w[i].x && w[j].y > w[i].y)) {
				T[cnt] = w[j] - w[i];
				T[cnt].a = i, T[cnt].b = j;
				cnt++;
			}
		}
	}
	sort(T, T + cnt);
	long long S = 0, Res = 0;
	for (i = 0; i < cnt; i++) {
		for (j = i; j < cnt; j++) {
			if (T[i] < T[j])break;
		}
		int b = i, e = j - 1;

		vector<long long>U;
		for (int ii = b; ii <= e; ii++) {
			point t = w[T[ii].a];
			U.push_back(t.x*T[i].y - t.y*T[i].x);
		}
		sort(U.begin(), U.end());
		long long sz = unique(U.begin(), U.end()) - U.begin();
		S += sz;
		Res -= sz * (sz - 1) / 2;

		i = e;
	}
	Res += S * (S - 1) / 2;
	printf("%lld\n", Res);
}