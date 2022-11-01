#include<bits/stdc++.h>
using namespace std;
int a[100002];
double T[100002];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, l;
		cin >> n >> l;
		for (int i = 1; i <= n; i++) cin >> a[i];
		a[n+1] = l, T[n+1] = 0;
		int s = 0, e = n + 1;
		while (e - s > 1) {
			double t1 = T[s] + (a[s+1]-a[s])*1.0/(s+1), t2 = T[e] + (a[e]-a[e-1])*1.0/(n+2-e);
			if (t1 < t2) T[++s] = t1;
			else T[--e] = t2;
		}
		cout << fixed << setprecision(15) << (a[e]-a[s]+T[s]*(s+1)+T[e]*(n+2-e))/(n+s-e+3) << endl;
	}
}