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

ld solve(ld s, ld h) {
	return s * h / 3;
}

ld solve_1(ld a) {
	ld s = sqr(a) * (ld) sqrt(3) / 4;
	ld q = a * (ld) sqrt(3) / 2;
	ld w = q / 3;
	ld h = sqrt(sqr(q) - sqr(w));
	return solve(s, h);
}

ld solve_2(ld a) {
	ld s = a * a;
	ld q = a * (ld) sqrt(3) / 2;
	ld w = a / 2;
	ld h = sqrt(sqr(q) - sqr(w));
	return solve(s, h);
}

ld to_rad(ld degree) {
	return degree / 180 * M_PI;
}

ld solve_3(ld a) {
	ld w = tan(to_rad(54)) * (a / 2);
	ld s = a * w / 2 * 5;
	ld q = a * (ld) sqrt(3) / 2;
	ld h = sqrt(sqr(q) - sqr(w));
	return solve(s, h);
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	ld l1, l2, l3;
	cin >> l1 >> l2 >> l3;
	cout << solve_1(l1) + solve_2(l2) + solve_3(l3);

}