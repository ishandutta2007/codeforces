#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	string d = "";
	for (int i = 0; i < n; i++) {
                if (k == 0)
                    d += s[i];
                if (s[i] - 'a' > 'z' - s[i]) {
                    if (k > s[i] - 'a') {
                        k -= (s[i] - 'a');
                        d += 'a';
                    } else if (k != 0) {
                        d += (char) (s[i] - k);
                        k = 0;
                    }
                } else {
                    if (k > 'z' - s[i]) {
                        k -= ('z' - s[i]);
                        d += 'z';
                    } else if (k != 0) {
                        d += (char) (s[i] + k);
                        k = 0;
                    }
                }
            }
            if (k != 0)
                cout << -1 << endl;
            else
                cout << d << endl;
}