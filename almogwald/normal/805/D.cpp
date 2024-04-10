
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
	char a[1000003];
	string s;
	cin >> a;
	s.assign(a);
	int bs = 0, sum = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == 'b') {
			bs++;
		}
		else {
			sum = (sum+bs)% 1000000007;
			bs *= 2;
			bs = bs % 1000000007;
		}
	}
	cout << sum << endl;
	return 0;
}