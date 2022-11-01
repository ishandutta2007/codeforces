/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \
      	
*/

#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
	long long n, k; cin >> n >> k;
	long long ans = (k * (1 + n/k));
	cout << ans << endl;
	return 0;
}