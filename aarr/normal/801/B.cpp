#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
vector <char> vec;
deque <int> q;
bool mark[N];
char c[55][55];

int main() {
	string x, y;
	cin >> x >> y;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] <  y[i]) {
			cout << -1;
			return 0;
		}
	}
	cout << y;
}