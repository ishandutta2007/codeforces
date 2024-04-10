#include <bits/stdc++.h>

using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 1e5;
//#define DEBUG
#else
const ll MAX = 5e5;
#endif

struct point {
	ll x, y, z;
	point() {
		x = y = z = 0;
	}
	point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

ll dist(point a, point b) {
	return sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z);
}

bool solve(point p[8]) {
	// a = b = c -> 8 12 12 4
	// a = b != c -> 8 4 4 8 4
	// a != b != c -> 4 4 4 4 4 4
	for (int q = 0; q < 8; q++) {
		vector<pair<ll, int> > vec;
		for (int i = 0; i < 8; i++)
			if (i != q)
				vec.push_back(make_pair(dist(p[q], p[i]), i));
		sort(vec.begin(), vec.end());
		if (vec[0].first == 0)
			return false;
		for (int i = 0; i < (int) vec.size(); i++)
			for (int i = 0; i < 3; i++)
				for (int j = i + 1; j < 3; j++)
					if (vec[i].first + vec[j].first
							!= dist(p[vec[i].second], p[vec[j].second]))
						return false;
	}
	return true;
}

point p[8];

bool solve(int pos) {
	if (pos == 8) {
		if (solve(p)) {
			cout << "YES\n";
			for (int i = 0; i < 8; i++)
				cout << p[i].x << " " << p[i].y << " " << p[i].z << endl;
			return true;
		}
		return false;
	}
	for (int i = 0; i < 6; i++) {
		if (solve(pos + 1))
			return true;
		if (i % 2 == 0) {
			swap(p[pos].x, p[pos].y);
		} else {
			swap(p[pos].y, p[pos].z);
		}
	}
	return false;
}

int main() {

	sync;
	cout.precision(20);

#ifdef LOCAL
	srand(time(NULL));
	input;
#else

#endif

	for(int i = 0; i < 8; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		p[i] = point(x, y, z);
	}

	if(!solve(1))
	cout << "NO";

}