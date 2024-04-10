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
	long long n, x, y;
	cin >> n >> x >> y;
	if (y > x)
		swap(x, y);
	if (y - 1 <= n - x) 
		cout << "White";
	else
		cout << "Black";
}