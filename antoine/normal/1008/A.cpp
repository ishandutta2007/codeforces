#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

bool vowel(char c) {
	const static string vowels = "aeiou";
	return binary_search(vowels.begin(), vowels.end(), c);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i)
		if (!vowel(s[i]) && s[i] != 'n' && (i + 1 == s.size() || !vowel(s[i + 1]))) {
			cout << "NO";
			cerr << i;
			return 0;
		}
	cout << "YES";
	return 0;
}