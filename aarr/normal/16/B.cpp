#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

pair<int, int> a[N];
int b[N];
vector <char> vec;
deque <int> q;
bool mark[N];
char c[55][55];
string s[N];

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a, a + m);
	for (int i = m - 1; i >= 0; i--) {
		int x = min(n, a[i].second);
		n -= x;
		ans += x * a[i].first;
	}
	cout << ans; 
}