#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <set>
#include <map>


using namespace std;

int main() {
	int n; cin >> n;
	string s;
	cin >> s;
	string alph = "aeioyu";
	bool k = true;
	while (k) {
		k = false;
		for (int i = 1; i < s.size(); ++i)
			if (alph.find_first_of(s[i]) != string::npos && alph.find_first_of(s[i - 1]) != string::npos)
			{
				s.erase(i, 1);
				k = true;
				break;
			}
	}
	cout << s;
	return 0;
}