#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int a[1000001], b[1000001];
int wa[1000001], wb[1000001];
bool check(int n) {
	for (int i = 1; i <= n; i++) wa[i] = a[i], wb[i] = b[i];
	if (wa[1] > wb[1]) return 0;
	wb[1] -= wa[1];
	for (int i = 2; i <= n; i++) {
		wa[i] -= wb[i-1];
		if (wa[i] > 0) wb[i] -= wa[i];
		if (wb[i] < 0) return 0;
	}
	return 1;
}
int main() {
	int t = read();
	while (t--) {
		int n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n; i++) b[i] = read();
		int l = 0, r = min(b[n], a[1]);
		while (l < r) {
			int mid = (l + r) / 2;
			a[1] -= mid;
			if (check(n - 1)) r = mid;
			else l = mid + 1;
			a[1] += mid;
		}
		a[1] -= l, b[n] -= l;
		if (check(n)) puts("YES");
		else puts("NO");
	}
}