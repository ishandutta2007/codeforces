#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
	bool zero = false;
	int sum = 0, even = 0;
	for (int i = 0; i < s.size(); i++) {
		int digit = s[i] - '0';
		sum += digit;
		if (!digit)
			zero = true;
		if (!(digit % 2))
			even++;
	}
	return !(sum % 3) && zero && even >= 2;
}

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		string s;
		cin >> s;
		puts(check(s) ? "red" : "cyan");
	}
	return 0;
}