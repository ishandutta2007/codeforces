/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \

*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

map <char, int> M;
string A, B = "";
long long Ans = 1;

string toBin (int x) {
	if (x == 0) return "000000";
	string ret = "";
	while (x) {
		ret += (char)('0' + (x & 1));
		x >>= 1;
	}
	while (ret.size() < 6) ret += '0';
	reverse(ret.begin(), ret.end());
	return ret;
}

int main (int argc, char const *argv[]) {
	for (int i = 0; i <= 9; ++i) M['0' + i] = i;
	for (int i = 10; i <= 35; ++i) M['A' + i - 10] = i;
	for (int i = 36; i <= 61; ++i) M['a' + i - 36] = i;
	M['-'] = 62, M['_'] = 63;

	cin >> A;
	for (int i = 0; i < A.size(); ++i) {
		B += toBin(M[A[i]]);
	}

	for (int i = 0; i < B.size(); ++i) {
		if (B[i] == '0') Ans *= 3, Ans %= MOD;
	}

	printf("%I64d\n", Ans);
	return 0;
}