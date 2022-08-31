#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, CA, CB;
struct point {
	int x, y;
	bool operator<(const point &p)const {
		return x != p.x ? x < p.x : y < p.y;
	}
}st[201000];
int BX[201000], EX[201000], BY[201000], EY[201000];
long long res;
void Pro(vector<point> &w, int *B, int *E) {
	int i;
	int top = 0;
	for (auto &tp : w) {
		while (top && st[top].x + st[top].y >= tp.x + tp.y)top--;
		if (top && st[top].y - st[top].x <= tp.y - tp.x)continue;
		st[++top] = tp;
	}
	int pv = 1;
	for (i = 1; i <= 200020; i++) {
		while (pv < top && st[pv].y + abs(i - st[pv].x) >= st[pv + 1].y + abs(i - st[pv + 1].x))pv++;
		B[i] = st[pv].y + abs(i - st[pv].x);
	}

	top = 0;
	for (auto &tp : w) {
		while (top && st[top].y - st[top].x <= tp.y - tp.x)top--;
		if (top && st[top].y + st[top].x >= tp.y + tp.x)continue;
		st[++top] = tp;
	}
	pv = 1;
	for (i = 1; i <= 200020; i++) {
		while (pv < top && st[pv].y - abs(i - st[pv].x) <= st[pv + 1].y - abs(i - st[pv + 1].x))pv++;
		E[i] = st[pv].y - abs(i - st[pv].x);
		if (B[i] > E[i])B[i] = 1, E[i] = 0;
	}
}

struct AA {
	int t, y, ck;
	bool operator<(const AA &p)const {
		return t < p.t;
	}
}T[401000];

int BIT[201000][2];

void Add(int a, int ck, int b) {
	while (a <= 200020) {
		BIT[a][ck] += b;
		a += (a&-a);
	}
}

int Sum(int a, int ck) {
	if (a < 0)return 0;
	int r = 0;
	while (a) {
		r += BIT[a][ck];
		a -= (a&-a);
	}
	return r;
}

void Do(vector<point> w, int ck) {
	if (w.empty())return;
	int i;
	sort(w.begin(), w.end());
	Pro(w, BX, EX);
	for (i = 0; i < w.size(); i++)swap(w[i].x, w[i].y);
	sort(w.begin(), w.end());
	Pro(w, BY, EY);
	int cnt = 0;
	for (i = 1; i <= 200020; i++) {
		BIT[i][0] = BIT[i][1] = 0;
		T[cnt++] = { BY[i], i, 1 };
		T[cnt++] = { EY[i]+1, i, -1 };
	}
	sort(T, T + cnt);
	int pv = 0;
	for (i = 1; i <= 200020; i++) {
		while (pv < cnt && T[pv].t <= i) {
			Add(T[pv].y, T[pv].y % 2, T[pv].ck);
			pv++;
		}
		if (BX[i] > EX[i])continue;
		res += Sum(EX[i], (ck + i) % 2) - Sum(BX[i] - 1, (ck + i) % 2);
	}
}
int main() {
	int i, x, y;
	scanf("%d", &n);
	vector<point>A, B;
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		x += 1e5 + 10;
		y += 1e5 + 10;
		if ((x + y) % 2) {
			A.push_back({ x,y });
		}
		else {
			B.push_back({ x,y });
		}
	}
	Do(A, 0);
	Do(B, 1);
	printf("%lld\n", res);
}