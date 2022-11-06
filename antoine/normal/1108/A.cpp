#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q;
	cin >> q;
	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (l1 != r2)
			cout << l1 << ' ' << r2 << endl;
		else
			cout << r1 << ' ' << l2 << endl;
	}
	return 0;
}