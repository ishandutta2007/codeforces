#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	string g = "aeiou";
	int t = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] >= '0' && s[i] <= '9') {
			if (s[i] % 2 == 1)
				++t;
		}
		else
			if (g.find_first_of(s[i]) != string::npos)
				++t;
	cout << t;
	return 0;
}