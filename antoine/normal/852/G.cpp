#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <string>
#include <unordered_set>

int N, M;

std::string to3db6(int i) {
	std::string res = "";
	for (int c = 0; c < 3; ++c) {
		res += std::to_string(i % 6);
		i /= 6;
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> N >> M;
	std::unordered_map<std::string, int> occ;
	for (int i = 0; i < N; ++i) {
		std::string w;
		std::cin >> w;
		++occ[w];
	}


	while(--M >= 0) {
		std::unordered_set<std::string> done;
		std::string str;
		std::cin >> str;

		int ans = 0;
		for (int mask = 0; mask < 6 * 6 * 6; ++mask) {
			std::string sMask = to3db6(mask);
			std::string res = "";
			for (char c : str) {
				if (c != '?')
					res += c;
				else {
					if (sMask.empty()) return 1;
					char d = sMask[sMask.size() - 1] - '0' + 'a';
					if (d != 'f') res += d;
					sMask.resize(sMask.size() - 1);
				}
			}
			if(!done.count(res) && occ.count(res))
				ans += occ[res];
			done.insert(res);
		}
		std::cout << ans << '\n';
	}
	return 0;
}