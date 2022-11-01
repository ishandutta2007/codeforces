#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
	int n, c1 = 0, c2 = 0, ans;
	cin >> n, ans = n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] == c1 && a[i] == c2) --ans;
		else if (a[i] == c1 || a[i] == c2) c1 = c2 = a[i];
		else if (a[i+1] == c2) c2 = a[i];
		else c1 = a[i];
	}
	cout << ans << endl;
}