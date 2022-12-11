#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a;
	cin >> a;
	char car;
	cin >> car;
	int b;
	cin >> b;
	
	int f;
	cin >> f;
	
	int s = a * 60 + b + f;
	s = s % (24 * 60);
	
	cout << s / 600 << (s / 60) % 10 << ":" << (s % 60) / 10 << (s % 10) << endl;
	return 0;
}