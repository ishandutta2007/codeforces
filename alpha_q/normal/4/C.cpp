#include <bits/stdc++.h>

using namespace std;

map <string, int> M;

int main() {
	int n; cin >> n; 
	while (n--) {
		string s; cin >> s;
		if (M[s] == 0) M[s] = 1, cout << "OK\n";
		else {
			int num = M[s];
			++M[s]; string en = "";
			while (num) en = (char)('0' + (num % 10)) + en, num /= 10;
			cout << s + en << endl;
		}
	}
	return 0;
}