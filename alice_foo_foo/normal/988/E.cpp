#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

char c[200], d[200];
int len, ans = -1, ans1 = -1;

int main() {
	scanf("%s", c);
	len = strlen(c);
	for(int i = 0; i < len; i++) d[i] = c[i];
	bool ok = 0;
	for(int i = 0; i < len; i++) {
		if(c[i] == '5' || c[i] == '0') {
			ok = 1;
			break;
		}
	}
	if(!ok) cout << "-1";
	else {
		int ok = 0, ok1 = 0;
		int tmp = -1;
		for(int i = len - 1; i >= 0; i--) {
			if(c[i] == '5') {
				tmp = i;
				break;
			}
		}
		if(tmp != -1) {
			int AAA = 0;
			if(tmp == 0 && c[tmp + 1] == '0') {
				for(int i = 1; i < len; i++) {
					if(c[i] == '0') AAA++;
					else break;
				}
			}
			for(int i = tmp; i < len - 1; i++) swap(c[i], c[i + 1]);
			ans = len - 1 - tmp + AAA;
			for(int j = len - 2; j >= 0; j--) {
				if(c[j] == '2' || c[j] == '7') {
					ok = 1;
					ans = ans + len - 2 - j;
					break;
				}
			}
		}
		int tmp1 = -1;
		for(int i = len - 1; i >= 0; i--) {
			if(d[i] == '0') {
				tmp1 = i;
				break;
			}
		}
		if(tmp1 != -1) {
			for(int i = tmp1; i < len - 1; i++) swap(d[i], d[i + 1]);
			ans1 = len - 1 - tmp1;
			for(int j = len - 2; j >= 0; j--) {
				if(d[j] == '5' || d[j] == '0') {
					ans1 = ans1 + len - 2 - j;
					ok1 = 1;
					break;
				}
			}
		}
		if(!ok && !ok1) cout << "-1";
		else if(!ok) cout << ans1;
		else if(!ok1) cout << ans;
		else cout << min(ans, ans1);
	}
	return 0;
}