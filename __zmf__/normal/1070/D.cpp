#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LL long long
#define PB push_back
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 2e5;
const int M = 1e6;
const int mod = 1e9 + 7;
const int inf = 1e9;
int read() {
	int x = 0, y = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) y |= (c == '-');
	for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar());
	return (y ? -x : x);
}

int a, b, s[N + 5], p[N + 5];

signed main() {
	// freopen("in1.in", "r", stdin);
	a = read();
	b = read();
	int ans = 0;
	rep(i, 1, a) {
		s[i] = read();
		if(i < a) {
			if((s[i] + p[i] + b - 1) / b == (p[i] + b - 1) / b) ans += (p[i] + b - 1) / b;
			else ans += (s[i] + p[i]) / b, p[i + 1] += (s[i] + p[i]) % b;
		}
		else ans += (s[i] + p[i] + b - 1) / b;
	}
	cout << ans;
	return 0;
}