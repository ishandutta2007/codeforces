#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &e : a) 
			cin >> e;
		bool done = false;
		for (int i = 0; i < n; i++) {
			if (a[i] != i + 1) {
				int pos = 0;
				for (int j = i + 1; j < n; j++) {
					if (a[j] == i + 1) 
						pos = j;
				}
				reverse(a.begin() + i, a.begin() + pos + 1);
				done = true;
			}	
			if (done) 
				break;
		}
		for (int e : a) 
			cout << e << ' ';
		cout << '\n';
	}
}