#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
int b[N];
vector <char> vec;
deque <int> q;
bool mark[N];
char c[55][55];
string s[N];

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
		s[i].resize(unique(s[i].begin(), s[i].end()) - s[i].begin());
		bool b = false;
		for (int j = 0; j < i; j++) {
			if (s[i] == s[j]) {
				b = true;
			}
		}
		if (!b) {
			ans++;
		}
	}
	cout << ans;
}