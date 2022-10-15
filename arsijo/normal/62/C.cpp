#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[12];
int kkkk;
inline void write(int x) {
	kkkk = 0;
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar('\n');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

struct point {
	ld x, y;
	bool operator<(point b) {
		return (abs(x - b.x) >= E ? x < b.x : y < b.y);
	}
	point() {
		x = y = 0;
	}
	point(ld x, ld y) {
		this->x = x;
		this->y = y;
	}
};

istream& operator>>(istream &cin, point &p){
	cin >> p.x >> p.y;
	return cin;
}

ostream& operator<<(ostream &cout, point &p){
	cout << p.x << " " << p.y;
	return cout;
}

struct line {
	ld a, b, c;
	line(point a, point b) {
		this->a = a.y - b.y;
		this->b = b.x - a.x;
		this->c = a.x * b.y - a.y * b.x;
	}
};

struct segment {
	point a, b;
	segment(point a, point b) {
		this->a = a;
		this->b = b;
	}
};

pair<bool, point> operator&(line l1, line l2) {
	if (abs(l1.a * l2.b - l1.b * l2.a) < E)
		return make_pair(false, point(0, 0));
	ld y = (ld) (l2.a * l1.c - l2.c * l1.a) / (l2.b * l1.a - l1.b * l2.a);
	if (abs(l1.a) < E)
		swap(l1, l2);
	ld x = (-l1.c - l1.b * y) / l1.a;
	return make_pair(true, point(x, y));
}

ld dist(point a, point b){
	return (ld) sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

bool in(point a, point b, point c){
	return abs(dist(a, c) - dist(a, b) - dist(b, c)) < E;
}

pair<bool, point> operator&(segment s1, segment s2){
	pair<bool, point> pp = line(s1.a, s1.b) & line(s2.a, s2.b);
	if(!pp.first)
		return pp;
	return ((in(s1.a, pp.second, s1.b) && in(s2.a, pp.second, s2.b)) ? pp : make_pair(false, point(0, 0)));
}

vector<pair<pair<point, point>, point> > t;

ld get_s(ld a, ld b, ld c){
	ld d = max((ld) 0, (a + b + c) / 2);
	ld ans = (ld) sqrt(d * (d - a + E) * (d - b + E) * (d - c + E));
	if(ans != ans){
		assert(false);
		ans = 0;
	}
	return ans;
}

ld get_s(point a, point b, point c){
	ld s = 0;
	s += (a.x + b.x) * (a.y - b.y);
	s += (b.x + c.x) * (b.y - c.y);
	s += (c.x + a.x) * (c.y - a.y);
	return abs(s) / 2;
}

bool in(point a, point b, point c, point p){
	ld A = get_s(a, b, p);
	ld B = get_s(b, c, p);
	ld C = get_s(a, c, p);
	ld S = get_s(a, b, c);
	if(abs(A + B + C - S) >= E)
		return false;
	dbg cout << "@ " << A << " " << B << " " << C << endl;
	if(min(A, min(B, C)) < E)
		return false;
	return true;
}

bool in(point p){
	for(int i = 0; i < (int) t.size(); i++){
		if(in(t[i].first.first, t[i].first.second, t[i].second, p)){
			dbg cout << "FAIL " << p << " " << i << endl;
			return true;
		}
	}
	return false;
}

point operator|(point a, point b){
	return point((a.x + b.x) / 2, (a.y + b.y) / 2);
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n;
	cin >> n;

	vector<segment> vec;

	for(int i = 0; i < n; i++){
		point a, b, c;
		cin >> a >> b >> c;
		vec.push_back(segment(a, b));
		vec.push_back(segment(b, c));
		vec.push_back(segment(c, a));
		t.push_back(make_pair(make_pair(a, b), c));
	}

	ld ans = 0;
	for(int i = 0; i < (int) vec.size(); i++){
		vector<point> v;
		v.push_back(vec[i].a);
		v.push_back(vec[i].b);
		for(int j = 0; j < (int) vec.size(); j++){
			if(i == j)
				continue;
			pair<bool, point> t = vec[i] & vec[j];
			if(t.first)
				v.push_back(t.second);
		}
		dbg cout << vec[i].a << " " << vec[i].b << ": " << endl;
		sort(v.begin(), v.end());
		dbg for(int i = 0; i < (int) v.size(); i++)
			cout << "| " << v[i] << endl;
		for(int i = 1; i < (int) v.size(); i++){
			if(dist(v[i], v[i - 1]) >= E){
				if(!in(v[i] | v[i - 1])){
					point p = v[i] | v[i - 1];
					dbg cout << v[i] <<  " " << v[i - 1] << " " << p << endl;
					ans += dist(v[i], v[i - 1]);
				}
			}
		}
		dbg cout << endl;
	}

	cout << ans << endl;

}