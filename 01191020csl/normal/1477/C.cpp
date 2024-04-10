#include<bits/stdc++.h>
using namespace std;
long long x[5001], y[5001];
int vis[5001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	int p = 1;
	cout << 1;
	vis[1] = 1;
	for (int i = 2; i <= n; i++) {
		long long dis = 0;
		int nxt = 0;
		for (int j = 1; j <= n; j++)
			if (!vis[j]) {
				long long tmp = 1ll*(x[j]-x[p])*(x[j]-x[p])+1ll*(y[j]-y[p])*(y[j]-y[p]);
				if (tmp > dis) dis = tmp, nxt = j;
			}
		vis[nxt] = 1, p = nxt;
		cout << ' ' << p;
	}
	cout << endl;
}