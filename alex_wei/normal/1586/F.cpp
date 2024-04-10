#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int, int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x), end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define FileI(x) freopen(x, "r", stdin)
#define FileO(x) freopen(x, "w", stdout)

namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
	    ll x = 0, sgn = 0; char s = gc;
	    while(!isdigit(s)) sgn |= s == '-', s = gc;
	    while(isdigit(s)) x = x * 10 + s - '0', s = gc;
	    return sgn ? -x : x;
	}
	inline void rec_print(ll x) {if(x >= 10) rec_print(x / 10); pc(x % 10 + '0');}
	inline void print(ll x) {if(x < 0) pc('-'), x = -x; rec_print(x);}
} using namespace IO;

template <class T> void cmin(T &a, T b){a = a < b ? a : b;}
template <class T> void cmax(T &a, T b){a = a > b ? a : b;}

const int N = 1e3 + 5;

int n, k, e[N][N];
int solve(int l, int r) {
	if(l == r) return 0;
	int cnt = 1, len = r - l + 1;
	if(len < k) {
		for(int i = l; i <= r; i++)
			for(int j = i + 1; j <= r; j++)
				e[i][j] = cnt;
		return cnt;
	}
	int p = len / k, rest = len % k;
	vint pos(k + 1, 0), col(n + 1, 0);
	for(int i = 1; i <= k; i++)
		pos[i] = pos[i - 1] + p + (i <= rest);
	for(int i = 1; i <= k; i++)
		cnt = max(cnt, solve(l + pos[i - 1], l + pos[i] - 1) + 1);
	for(int i = 1; i <= k; i++)
		for(int j = pos[i - 1]; j < pos[i]; j++)
			col[l + j] = i;
	for(int i = l; i <= r; i++)
		for(int j = i + 1; j <= r; j++)
			if(col[i] != col[j])
				e[i][j] = cnt;
	return cnt;
}
int main(){
//	FileI("1.in");
	cin >> n >> k, cout << solve(1, n) << endl;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			cout << e[i][j] << " ";
    return flush(), 0;
}