#include <iostream>
#include <algorithm>
using namespace std;

string tostring(long long a) {
	string s;
	while(a != 0) {
		s.push_back('0' + a % 10);
		a /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

long long tolong(string a) {
	long long res = 0;
	for(char car : a) {
		res = res * 10 + car - '0';
	}
	return res;
}

int main() {
	int nbs, mod;
	cin >> nbs >> mod;
	
	long long s = 0;
	for(int i = 1;i <= nbs;i++) {
		string deb = tostring(i);
		string fin = deb;
		reverse(fin.begin(), fin.end());
		long long val = tolong(deb + fin);
		s = (s + val) % mod;
	}
	
	cout << s << endl;
	return 0;
}