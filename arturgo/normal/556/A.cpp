#include <iostream>
using namespace std;

int main() {
	int s1 = 0, s2 = 0;
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) {
		char c;
		cin >> c;
		s1 += c - '0';
		s2 += '1' - c;
	}
	
	cout << abs(s1 - s2) << endl;
}