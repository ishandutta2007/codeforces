#include <iostream>
#include <vector>


using namespace std;

int min(vector<int> a);

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int k = min(a);
	vector<int> x;
	for (int i = 0; i < n; ++i) {
		if (a[i] == k)
			x.push_back(i);
	}
	vector<int> y;
	for (int i = 1; i < x.size(); ++i)
		y.push_back(x[i] - x[i - 1]);
	cout << min(y);
}

int min(vector<int> a) {
	int k = a[0];
	for (auto i = a.begin() + 1; i != a.end(); ++i) {
		if (k > *i)
			k = *i;
	}
	return k;
}