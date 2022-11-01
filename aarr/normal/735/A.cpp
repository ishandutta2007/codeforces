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
	int n, k;
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'G' || s[i] == 'T') {
			for (i += k; i < n; i += k) {
				if (s[i] == '#') {
					cout << "NO";
					return 0;
				}
				if (s[i] == 'G' || s[i] == 'T') {
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";

}