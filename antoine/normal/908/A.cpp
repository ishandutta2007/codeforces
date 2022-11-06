#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isVowel(char c) {
	static string vowels = "aeiou";
	for (char d : vowels)
		if (c == d)
			return true;
	return false;
}

bool isOdd(char c) {
	return (c - '0') & 1;
}

bool isDigit(char c) {
	return '0' <= c && c <= '9';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	int ans = 0;
	for (char c : s)
		ans += (isDigit(c) && isOdd(c)) || (!isDigit(c) && isVowel(c));
	cout << ans;
	return 0;
}