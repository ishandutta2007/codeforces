#include<bits/stdc++.h>

using namespace std;

int a[3], x[7], cnt[7];

bool f(int t) {
	int g = t;
	for (int i = 3; i >= 0; i--) {
		x[i] = cnt[i];
		int f = min(t, x[i]);
		
		x[i] -= f;
		t -= f;
	}
	
	if (x[0] > x[1]) {
		int f = (x[0] - x[1] + 1) / 2;
		
		x[0] -= f;
		x[1] += f;
	}
	
	if (x[2] + x[1] > g) return false;
	
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 3; i++) scanf("%d", a + i);
	
	sort(a, a + 3);
	
	for (int i = 1; i < 8; i++) x[i - 1] = (i % 2) * a[0] + (i / 2 % 2) * a[1] + (i / 4 % 2) * a[2];
	
	sort(x, x + 7);
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int f;
		scanf("%d", &f);
		
		if (f > a[0] + a[1] + a[2]) {
			printf("-1\n");
			
			return 0;
		}
		
		int j = 0;
		while (f > x[j]) j++;
		
		cnt[j]++;
	}
	
	ans += cnt[6];
	ans += cnt[5];
	cnt[0] -= min(cnt[0], cnt[5]);
	ans += cnt[4];
	n = min(cnt[1], cnt[4]);
	cnt[1] -= n;
	cnt[4] -= n;
	cnt[0] -= min(cnt[0], cnt[4]);
	
	if (a[0] + a[1] > a[2]) {
		ans += cnt[3];
		n = min(cnt[2], cnt[3]);
		cnt[2] -= n;
		cnt[3] -= n;
		n = min(cnt[1], cnt[3]);
		cnt[1] -= n;
		cnt[3] -= n;
		cnt[0] -= min(cnt[0], cnt[3]);
		
		while (cnt[0] + cnt[1] + cnt[2] > 0) {
			ans++;
			
			if (cnt[0] == 0 && cnt[1] == 0) cnt[2]--;
			
			for (int i = 0; i < 3; i++) {
				int j = i;
				while (j > 0 && cnt[j] == 0) j--;
				
				if (cnt[j] > 0) cnt[j]--;
			}
		}
	}
	else {
		int k = cnt[3];
		while (!f(k)) k++;
		
		ans += k;
	}
	
	printf("%d\n", ans);
	
	return 0;
}