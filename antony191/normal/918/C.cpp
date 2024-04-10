#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

bool c(const char &a, const char &b) {
	return ((a == '?' || a == '(') && (b == '?' || b == ')'));
		
}
int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	int sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == ')')
			continue;
		int max = 1, min = 1;
		for (int j = i + 1; j < n; ++j) {
			if (s[j] == '(') {
				min++;
				max++;
				continue;
			}
			if (s[j] == ')') {
				if (max == 0)
					break;
				--max;
				if (min == 0)
					min = 1;
				else
					--min;
			}
			else {
				++max;
				if (min == 0)
					min = 1;
				else
					--min;
			}
			if (min == 0)
				++sum;
		}
	}
	cout << sum;
	return 0;
}