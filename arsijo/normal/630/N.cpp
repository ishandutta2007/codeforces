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


int main() {

	sync;
	cout.precision(10);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	ld a, b, c;
	cin >> a >> b >> c;

	ld d = (ld) sqrt(b * b - 4 * a * c);

	vector<ld> vec;
	vec.push_back((-b + d) / (2 * a));
	vec.push_back((-b - d) / (2 * a));
	sort(vec.begin(), vec.end());
	cout << vec[1] << endl << vec[0] << endl;


}