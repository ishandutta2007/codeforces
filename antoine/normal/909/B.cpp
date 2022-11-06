#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;


int f(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return n + f(n - 2);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	cout << f(N);

	return 0;
}