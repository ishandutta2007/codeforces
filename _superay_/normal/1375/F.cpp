#include <bits/stdc++.h>
using namespace std;
int main() {
	long long a[4], tmp;
	cin >> a[1] >> a[2] >> a[3];
	cout << "First" << endl;
	tmp = 3 * max(max(a[1], a[2]), a[3]) - a[1] - a[2] - a[3];
	cout << tmp << endl;
	int id;
	cin >> id;
	if (a[id] == max(max(a[1], a[2]), a[3])) {
		a[id] += tmp;
		tmp = 3 * max(max(a[1], a[2]), a[3]) - a[1] - a[2] - a[3];
		cout << tmp << endl;
		cin >> id;
	}
	a[id] += tmp;
	tmp = (max(max(a[1], a[2]), a[3]) - min(min(a[1], a[2]), a[3])) / 2;
	cout << tmp << endl;
	cin >> id;
	assert(!id);
	return 0;
}