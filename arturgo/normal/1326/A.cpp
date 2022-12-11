#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool est_divisible(const vector<int>& chaine, int n) {
	int p10 = 1, r = 0;
	for(int c : chaine) {
		r = (r + p10 * c ) % n;
		p10 = (10 * p10) % n;
	}
	return r == 0;
}

set<int> chiffres(const vector<int>& digits) {
	set<int> c;
	for(int dig : digits)
		c.insert(dig);
	return c;
}

bool est_valide(const vector<int>& digits) {
	for(int c : chiffres(digits)) {
		if(est_divisible(digits, c))
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);

	int nbTests;
	cin >> nbTests;

	for(int iTest = 0;iTest < nbTests;iTest++) {
		int n;
		cin >> n;

		if(n <= 1) {
			cout << "-1" << endl;
			continue;
		}

		vector<int> digits(n, 2);

		while(!est_valide(digits)) {
			int i = 0;
			while(digits[i] == 9) {
				digits[i] = 2;
				i++;
			}

			digits[i]++;
		}

		while(!digits.empty()) {
			cout << digits.back();
			digits.pop_back();
		}
		cout << endl;
	}
	return 0;
}