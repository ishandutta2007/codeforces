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
string s;

int main() {
	int x, h, m, ans = 0;
	cin >> x >> h >> m;
	while (h % 10 != 7 && h / 10 != 7 && m % 10 != 7 && m / 10 != 7) {
		m -= x;
		if (m < 0) {
			h--;
		}
		m = (m + 60) % 60, h = (h + 24) % 24;
		ans++;
	}
	cout << ans;
}