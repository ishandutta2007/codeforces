#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5, N2 = N << 1;
const int bzmax = 19;

const double eps = 1e-7;
const double dinf = 1e100;
const double pi = acos(-1);
const double pi2 = pi * 2;

typedef class Segment {
	public:
		double l, r;
		int id;

		Segment() {	}
		Segment(double a, double b, int id = 0) : l(a), r(b), id(id) {
			(l > r) && (swap(l, r), 0);
		}
		
		boolean operator < (Segment b) const {
			return (l != b.l) ? (l < b.l) : (r < b.r);
		}
} Segment;

int n, m;
boolean exist[N];
int bz[bzmax][N2];
double Ls[N], Rs[N];
double deg[N], dis[N];
vector<Segment> seg, _seg;

boolean check(double mid) {
	seg.clear(), _seg.clear();
	for (int i = 1; i <= n; i++) {
		double dr = acos(mid / dis[i]);
		Segment s(deg[i] - dr, deg[i] + dr, i);
		while (s.l < -pi)
			s.l += pi2;
		while (s.l >= pi)
			s.l -= pi2;
		while (s.r < -pi)
			s.r += pi2;
		while (s.r >= pi)
			s.r -= pi2;
		if (s.l > s.r)
			swap(s.l, s.r);
		if (s.r - s.l > pi) {
			Ls[i] = s.r, Rs[i] = s.l + pi2;
			_seg.emplace_back(s.r, s.l + pi2, i);
			_seg.emplace_back(s.r - pi2, s.l, i);	
		} else {
			Ls[i] = s.l, Rs[i] = s.r;
			_seg.push_back(s);
		}
		exist[i] = true;
	}
	sort(_seg.begin(), _seg.end());
	reverse(_seg.begin(), _seg.end());
	double R = dinf;
	for (auto s : _seg) {
		if (s.r < R) {
			R = s.r;
//			seg.push_back(s);
//			cerr << s.l << " " << s.r << '\n';
		} else {
			exist[s.id] = false;
		}
	}
	for (auto s : _seg) {
		if (exist[s.id]) {
			exist[s.id] = false;
			seg.emplace_back(Ls[s.id], Rs[s.id]);
		}
	}
	reverse(seg.begin(), seg.end());
	int s = seg.size(), s2 = s << 1;
	for (int i = 0; i < s; i++) {
		seg.emplace_back(seg[i].l + pi * 2, seg[i].r + pi * 2);
	}
	bz[0][s2] = s2;
	for (int i = 0; i < s2; i++) {
		int l = i, r = s2 - 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (seg[mid].l <= seg[i].r) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		bz[0][i] = l; 
	}
	for (int i = 1; i < bzmax; i++) {
		for (int j = 0; j <= s2; j++) {
			bz[i][j] = bz[i - 1][bz[i - 1][j]];
		}
	}
	for (int i = 0; i < s; i++) {
		int p = i;
		for (int j = 0; (m >> j); j++) {
			if ((m >> j) & 1) {
				p = bz[j][p];
			}
		}
		if (p - i >= s) {
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	double l = 0, r = dinf, mid;
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y);
		deg[i] = atan2(y, x);
		r = min(r, dis[i] = sqrt(1ll * x * x + 1ll * y * y));
	}
	for (int t = 0; t < 64 && (r - l > eps); t++) {
		mid = (l + r) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("%.9lf", l);
	return 0;
}