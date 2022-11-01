#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 8005;

int a[N];
vector <int> vec;
deque <int> q;
bool mark[N];

int main() {
	int n, m;
	cin >> n >> m;
	if (m <= 1) {
		cout << 1;
	}
	else {
		if (m <= n / 2) {
			cout << m;
		}
		else {
			cout << n - m;
		}
	}

	return 0;
}