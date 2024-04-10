#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> cnt;
int a[1000];

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		
		if (cnt.count(a[i]) == 0) cnt[a[i]] = 0;
		
		cnt[a[i]]++;
		
		if (a[i] == 0) ans++;
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && (a[i] != 0 || a[j] != 0)) {
				int k = 2;
				
				cnt[a[i]]--;
				cnt[a[j]]--;
				
				int p = a[i], q = a[j];
				while (1) {
					int r = p + q;
					p = q;
					q = r;
					
					if (cnt.count(r) == 1 && cnt[r] > 0) {
						cnt[r]--;
						k++;
					}
					else break;
				}
				
				ans = max(ans, k);
				
				p = a[i], q = a[j];
				while (k) {
					cnt[p]++;
					
					int r = p + q;
					p = q;
					q = r;
					
					k--;
				}
			}
	
	printf("%d\n", ans);
	
	return 0;
}