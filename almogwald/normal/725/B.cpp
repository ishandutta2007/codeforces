#include <iostream>
#include <string>

using namespace std;
int served(char c) {
	if (c == 'f') {
		return 1;
	} else if (c == 'e') {
		return 2;
	}
	else if (c == 'd') {
		return 3;
	}
	else if (c == 'a') {
		return 4;
	}
	else if (c == 'b') {
		return 5;
	}
	else if (c == 'c') {
		return 6;
	}
}
int main()
{
	string line;
	cin >> line;
	char c = line[line.length() - 1];
	
	long long int num = 0;
	for (int i = 0; i < line.length() -1; i++) {
		num = 10 * num + line[i] - '0';
	}
	cout << ((num - 1) /4*16 + ((num-1)%2)*7 + served(c)) << "\n";
	return 0;
}