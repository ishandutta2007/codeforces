#include <iostream>
#include <vector>
using namespace std;

int get(long long n, int m) {
	return (n >> m) & 1;
}
vector <int> l;
vector <int> r;
int main() {
	int n;
	long long m;
	cin >> n;
	cin >> m;
	m--;
	for (int i = n - 2; i >= 0; i--) {
		if (get(m, i) == 0)
			l.push_back(n - i - 1);
		else
			r.push_back(n - i - 1);
	}
	for (int i = 0; i < l.size(); i++) {
		cout << l[i] << " ";
	}
	cout << n << " ";
	for (int i = (int) r.size() - 1; i >= 0; i--) {
		cout << r[i] << " ";
	}
	return 0;
}