#include <bits/stdc++.h>
using namespace std;

#define double long double
const int N = 3e3 + 5;
const double PI = acos(-1);
const double eps = 1e-9;

int n, R, x[N], y[N], ans; bool ban[N][N];
double sq(double x) {return x * x;}
double dis(int i, int j) {return sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]));}
double Arg(int i, int j) {
	if(x[i] == x[j]) return y[j] > y[i] ? PI / 2 : PI * 3 / 2;
	if(y[i] == y[j]) return x[j] > x[i] ? 0 : PI;
	double T = atan2(abs(y[j] - y[i]), abs(x[j] - x[i]));
	if(x[i] < x[j] && y[i] < y[j]) return T;
	if(x[i] > x[j] && y[i] < y[j]) return PI - T;
	if(x[i] > x[j] && y[i] > y[j]) return PI + T;
	if(x[i] < x[j] && y[i] > y[j]) return 2 * PI - T;
	assert(0);
}

struct Interval {
	double l, r;
	Interval(double _l, double _r) {l = _l, r = _r;}
	Interval shift(double del) {return Interval(l + del, r + del);}
	bool In(double x) {return l - eps <= x && x <= r + eps;}
}; Interval Intersect(Interval x, Interval y) {return Interval(max(x.l, y.l), min(x.r, y.r));}

int main(){
	cin >> n >> R;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++) {
		Interval seq(0, 2 * PI); bool split = 0;
		for(int j = 1; j <= n && seq.l - eps < seq.r; j++) {
			double d = dis(i, j);
			if(d <= R) continue;
			double alpha = Arg(i, j), theta = asin(R / d);
			Interval cur(alpha - theta - eps, alpha + theta + eps);
			if(cur.r > 2 * PI) cur = cur.shift(-2 * PI);
			Interval nw = Intersect(seq, cur);
			if(cur.l < 0) {
				if(split) seq = nw;
				else {
					if(seq.l == 0 && seq.r == 2 * PI) seq = cur;
					else if(nw.l - eps < nw.r) seq = nw;
					else seq = Intersect(seq.shift(-2 * PI), cur);
					split = 1;
				}
			} else {
				if(split) {
					if(nw.l - eps < nw.r) seq = nw;
					else seq = Intersect(seq, cur.shift(-2 * PI));
				} else seq = nw;
			}
		}
		if(seq.l - eps > seq.r) {
			for(int j = 1; j <= n; j++) ban[i][j] = 1;
			continue;
		} 
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			double alpha = Arg(i, j);
			ban[i][j] |= !seq.In(alpha) && !seq.shift(2 * PI).In(alpha);
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			ans += !ban[i][j] && !ban[j][i];
	cout << ans << endl;
	return 0;
}