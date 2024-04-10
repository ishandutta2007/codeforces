#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (1ll*b*c < a) {
			puts("-1");
			continue;
		}
		int t = a/b/d;
		cout << 1ll*(t+1)*a-1ll*t*(t+1)/2*b*d << endl;
	}
}