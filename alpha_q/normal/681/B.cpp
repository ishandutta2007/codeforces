/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \
      	
*/

#include <bits/stdc++.h>

using namespace std;

const long long p = 1234567, q = 123456, r = 1234;

bool flag = 0;
long long n, a, b, c;

int main (int argc, char const *argv[]) {
	cin >> n; 
	for (a = 0; a * p <= n; ++a) {
		bool check = 0;
		for (b = 0; b * q <= n - a * p; ++b) {
			long long z = n - a * p - b * q;
			if (z % r == 0) {
				flag = 1, check = 1;
				break;
			}
		}
		if (check) break;
	}

	cout << (flag ? "YES\n" : "NO\n");
    return 0;
}