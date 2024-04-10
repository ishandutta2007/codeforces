#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int N = 505;

bool mark[N];
//bool b[N];
int a[N];
vector <int> vec;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - k - 1; i++) {
		cout << "? ";
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!mark[j]) {
				cout << j << " ";
				cnt++;
			}
			if (cnt == k) {
				break;
			}
		}
		cout << endl;
		cout.flush();
		int x, y;
		cin >> x >> y;
		mark[x] = true;
	//	b[y] = true;
	}
/*	cout << "? ";
	for (int i = 1; i <= n; i++) {
		cout << "? ";
		if (!mark[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
	cout.flush();*/
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			vec.push_back(i);
		}
	}
	sort(vec.begin(), vec.end());
	int c = -1, d = -1, s1 = 0, s2 = 0;
//	cout << "73 " << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << "? ";
		for (int j = 0; j < vec.size(); j++) {
			if (j != i) {
				cout << vec[j] << " ";
			}
		}
		cout << endl;
		cout.flush();
		int x, y;
		cin >> x >> y;
		if (c == -1) {
			c = y;
			s1 = 1;
		}
		else {
			if (c == y) {
				s1++;
			}
			else {
				d = y;
				s2++;
			}
		}
	}
	if (d < c) {
		swap(c, d);
		swap(s1, s2);
	}
	cout << "! " << s2 << endl;
	return 0;
}