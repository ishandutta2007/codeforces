#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool query(const int x, const int y) {
	cout << "? " << x << ' ' << y << endl;
	char res;


	cin >> res;


	// static int a = (int)1e9;
	// res = x%a >= y%a ? 'x' : 'y';

	////



	if (res == 'e')
		exit(0);
	assert(res == 'x' || res == 'y');
	return res == 'x';
}

void done(const int x) {
	cout << "! " << x << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (;;) {
		{
			string s;
			cin >> s;
			if (s == "end")
				return 0;
			if (s == "mistake")
				exit(0);
			assert(s == "start");
		}

		if(query(0, 1)) {
			done(1);
			continue;
		}


		ll lo = 2;
		ll hi = (ll) 1e9;

		while (lo + 1 < hi) {
			const ll mid = min((lo + hi) / 2, 2 * (lo - 1));
			const bool res = query(lo - 1, mid);
			if (res)
				hi = mid;
			else
				lo = mid + 1;
		}

		if (lo < hi) {
			cerr << "test" << endl;
			assert(lo + 1 == hi);
			const bool res = query(lo, hi);
			if (res)
				lo = hi;
			else
				hi = lo;

		}

		done(lo);
	}
	return 0;
}