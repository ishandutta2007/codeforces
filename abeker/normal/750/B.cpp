#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

const int MAX = 40000;

void no() {
	puts("NO");
	exit(0);
}

int main() {
	int N;
	cin >> N;
	int x = 0;
	while (N--) {
		int t;
		string s;
		cin >> t >> s;
		if (!x && s[0] != 'S')
			no();
		if (x == MAX / 2 && s[0] != 'N')
			no();
		if (x < MAX / 2) {
			if (s[0] == 'S') {
				x += t;
				if (x > MAX / 2)
					no();
			}
			else if (s[0] == 'N') {
				x -= t;
				if (x < 0)
					no();
			}
		}
		else {
			if (s[0] == 'S') {
				x -= t;
				if (x < MAX / 2)
					no();
			}
			else if (s[0] == 'N') {
				x += t;
				if (x > MAX)	
					no();
			}
		}
		x += MAX;
		x %= MAX;
	}
	
	if (x)
		no();
		
	puts("YES");
	return 0;
}