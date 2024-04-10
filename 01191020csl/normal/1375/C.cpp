#include<bits/stdc++.h>
using namespace std;
int a[300001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (a[1] < a[n]) puts("YES");
		else puts("NO");
	}
}