#include <iostream>
#include <string>


using namespace std;

int main() {
	int a, h, c;
	cin >> a >> h >> c;
	int p, q;
	cin >> p >> q;
	int k = 0;
	string *s = new string[100000];
	while (p > 0) {
		if (p <= h) {
			s[k] = "STRIKE";
			break;
		}
		else {
			if (a <= q) {
				s[k] = "HEAL";
				a += c;
			}
			else {
				s[k] = "STRIKE";
				p -= h;
			}
		}
		++k;
		a -= q;
	}
	cout << k + 1 << '\n';
	for (int i = 0; i <= k; ++i) {
		cout << s[i] << '\n';
	}
	return 0;
}