#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int b[N];
vector <int> vec1, vec2;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			a[i] = c - '0';
		}
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			b[i] = c - '0';
		}
	//	if (a[0] == 0) {
	//		vec1.push_back(0);
	//		a[0] = 1;
	//	}
		int s = 0, cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			int k = s;
			if (cnt % 2) {
				k -= i;
			}
			else {
				k += i;
			}
			if ((a[k] ^ b[i]) != cnt % 2) {
				if ((a[s] ^ b[i]) == cnt % 2) {
					vec1.push_back(0);
				}
				vec1.push_back(i);
				s = k;
				cnt++;
			}
		}
		cout << vec1.size() << " ";
		for (auto x : vec1) {
			cout << x + 1 << " ";
		}
		cout << '\n';
		vec1.clear();
		vec2.clear();
	}
	
	return 0;
}