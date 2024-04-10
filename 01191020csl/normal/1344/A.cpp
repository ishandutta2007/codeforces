#include<bits/stdc++.h>
using namespace std;
int vis[200000];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) vis[i] = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			vis[(i+a%n+n)%n]=1;
		}
		bool ans = 1;
		for (int i = 0; i < n; i++)
			if (!vis[i]) ans = 0;
		if (ans) puts("YES");
		else puts("NO");
	}
}