// Problem: B. Preparing for Merge Sort
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
const int N = 2e5;
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

int a, s[N + 5], nxt[N + 5];
bool vis[N + 5];
struct pii {
	int x;
	bool operator<(const pii &o) const {return s[x] > s[o.x];}
};
set<pii> st;

signed main() {
	// freopen("in1.in", "r", stdin);
	a = read();
	rep(i, 1, a) {
		s[i] = read();
		auto it = st.upper_bound((pii) {i});
		if(it != st.end()) {
			nxt[(*it).x] = i;
			st.erase(it);
		}
		st.insert((pii) {i});
	}
	rep(i, 1, a) if(!vis[i]) {
		for(int x = i; x; x = nxt[x]) {
			vis[x] = 1;
			printf("%lld ", s[x]);
		}
		puts("");
	}
	return 0;
}