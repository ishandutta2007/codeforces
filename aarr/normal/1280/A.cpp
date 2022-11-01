#include <iostream>
using namespace std;

const int mod = 1000 * 1000 * 1000 + 7;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int x;
		cin >> x;
		string s;
	//	string c;
		cin >> s;
		long long y = (long long) s.size();
		for (int i = 1; i <= x; i++) {
			string c;
		//	if (s[i - 1] == '1') {
		//		continue;
		//	}
			for (int k = 1; k < s[i - 1] - '0'; k++) {
			//	int z = s.size();
				for (int j = i; j < s.size() && (int) s.size() + c.size() <= 2 * x + 3; j++) {
					c += s[j];
				}
				
			}
			s += c;
			long long z = 1ll * (y - i + mod) * (s[i - 1] - '0') + i;	
			y = z % mod;	
		//	cout << s << " " << c << " " << y << endl;
		}
		cout << y << endl;
	}
	return 0;
}