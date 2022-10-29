#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const char *dir = "lrud";
const string Dir[] = {"l", "r", "u", "d"};

#define L Copy(0)
#define R Copy(1)
#define U Copy(2)
#define D Copy(3)
#define _L _Copy(0)
#define _R _Copy(1)
#define _U _Copy(2)
#define _D _Copy(3)

string Copy(int d) {
	return Dir[d] + "10" + Dir[d ^ 1] + "t";
}
string _Copy(int d) {
	return Dir[d] + "01" + Dir[d ^ 1] + "t";
}

// and : 0(dir)t, stay in situ
string bit_plus() { // current and above
	string rt = L + "ur" + L + "0dt" + L + "rr";
	rt += _L + "dr" + _L + "u0dt" + _D;
	rt += "ru0dt" + _D + "0lt";
	return rt;
}

int main() {
	string ans = "";
	for (int i = 0; i < 34; i++) {
		ans += D + "usdt";
		if (i < 33) {
			ans += "l";
		}
	}
	ans += "u";
	for (int i = 0; i < 34; i++) {
		ans += U + "dsut";
		if (i < 33) {
			ans += "r";
		} 
	}
	ans += "rd0l";
	for (int i = 0; i < 32; i++) {
		ans += "d" + U + "uu" + D + "d" + bit_plus();
		ans += "r" + U + L + "ll" + D;
		ans += "rr" + bit_plus();
		ans += D + "ull" + _R + "ul" + _R;
		ans += "0dt" + _D + R;
		ans += "l";
	}
	ans += "d";
	cout << ans << '\n';
	return 0;
}