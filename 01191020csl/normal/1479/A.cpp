#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2, a1, a2;
		cout << "? " << mid << endl;
		cin >> a1;
		cout << "? " << mid+1 << endl;
		cin >> a2;
		if (a1 > a2) l = mid + 1;
		else r = mid;
	}
	cout << "! " << l << endl;
}