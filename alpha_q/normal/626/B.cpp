/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;

#define checkbit(n, b) ((n >> b) & 1)
#define gcd __gcd
#define bitcount __bultin_popcount
#define inf (int) 2e9
#define eps 1e-9
#define pi acos(-1)
#define mod 1000000007
#define exp 1000000005
#define MAX 300005

int n, R = 0, G = 0, B = 0, i; string S;

int main () {
	cin >> n >> S;
	for (i = 0; i < n; i++) {
		if (S[i] == 'R') ++R;
		if (S[i] == 'G') ++G;
		if (S[i] == 'B') ++B;
	}
	if (R == 0 && G == 0 && B) {
		cout << "B" << endl;
		return 0;
	}
	if (R == 0 && G && B == 0) {
		cout << "G" << endl;
		return 0;
	}
	if (R && G == 0 && B == 0) {
		cout << "R" << endl;
		return 0;
	}
	if (R == 0 && G && B) {
		if (G == 1 && B == 1) cout << "R" << endl;
		else if (G == 1) cout << "GR" << endl;
		else if (B == 1) cout << "BR" << endl;
		else cout << "BGR" << endl;
		return 0;
	}
	if (R && G == 0 && B) {
		if (R == 1 && B == 1) cout << "G" << endl;
		else if (R == 1) cout << "GR" << endl;
		else if (B == 1) cout << "BG" << endl;
		else cout << "BGR" << endl;
		return 0;
	}
	if (R && G && B == 0) {
		if (G == 1 && R == 1) cout << "B" << endl;
		else if (G == 1) cout << "BG" << endl;
		else if (R == 1) cout << "BR" << endl;
		else cout << "BGR" << endl;
		return 0;
	}
	else {
		cout << "BGR" << endl;
		return 0;
	}
	return 0;
}