#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	string a;
	char last = 'a';
	int sum = 0;
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		int value = abs((int)(a[i] - last));
		sum += min(value, 26 - value);
		last = a[i];
	}
	cout << sum;

	//string tmp;
	//cin >> tmp;
	return 0;
}