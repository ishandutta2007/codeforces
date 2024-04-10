#include <iostream>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
map <string, int> mp;
int b[N];
vector <int> vec;
deque <int> q;
bool mark[N];
char c[55][55];
string s[10], t[10];

bool get(int l, int r) {
	for (int i = 0; i <= r - l; i++) {
		if (s[l + i] != s[r - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, ans = 0;
	string s;
	cin >> s;
	while (cin >> s) {
		int c = 0;
		for (int i = 0; i < s.size(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z') {
			c++;
		}
		ans = max(ans, c);
	}
	cout << ans;
}