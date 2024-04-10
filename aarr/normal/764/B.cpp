#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
vector <int> vec;
deque <int> q;
bool mark[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i * 2 <= n; i += 2) {
		swap(a[i], a[n - i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}