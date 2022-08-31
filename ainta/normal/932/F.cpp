#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
#define BS 1000
using namespace std;
int A[N_], B[N_], BB[N_];
int n, Num[N_], Ed[N_], cnt;
vector<int>E[N_];
struct point {
	int a;
	long long b;
	bool operator<(const point &p)const {
		return a != p.a ? a > p.a : b < p.b;
	}
}st[200][1024], w[1024], T[101000];
int top[200], v[200], ReNum[N_];
long long D[N_];
long long Get(point &tp, int a) {
	return (long long)tp.a*a + tp.b;
}
bool Over(point &a, point &b, point &c) {
	return 1.0L*(c.b - a.b)* (a.a - b.a) <= 1.0L*(b.b - a.b)*(a.a - c.a);
}
void Build(int a) {
	int i, b, e;
	v[a] = 1;
	b = max(1, a * BS), e = min(n, (a + 1) * BS - 1);
	int c = 0;
	for (i = b; i <= e; i++) {
		w[c++] = T[i];
	}
	sort(w, w + c);
	int tt = 0;
	for (i = 0; i < c; i++) {
		if (tt && st[a][tt].a == w[i].a)continue;
		while (tt > 1 && Over(st[a][tt - 1], st[a][tt], w[i]))tt--;
		st[a][++tt] = w[i];
	}
	top[a] = tt;
}
void Make(long long &res, int a, int aa) {
	int b = 1, e = top[a]-1, mid, r = 1;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Get(st[a][mid], aa) >= Get(st[a][mid + 1], aa))b = mid + 1, r = mid + 1;
		else e = mid - 1;
	}
	res = min(res, Get(st[a][r], aa));
}
long long Calc(int b, int e, int aa) {
	if (b > e)return 0;
	int t1 = b/BS, t2 = e/BS;
	int i;
	long long res = 5e18;
	if (t1 + 1 < t2) {
		for (i = t1 + 1; i < t2; i++) {
			if (!v[i]) {
				Build(i);
			}
			Make(res, i, aa);
		}
		for (i = b; i < (t1 + 1) * BS; i++) {
			res = min(res, Get(T[i], aa));
		}
		for (i = t2 * BS; i <= e; i++) {
			res = min(res, Get(T[i], aa));
		}
	}
	else {
		for (i = b; i <= e; i++) {
			res = min(res, Get(T[i], aa));
		}
	}
	return res;
}
void DFS(int a, int pp) {
	Num[a] = ++cnt;
	ReNum[cnt] = a;
	BB[cnt] = B[a];
	int i;
	for (i = 0; i < E[a].size(); i++) {
		if (E[a][i] == pp)continue;
		DFS(E[a][i], a);
	}
	Ed[a] = cnt;
	D[a] = Calc(Num[a] + 1, Ed[a], A[a]);
	T[Num[a]] = { B[a],D[a] };
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &B[i]);
	}
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	for (i = 1; i <= n; i++)printf("%lld ", D[i]);
}