#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
bool aeiouy(char c) {
	if (c == 'A' || c == 'E' || c == 'O' || c == 'I' || c == 'U' || c == 'Y') {
		return true;
	}
	return false;
	
}
int main()
{
	string a;
	int last = -1,max=0;
	cin >> a;
	int length = a.length();
	for (int i = 0; i < length; i++) {
		if (aeiouy(a[i])) {
			if (max < i - last) {
				max = i - last;
			}
			last = i;
		}
	}
	if (max <  length - last) {
		max = length - last;
	}
	cout << max;

	//string tmp;
	//cin >> tmp;
	return 0;
}