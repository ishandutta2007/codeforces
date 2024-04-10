#include <bits/stdc++.h>

using namespace std;

long long a, b, c;

int main (void) {
	cin >> a >> b >> c;
	
	if (c == 0) {
		if (a == b) printf("YES\n");
		else printf("NO\n");
	} else {
		if ((b - a) % c != 0) printf("NO\n");
		else {
			long long n = (b - a)/c + 1;
			if (n > 0) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;	
}