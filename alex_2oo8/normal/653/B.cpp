#include<bits/stdc++.h>

using namespace std;

char a[36][3], b[36][2], s[6];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) scanf("%s %s", a[i], b[i]);
	
	int ans = 0, x = 1;
	for (int i = 0; i < n; i++) x *= 6;
	for (int i = 0; i < x; i++) {
		int x = i;
		for (int j = 0; j < n; j++, x /= 6) s[j] = 'a' + (x % 6);
		
		bool ok = true;
		for (int j = 0; j < n - 1 && ok; j++) {
			ok = false;
			for (int k = 0; k < q; k++)
				if (s[j] == a[k][0] && s[j + 1] == a[k][1]) {
					s[j + 1] = b[k][0];
					ok = true;
					break;
				}
		}
		
		if (ok && s[n - 1] == 'a') ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}