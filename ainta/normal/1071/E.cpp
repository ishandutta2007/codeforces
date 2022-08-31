#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
double W, H;
struct point{
	double x, y, z;
	bool operator <(const point &p) {
		return x != p.x ? x < p.x : y < p.y;
	}
	point() {

	}
	point(double x_, double y_, double z_=  1.0) {
		x = x_, y = y_, z = z_;
	}
	point operator +(const point &p)const {
		return { x + p.x,y + p.y};
	}
	point operator -(const point &p)const {
		return { x - p.x,y - p.y };
	}
	point To2D() {
		return { x / z,y / z };
	}
	double SZ() {
		return sqrt(x*x + y*y);
	}
}st,P[20], TP[20];
struct Input {
	point A, B;
	int T;
}w[101000];
int cnt = 0;
int ccw(point a, point b, point c) {
	point tb = b - a, tc = c - a;
	double t = tb.x*tc.y - tb.y*tc.x;
	
	if (abs(t / (tb.SZ() + tc.SZ())) < 1e-8)return 0;
	if (t > 0)return 1;
	if (t < 0)return -1;
}
point Seg(point a, point b) {
	return { b.y - a.y, a.x - b.x, -a.x*b.y + a.y*b.x };
}
point Cross(point a, point b) {
	return { a.y*b.z - b.y*a.z, a.z*b.x - a.x*b.z, a.x*b.y - b.x*a.y };
}

bool Get2(point &rA, point &rB, point b, point e, point A, point B) {
	int ck1 = ccw(b, e, A);
	int ck2 = ccw(b, e, B);
	if (ck1 >= 0 && ck2 >= 0) {
		rA = A, rB = B;
		return true;
	}
	if (ck1 < 0 && ck2 < 0) {
		return false;
	}
	if (ck1 < 0) {
		swap(A, B);
	}
	rA = A;
	rB = Cross(Seg(A, B), Seg(b, e)).To2D();
	return true;
}

bool Get(point &rA, point &rB, point b, point e) {
	int i;
	for (i = 0; i < cnt; i++) {
		if (!Get2(b, e, P[i], P[(i + 1) % cnt], b, e))return false;
	}
	rA = b, rB = e;
	return true;
}

void Make(int pv, double x, double y) {
	point P1 = { 0.0, H*x / y };
	point P2 = { W, (H*x + (y - H)*W) / y };
	cnt = 0;
	P[cnt++] = { 0,0 };
	P[cnt++] = { W,0 };
	P[cnt++] = { W,W };
	P[cnt++] = { 0,W };
	Get(w[pv].A, w[pv].B, P1, P2);
}
double KK;
int stk[20];
void GetHull(point A, point B, double t) {
	int m = 0;
	double l = t*KK;
	TP[m++] = { A.x - l,A.y - l };
	TP[m++] = { A.x - l,A.y + l };
	TP[m++] = { A.x + l,A.y - l };
	TP[m++] = { A.x + l,A.y + l };
	TP[m++] = { B.x - l,B.y - l };
	TP[m++] = { B.x - l,B.y + l };
	TP[m++] = { B.x + l,B.y - l };
	TP[m++] = { B.x + l,B.y + l };
	sort(TP, TP + m);
	int top = 0, i;
	for (i = 0; i < m; i++) {
		while (top > 1 && ccw(TP[stk[top - 1]], TP[stk[top]], TP[i]) <= 0)top--;
		stk[++top] = i;
	}
	cnt = 0;
	for (i = 1; i < top; i++)P[cnt++] = TP[stk[i]];
	top = 0;

	for (i = 0; i < m; i++) {
		while (top > 1 && ccw(TP[stk[top - 1]], TP[stk[top]], TP[i]) >= 0)top--;
		stk[++top] = i;
	}
	for (i = top; i > 1; i--)P[cnt++] = TP[stk[i]];
}

bool Pos(double K) {
	KK = K;
	int i, curT = 0;
	point A = st, B = st;
	double eps = 1e-7;
	for (i = 1; i <= n; i++) {
		GetHull(A, B, w[i].T - curT + eps);
		if (!Get(A, B, w[i].A, w[i].B))return false;
		curT = w[i].T;
	}
	return true;
}
int main() {
	int i, j;
	double x, y;
	scanf("%d%lf%lf", &n, &W, &H);
	scanf("%lf%lf", &st.x, &st.y);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i].T);
		scanf("%lf%lf", &x, &y);
		Make(i, x, y);
	}
	double INF = 1e5;
	double b = 0.0, e = INF, mid;
	for (i = 0; i < 35; i++) {
		mid = (b + e)*0.5;
		if (Pos(mid)) e = mid;
		else b = mid;
	}
	if (b > INF*0.8) {
		puts("-1");
		return 0;
	}
	printf("%.10f\n", (b + e)*0.5);
}