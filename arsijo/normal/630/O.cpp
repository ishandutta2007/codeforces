#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-9;
template<typename T> T sqr(T t) {
	return t * t;
}
#define ms(x) memset(x, 0, sizeof(x))
#define endl "\n"
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define input _read("input.txt")
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

struct point{
	ld x, y;
	point(ld x, ld y){
		this->x = x;
		this->y = y;
	}
	point operator*(ld a){
		return point(x * a, y * a);
	}
	point operator%(ld len){
		ld a = sqrt(sqr(len) / (sqr(x) + sqr(y)));
		return point(x * a, y * a);
	}
	point operator+(point p){
		return point(x + p.x, y + p.y);
	}
	point operator^(bool o){
		if(o){
			return point(y, -x);
		}else{
			return point(-y, x);
		}
	}
};

ostream& operator<<(ostream &cout, point p){
	cout << p.x << " " << p.y;
	return cout;
}

int main() {

	sync;
	cout.precision(10);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	ld x, y;
	cin >> x >> y;
	point center(x, y);
	cin >> x >> y;
	point vec(x, y);
	ld a, b, c, d;
	cin >> a >> b >> c >> d;
	point upcenter = center + (vec % b);
	point vec_left = vec ^ false;
	point vec_right = vec ^ true;
	point left = center + (vec_left % (a / 2));
	point right = center + (vec_right % (a / 2));
	point center_left = center + (vec_left % (c / 2));
	point center_right = center + (vec_right % (c / 2));
	point vec_down = vec_left ^ false;
	point down_left = center_left + (vec_down % d);
	point down_right = center_right + (vec_down % d);

	cout << upcenter << endl << left << endl << center_left << endl << down_left << endl << down_right << endl << center_right << endl << right << endl;

}