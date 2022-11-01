#include <iostream>
#include <vector>
using namespace std;

vector <long long> vec;

long long bmm(long long x, long long y) {
	if (y == 0) {
		return x;
	}
	vec.push_back(x / y);
	long long ans = bmm(y, x % y);
}

int main() {
	long long x, y;
	cin >> x >> y;
	long long z = bmm(x, y);
	vec.back()--;
	if (z > 1) {
		cout << "Impossible";
	}
	else
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] > 0) {
				cout << vec[i] << (char) ('A' + (i % 2));
			}
		}
	return 0;
}