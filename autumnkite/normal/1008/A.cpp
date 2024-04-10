#include <bits/stdc++.h>

const char vowel[] = "aeiou";

int n;
char a[105];

bool is_vowel(char c) {
	for (int i = 0; i < 5; ++i) {
		if (c == vowel[i]) {
			return 1;
		}
	}
	return 0;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> (a + 1);
	n = strlen(a + 1);
	for (int i = 1; i <= n; ++i) {
		if (a[i] != 'n' && !is_vowel(a[i]) && (i == n || !is_vowel(a[i + 1]))) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
}