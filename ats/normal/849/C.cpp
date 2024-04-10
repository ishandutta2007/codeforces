#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	int k;
	cin >> k;
	string s;
	char a = 'a';
	int t = 0;
	int y = 0;
	if (k == 0) {
		s = "a";
	}
	while (k > 0) {
		s.push_back(a);
		t++;
		y += t;
		if (k < y) {
			y -= t;
			k = k - y;
			a = a + 1;
			t = 0;
			y = 0;
		}
	}
	if (a > 'z') {
		cerr << "ERROR" << endl;
	}
	cout << s << endl;
	//cerr << s.size() << endl;
	return 0;
}