#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5;

int n, d, a[maxn], b[maxn], add, suff[maxn], cnt;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> d;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
		if(i) b[i] += b[i - 1];
		if(b[i] > d) return cout << -1, 0;
	}
	suff[n - 1] = b[n - 1];
	for(int i = n - 2; i >= 0; i--) suff[i] = max(b[i], suff[i + 1]);
	for(int i = 0; i < n; i++)
		if(a[i] == 0 && b[i] + add < 0) {
			add += d - suff[i] - add;
			cnt++;
			if(b[i] + add < 0) return cout << -1, 0;
		}
	cout << cnt;
}