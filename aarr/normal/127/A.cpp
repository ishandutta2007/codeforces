#include <iostream>
#include <iomanip>
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
int x[N], y[N];;


int main() {
	int n, k;
	cin >> n >> k;
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		if (i > 1) {
			ans += sqrt((x[i] - x[i - 1]) * (x[i] - x[i - 1]) + (y[i] - y[i - 1]) * (y[i] - y[i - 1]));
		}
	}
	ans /= 50;
	ans *= k;
	cout << fixed << ans;
}