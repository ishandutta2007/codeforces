/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \
      	
*/

#include <bits/stdc++.h>

using namespace std;

int n, x, y; string s;

int main (int argc, char const *argv[]) {
	cin >> n; 
	bool flag = 0;
	while (n--) {
		cin >> s >> x >> y;
		if (x >= 2400 and y > x) flag = 1;
	}
	cout << (flag ? "YES\n" : "NO\n");
    return 0;
}