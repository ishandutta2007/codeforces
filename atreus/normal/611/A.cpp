#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll maxn = 5e5 + 10;
const ll mod = 1e9 + 7;
const ll base = 13;
const ll inf = 1e18;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	getline(cin, s);
	if (s.back() == 'k'){
		int k = (int)(s[0] - '0');
		if (k == 5 or k == 6)
			cout << 53 << endl;
		else
			cout << 52 << endl;
		return 0;
	}
	int k = (int)(s[0] - '0');
	if (s[1] != ' ')
		k = 10 * k + (int)(s[1] - '0');
	if (k <= 29)
		cout << 12 << endl;
	else if (k == 30)
		cout << 11 << endl;
	else
		cout << 7 << endl;
}