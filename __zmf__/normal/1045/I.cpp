#include <bits/stdc++.h>
using namespace std;

#define PB push_back
// #define int long long
#define LL long long
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 1e6;
const int M = 1e7;
const int mod = 1e9 + 7;
const int inf = 1e9;
int read() {
	int x = 0, y = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) y |= (c == '-');
	for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar());
	return (y ? -x : x);
}

int a;
char s[N + 5];
map<int, int> mp;

signed main() {
	// freopen("in1.in", "r", stdin);
	// freopen("out.out", "w", stdout);
	a = read();
	LL ans = 0;
	rep(i, 1, a) {
		scanf("%s", s + 1);
		int len = strlen(s + 1), p = 0;
		rep(j, 1, len) p ^= (1 << (s[j] - 'a'));
		ans += mp[p];
		rep(k, 0, 25) {
			int q = p ^ (1 << k);
			if(mp.count(q)) ans += mp[q];
		}
		++mp[p];
		// cout << ans << endl;
	}
	cout << ans;
	return 0;
}