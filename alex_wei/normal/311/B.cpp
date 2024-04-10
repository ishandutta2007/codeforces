#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;

ll n, m, p, hd, tl, d[N], t[N], s[N], f[N], g[N];
ll dx(int i, int j) {return j - i;}
ll dy(int i, int j) {return f[j] + s[j] - f[i] - s[i];} 
int main() {
	cin >> n >> m >> p;
	for(int i = 2; i <= n; i++) cin >> d[i], d[i] += d[i - 1];
	for(int i = 1, h; i <= m; i++) cin >> h >> t[i], t[i] -= d[h];
	sort(t + 1, t + m + 1);
	for(int i = 1; i <= m; i++) s[i] = s[i - 1] + t[i];
	for(int i = 1; i <= m; i++) f[i] = t[i] * i - s[i];
	for(int _ = 1; _ < p; _++, swap(f, g), hd = tl = 0) {
		for(int i = 1; i <= m; d[++tl] = i++) {
			while(hd < tl && dy(d[hd], d[hd + 1]) <= t[i] * dx(d[hd], d[hd + 1])) hd++;
			g[i] = f[d[hd]] + t[i] * (i - d[hd]) - (s[i] - s[d[hd]]);
			while(hd < tl && dx(d[tl - 1], d[tl]) * dy(d[tl], i) - dy(d[tl - 1], d[tl]) * dx(d[tl], i) <= 0) tl--;
		}
	} cout << f[m] << endl;
	return 0;
}