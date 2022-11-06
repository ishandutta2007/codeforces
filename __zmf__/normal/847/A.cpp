// Problem: A. Union of Doubly Linked Lists
// Contest: Codeforces - 2017-2018 ACM-ICPC, NEERC, Southern Subregional Contest, qualification stage (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// Author: RedreamMer
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LL long long
#define PB push_back
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 1e5;
const int M = 100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
int read() {
	int x = 0, y = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) y |= (c == '-');
	for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar());
	return (y ? -x : x);
}

int a, l[N + 5], r[N + 5], R[N + 5];
bool vis[N + 5];

int find(int n) {
	return !r[n] ? n : find(r[n]);
}

signed main() {
	// freopen("in1.in", "r", stdin);
	a = read();
	rep(i, 1, a) {
		l[i] = read();
		r[i] = read();
	}
	rep(i, 1, a) if(!l[i]) R[i] = find(i), vis[i] = 1;
	int n;
	rep(i, 1, a) if(vis[i]) {
		n = i;
		break;
	}
	rep(i, n + 1, a) if(vis[i]) {
		l[i] = R[n], r[R[n]] = i;
		n = i;
	}
	rep(i, 1, a) cout << l[i] << ' ' << r[i] << endl;
	return 0;
}