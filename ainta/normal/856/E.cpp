#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 510000
#define SZ (1<<19)
using namespace std;
struct point {
	long long x, y;
	int num;
	bool operator<(const point &p)const {
		return x*p.y  < p.x*y ;
	}
}A[N_], B[N_];
long long Mul(point a, point b) {
	return a.x*b.x + a.y*b.y;
}
int R, n, cnt;
struct AA{
	int b, e, num;
	bool operator<(const AA &p)const {
		return b != p.b ? b < p.b : e < p.e;
	}
}w[N_];
int ReNum[N_];
struct QQ {
	int ck, a, b;
}Q[N_];
int IT[SZ + SZ];
void Ins(int a) {
	a = ReNum[a];
	int y = w[a].e;
	a += SZ;
	IT[a] = y;
	while (a != 1) {
		a >>= 1;
		IT[a] = max(IT[a + a], IT[a + a + 1]);
	}
}
void Del(int a) {
	a = ReNum[a];
	a += SZ;
	IT[a] = 0;
	while (a != 1) {
		a >>= 1;
		IT[a] = max(IT[a + a], IT[a + a + 1]);
	}
}
int Max(int b, int e) {
	int r = 0;
	b += SZ, e += SZ;
	while (b <= e) {
		r = max(r, max(IT[b], IT[e]));
		b = (b + 1) >> 1;
		e = (e - 1) >> 1;
	}
	return r;
}
bool Valid(int a, int b) {
	point t1 = A[a], t2 = A[b];
	if (Mul(A[a], B[b]) < 0)return false;
	return true;
}
int main() {
	int i, ck, x, y;
	scanf("%d%d", &R, &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &ck);
		if (ck == 1) {
			scanf("%d%d", &x, &y);
			cnt++;
			Q[i] = { 1,cnt,0 };
			A[cnt] = { x + R,y,cnt };
			B[cnt] = { x - R,y,cnt };
		}
		else if (ck == 2) {
			scanf("%d", &x);
			Q[i] = { 2,x,0 };
		}
		else {
			scanf("%d%d", &x, &y);
			Q[i] = { 3,x,y };
		}
	}
	sort(A + 1, A + cnt + 1);
	sort(B + 1, B + cnt + 1);
	int pv1 = 1, pv2 = 1;
	for (i = 1; i <= cnt; i++) {
		if (A[pv1] < A[i])pv1 = i;
		if (B[pv2] < B[i])pv2 = i;
		w[A[i].num].b = pv1;
		w[B[i].num].e = pv2;
		w[i].num = i;
	}
	sort(w + 1, w + cnt + 1);
	for (i = 1; i <= cnt; i++)ReNum[w[i].num] = i;
	for (i = 1; i <= n; i++) {
		if (Q[i].ck == 1) {
			Ins(Q[i].a);
		}
		if (Q[i].ck == 2) {
			Del(Q[i].a);
		}
		if (Q[i].ck == 3) {
			Del(Q[i].a), Del(Q[i].b);
			int a = ReNum[Q[i].a], b = ReNum[Q[i].b];
			int aa = max(w[a].b, w[b].b), bb = min(w[a].e, w[b].e);
			if (!Valid(aa, bb)) {
				printf("NO\n");
			}
			else {
				AA tp = { aa + 1,0,0 };
				int t = lower_bound(w + 1, w + cnt + 1, tp) - w - 1;
				if (Max(1, t) >= bb) {
					printf("NO\n");
				}
				else printf("YES\n");
			}

			Ins(Q[i].a), Ins(Q[i].b);
		}
	}
}