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
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			s += c[i][j];
			s += c[i + 1][j];
			s += c[i][j + 1];
			s += c[i + 1][j + 1];
			sort(s.begin(), s.end());
			if (s == "acef") {
				ans++;
			}
			s.clear();
		}
	}
	cout << ans;
}