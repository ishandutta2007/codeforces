//#include "stdafx.h"
#include <string>
#include <sstream>
#include <utility>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> point;
int main() {
	int n;
	cin >> n;
	vector<int> char_f(27);
	vector<int> char_b(27);
	vector<int> must_c;
	string line;
	for (int k = 0; k < n; k++) {
		cin >> line;
		must_c.push_back(line[0] - 'a' + 1);
		for (int i = 0; i < line.length() - 1; i++) {
			int a = line[i] - 'a' + 1;
			int b = line[i+1] - 'a' + 1;
			if ((char_f[a] != 0 && char_f[a] != b) || (char_b[b] != 0 && char_b[b] != a)) {
				cout << "NO" << endl;
				return 0;
			}
			char_f[a] = b;
			char_b[b] = a;
		}
	}
	// TODO anti lops search
	for (int i = 1; i <= 26; i++) {
		int r = i;
		for (int j = 1; j <= 30; j++) {
			r = char_f[r];
		}
		if (r != 0) {
			cout << "NO" << endl;
			return 0;
		}
		r = i;
		for (int j = 1; j <= 30; j++) {
			r = char_b[r];
		}
		if (r != 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	vector<int> done_c(27);
	vector<string> answer;
	while (!must_c.empty()) {
		int c = must_c.back();
		must_c.pop_back();
		if (done_c[c] == 1) {
			continue;
		}
		while (char_b[c] != 0) {
			c = char_b[c];
		}
		string newer = "";
		while (c != 0) {
			newer.push_back(c + 'a' - 1);
			done_c[c] = 1;
			c= char_f[c];
		}
		answer.push_back(newer);
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
	cout << endl;
	return 0;
}