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
int d[55][55];

int main() {
	int n, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		t++;
		int s, d;
		cin >> s >> d;
		while (t - s < 0 || (t - s) % d != 0) {
			t++;
		}
	}
	cout << t;
}