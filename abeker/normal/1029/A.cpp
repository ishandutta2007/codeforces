#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	string s;
	cin >> N >> K >> s;
	
	string curr = s;
	for (int i = 1; i < K; i++) {
		int tmp = 0;
		for (int j = 1; j < s.size(); j++)
			if (curr.substr((int)curr.size() - j, j) == s.substr(0, j))
				tmp = j;
		curr += s.substr(tmp, (int)s.size() - tmp);
	}

	cout << curr << endl;
	
	return 0;
}