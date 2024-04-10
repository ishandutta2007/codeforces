#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;


const int N = 305;

int cnt[N];



int get(int x, int y) {
	return (x >> y) & 1;
}
bool pal(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	int n, k, x;
	cin >> n >> k >> x;
	int s = k * x;
	for (int i = 0; i < n - k; i++) {
		int a;
		cin >> a;
		s += a;
	}
	cout << s;
}