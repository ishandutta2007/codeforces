#include <iostream>
#include <algorithm>
using namespace std;


const int N = 26;


int cnt[N];

int main() {
	int n, x = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'a']++;
	}
	bool b = false;
	for (int i = 0; i < N; i++) {
		if (cnt[i] > 1) {
			b = true;
		}
	}
	if (b || n == 1) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}