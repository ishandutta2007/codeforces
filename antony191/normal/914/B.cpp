#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(100001);
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	vector<int> b;
	for (int i = 0; i <= 100000; ++i)
		if (a[i] > 0)
			b.push_back(a[i]);
	n = b.size();
	bool k = (b[n - 1] & 1) == 1;
	for (int i = n - 2; i >= 0; --i) {
		if ((b[i] & 1) == 1)
			k = true;
	}
	if (k)
		cout << "Conan";
	else
		cout << "Agasa";
	return 0;
}