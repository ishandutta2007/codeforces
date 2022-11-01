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
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> y[i];
	}
	int maxi = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int p = y[j], q = x[i];
			if (p % q == 0) {
				if (p / q > maxi) {
					maxi = p / q;
					cnt = 0;
				}
				if (p / q == maxi) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}