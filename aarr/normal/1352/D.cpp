#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a[100 * 1000 + 5];
vector <int> vec;
deque <int> q;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			q.push_back(x);
		}
		int s = 0, a = 0, b = 0;
		int x = 0;
		while (q.size()) {
			x++;
			int s1 = 0;
			while (q.size() && s1 <= s) {
				s1 += q.front();
				q.pop_front();
			}	
			s = 0;
			if (q.size()) {
				x++;
			}
			while (q.size() && s <= s1) {
				s += q.back();
				q.pop_back();
			}
			a += s1, b += s;
		}		
		cout << x << " " << a << " " << b << endl;
	}

	return 0;
}