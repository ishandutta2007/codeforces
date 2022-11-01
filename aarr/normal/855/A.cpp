#include <iostream>
using namespace std;

const int N = 105;

string s[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		bool b = false;
		cin >> s[i];
		for (int j = 0; j < i; j++) {
			if (s[i] == s[j])
				b = true;
		}
		if (b)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}