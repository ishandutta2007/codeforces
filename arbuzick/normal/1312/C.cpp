#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		vector<long long> a(n);
		for (int j = 0; j < n; j++) 
			cin >> a[j];
		vector<long long> st1;
		vector<int> st2;
		st1.push_back(1);
		st2.push_back(0);
		for (int j = 1; j < 64; j++) {
			if (st1[j - 1] * k > 10000000000000000)
				break;
			st2.push_back(0);
			st1.push_back(st1[j - 1] * k);
		}
		for (int j = 0; j < n; j++) {
			for (int l = st1.size()-1; l >= 0; l--) {
				if (a[j] >= st1[l]) {
					if (st2[l] == 0) {
						st2[l] = 1;
						a[j] -= st1[l];
					}
				}
			}
		}
		for (int j = 0; j < n; j++) {
			if (a[j] != 0) {
				cout << "NO" << endl;
				break;
			}
			if (j == n - 1)
				cout << "YES" << endl;
		}
	}
	return 0;
}