#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 8005;

int a[N];
vector <int> vec;
deque <int> q;
bool mark[N];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a1, a2, b1, b2;
		cin >> a1 >> b1 >> a2 >> b2;
		if (a1 > b1) {
			swap(a1, b1);
		}
		if (a2 > b2) {
			swap(a2, b2);
		}
	//	cout << "73 " << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
		if (a1 + a2 == b2 && b1 == b2) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}