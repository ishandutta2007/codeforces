#include <bits/stdc++.h>
using namespace std;
 
#define sqr(x) ((x) * (x))
#define rep(c) for (int t = 0; t < c; t++)
#define _rep(c, t) for (int t = 0; t < c; t++)
// #define X first
// #define Y second
#define int long long
#define ll long long
#define mp make_pair
#define _mp make_point
 
const double Pi = 3.141592653589793;
const int fMax = 4294967295;
 
long long input() { long long n; scanf("%lld", &n); return n; }
string sinput() { string s; cin >> s; return s; }
string _sinput() { string s; getline(cin, s); return s; }
 
struct point {
	double x, y;
	point() {
		x = y = 0;
	}
	point(double X, double Y) {
		x = X, y = Y;
	}
	void init() {
		scanf("%lf", &x);
		scanf("%lf", &y);
	}
	void show() {
		cout << "(" << x << ";" << y << ")" << endl;
	}
	void to_polar() {
		point r;
		r.x = sqrt(x * x + y * y);
		r.y = atan2(y, x);
		x = r.x;
		y = r.y;
	}
	void to_decart() {
		point r;
		r.x = x * cos(y);
		r.y = x * sin(y);
		x = r.x;
		y = r.y;
	}
	void rotate(double a) {
		point r;
		r.x = (int)(round((x * cos(a) - y * sin(a)) * 10000)) / 10000.;
		r.y = (int)(round((y * cos(a) + x * sin(a)) * 10000)) / 10000.;
		x = r.x;
		y = r.y;
	}
	void rotate(double a, point o) {
		point r;
		r.x = (int)(round((o.x + (x - o.x) * cos(a) - (y - o.y) * sin(a)) * 10000)) / 10000.;
		r.y = (int)(round((o.y + (x - o.x) * sin(a) + (y - o.y) * cos(a)) * 10000)) / 10000.;
		x = r.x;
		y = r.y;
	}
};
bool operator== (point a, point b) {
	return a.x == b.x && a.y == b.y;
}
bool pcmp(point a, point b) {
	return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
bool cw(const point &a, const point &b, const point &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
}
vector<point> convex_hull(vector<point> p) {
    int n = p.size();
    if (n <= 1)
        return p;
    int k = 0;
    sort(p.begin(), p.end(), pcmp);
    vector<point> q(n * 2);
    for (int i = 0; i < n; q[k++] = p[i++])
        for (; k >= 2 && !cw(q[k - 2], q[k - 1], p[i]); --k);
    for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--])
        for (; k > t && !cw(q[k - 2], q[k - 1], p[i]); --k);
    q.resize(k - 1 - (q[0] == q[1]));
    return q;
}
point make_point(double X, double Y) {
	point r(X, Y); return r;
}
double dist(long long x1, long long y1, long long x2, long long y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
double dist(point A, point B) {
	return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}
double vec(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}
double scalar(int x1, int y1, int x2, int y2) {
	return x1 * x2 + y1 * y2;
}
bool point_in_polygon(long long n, long long X1, long long Y1, vector <long long> const & x, vector <long long> const & y) {
	// 
	long long X2 = X1 + 1000001, Y2 = Y1 + 1;
	long long intersection_count = 0;
	for (long long i = 0; i < n; i++) {
		long long j = (!i ? n - 1 : i - 1);
		double t0 = vec(x[i], y[i], X1, Y1, X2, Y2);
		double t1 = vec(x[j], y[j], X1, Y1, X2, Y2);
		double t2 = vec(X1, Y1, x[i], y[i], x[j], y[j]);
		double t3 = vec(X2, Y2, x[i], y[i], x[j], y[j]);
		if (
				((t0 >= 0 && t1 < 0) || (t0 < 0 && t1 >= 0)) &&
				((t2 >= 0 && t3 < 0) || (t2 < 0 && t3 >= 0))
				)
			intersection_count++;
	}
	return intersection_count % 2 != 0;
}
double area(long long n, vector <point> const & a) {
	double res = 0;
	for (long long i = 1; i < n; i++)
		res += (a[i].x - a[i - 1].x) * (a[i].y + a[i - 1].y);
	res += (a[0].x - a[n - 1].x) * (a[0].y + a[n - 1].y);
	return fabs(res) / 2;
}
double angle(int x1, int y1, int x2, int y2, int x3, int y3) {
	const int ax = x2 - x1;
	const int ay = y2 - y1;
	const int bx = x2 - x3;
	const int by = y2 - y3;
	const double sc = scalar(ax, ay, bx, by);
	const double ms = sqrt(ax * ax + ay * ay) * sqrt(bx * bx + by * by);
	return acos(sc / ms);
}
double angle(point a) {
	return atan2(a.y, a.x);
}
 
vector <long long> prefix_function (string s, long long max_prefsuf_len = INT_MAX) {
	long long n = s.size();
	vector <long long> p((int)n);
	for (long long i = 1; i < n; i++) {
		long long j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j]) j++;
		if (j >= max_prefsuf_len) j = max_prefsuf_len;
		p[i] = j;
	}
	return p;
}
long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}
long long bpow(long long n, long long p) {
	if (!p)
		return 1LL;
	if (p % 2)
		return bpow(n, p - 1) * n;
	else {
		long long m = bpow(n, p >> 1);
		return m * m;
	}
}
bool prime(long long n) {
	if (!n || n == 1) return 0;
	for (long long i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}
bool primef(long long x){
	if(x == 2)
		return true;
	srand(time(NULL));
	rep(100) {
		long long a = (rand() % (x - 2)) + 2;
		if (gcd(a, x) != 1)
			return false;
		if (pow(a, x) != 1)
			return false;
	}
	return true;
}
int to10(string s, int p) {
	int n = s.size(), res = 0;
	for (int i = 0; i < n; i++) {
		res = res * p + (s[i] - '0');
	}
	return res;
}
 
string Sum(string a, string b) {
	int l = b.length() - a.length();
	int l1 = a.length() - b.length();
	if (a.length() > b.length())
		for (int i = 0; i < l1; i++)
			b = "0" + b;
	if (b.length() > a.length())
		for (int i = 0; i < l; i++)
			a = "0" + a;
	int buf = 0;
	string res = "";
	for (int i = a.length() - 1; i >= 0; i--){
		char tmp = (((a[i] - '0') + (b[i] - '0') + buf) % 10) + '0';
		res = tmp + res;
		buf = ((a[i] - '0') + (b[i] - '0') + buf) / 10;
	}
	if (buf == 1)
		res = '1' + res;
	return res;
}
string Mul(string a, string b){
	int buf = 0;
	int l = b.length() - a.length();
	int l1 = a.length() - b.length();
	if (a.length() > b.length())
		for (int i = 0; i < l1; i++)
			b = "0" + b;
	if (b.length() > a.length())
		for (int i = 0; i < l; i++)
			a = "0" + a;
	string s_buf("");
	string sum("0");
	int z = 0;
	for (int i = a.length() - 1; i >= 0; i--){
		for (int j = b.length() - 1; j >= 0; j--){
			s_buf += (((a[i] - '0')*(b[j] - '0') + buf) % 10 + '0');
			buf = ((a[i] - '0')*(b[j] - '0') + buf) / 10;
		}
		if (buf != 0)
			s_buf += buf + '0';
		reverse(s_buf.begin(), s_buf.end());
		for (int f = 0; f < z; f++)
			s_buf += '0';
		z++;
		sum = Sum(sum, s_buf);
		s_buf = "";
		buf = 0;
	}
	return sum;
}

main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
 	int n = input(), h = input(), k = input();
 	vector <int> a(n + 1);
 	for (int i = 0; i < n; i++)
 		a[i] = input();
 	int curh = 0, ans = 0;
 	for (int i = 0; i < n; i++) {
 		if (curh + a[i] <= h) {
 			curh += a[i];
 			// cout << "PUTTING " << i << " POTATO1 " << ans << " : " << curh << "\n";
 		} else {
 			ans += curh / k;
 			curh %= k;
 			// cout << "WAITING FOR " << i - 1 << " POTATO " << ans << " : " << curh << "\n";
 			if (curh + a[i] <= h) {
	 			curh += a[i];
	 		} else {
	 			ans += curh / k;
	 			curh %= k;
	 			if (curh + a[i] <= h) {
	 				curh += a[i];
	 			} else {
	 				curh = 0;
	 				curh += a[i];
	 				ans++;
	 			}
	 		}
 			// cout << "PUTTING " << i << " POTATO2 " << ans << " : " << curh << "\n";
 		}
 	}
 	if (curh) {
 		ans += ceil(1. * curh / k);
 	}
 	cout << ans;
}