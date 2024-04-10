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
	int n, x = 0, ans = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i > 0 && x == 0 && s[i] == s[i - 1]) {
			ans++;
		}
		if (s[i] == 'U') {
			x++;
		}
		else {
			x--;
		}
	}
	cout << ans;
	return 0;
}