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
vector <char> vec;
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
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		string s;
		cin >> s;
		int c = 0, x = 0, ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				c++;
			}
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0' && x != 0 && x != c) {
				ans++;
			}
			if (s[i] == '1') {
				x++;
			}
		}
		cout << ans << endl;
	}
}