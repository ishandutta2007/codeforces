#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> odd, even;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x % 2) 
				odd.push_back(x);
			else 
				even.push_back(x);
		}
		bool ok = true;
		for (int i = 1; i < odd.size(); i++) 
			ok &= odd[i] >= odd[i - 1];
		for (int i = 1; i < even.size(); i++) 
			ok &= even[i] >= even[i - 1];
		cout << (ok ? "Yes\n" : "No\n");
	}
}