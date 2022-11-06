#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool query(int x, int y) {
	assert(0 <= x && x <= (int )1e9);
	assert(0 <= y && y <= (int )1e9);
	cout << x << ' ' << y << endl;
	string res;
	cin >> res;
	assert(res == "white" || res == "black");
	return res == "black";
}

bool col1;
char coord = ' ';

bool query(int x) {
	assert(0 <= x && x <= (int )1e9);
	assert(coord == 'x' || coord == 'y');
	if (coord == 'x')
		cout << x << ' ' << 0 << endl;
	else
		cout << 0 << ' ' << x << endl;
	string res;
	cin >> res;
	assert(res == "white" || res == "black");
	return (res == "black") != col1;
}

void done(const int x1, const int y1, const int x2, const int y2) {
	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	exit(0);
}

void done(const int x) {
	if(coord == 'x')
		done(x, 0, x, 1);
	else
		done(0, x, 1, x);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	if (n == 1) {
		query(0, 0);
		done(0, 1, 1, 0);
		return 0;
	}

	{
		bool ans1 = query(0, 0);
		bool ans2 = query((int)1e9, 0);
		if(ans1 == ans2) {
			coord = 'y';
			col1 = ans1;
		} else {
			coord = 'x';
			col1 = ans1;
		}
	}

	int lo = 1;
	int hi = (int)1e9 - 1;

	for(n -= 2; n > 0; --n) {
		assert(lo <= hi);
		const int mid = (lo + hi) / 2;
		if(query(mid))
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	assert(lo <= hi);
	done((lo + hi) / 2);
	cerr << lo << ' ' << hi << endl;
	return 0;
}