#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
int b[N];
vector <char> vec;
deque <int> q;
bool mark[N];
char c[55][55];

int main() {
	int n, x = 0, y = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		x |= a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		y |= b[i];
	}
	cout << x + y;
}