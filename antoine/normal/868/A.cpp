#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

std::string pass;
int n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> pass >> n;
	bool first = false;
	bool second = false;
	for (int i = 0; i < n; ++i) {
		std::string word;
		std::cin >> word;
		if (word[0] == pass[1]) {
			//std::cout << "case1";
			second = true;
		}
		if (word[word.size() - 1] == pass[0]) {
			//std::cout << "case2";
			first = true;
		}
		for (int i = 0; i + 1 < word.size(); ++i)
			if (word[i] == pass[0] && word[i + 1] == pass[1]) {
				//std::cout << "case3" << i << '\n';
				first = second = true;
			}
	}
	std::cout << ((first && second) ? "YES" : "NO");
	return 0;
}