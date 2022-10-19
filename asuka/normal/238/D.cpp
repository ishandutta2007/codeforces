#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 100015;
int n, q, In[N], Out[N];
array<int, 10> sum[N * 2], cur;
vector<int> stk;
list<int> L;
bool vis[N];
char s[N];
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	rep(i, 0, n + 1) L.emplace_back(i);
	auto ptr = L.begin();
	int dir = 1, clk = 0;
	while (SZ(L) > 2) {
		int u = *ptr;
		if (!vis[u]) {
			vis[u] = 1;
			sum[In[u] = ++clk] = cur;
			stk.pb(u);
		} else {
			while (SZ(stk) > 0 && stk.back() > u) {
				sum[Out[stk.back()] = ++clk] = cur;
				stk.pop_back();
			}
		}
		if (u == 0 || u == n + 1) {
			ptr = L.begin(); ptr++; dir = 1;
			continue;
		}
		if (!isdigit(s[u])) dir = s[u] == '>' ? 1 : -1;
		auto nptr = dir == 1 ? next(ptr) : prev(ptr);
		if (isdigit(s[u])) {
			cur[s[u] - '0']++;
			if (s[u] == '0') L.erase(ptr);
			else s[u]--;
		} else {
			if (!isdigit(s[*nptr])) L.erase(ptr);
		}
		ptr = nptr;
	}
	// printf("\n");
	if (!vis[n + 1]) sum[In[n + 1] = ++clk] = cur, stk.pb(n + 1);
	while (SZ(stk) > 0) sum[Out[stk.back()] = ++clk] = cur, stk.pop_back();
	while (q--) {
		int l, r, L, R;
		scanf("%d%d", &l, &r);
		L = In[l]; R = min(In[r + 1], Out[l]);
		// printf("%d %d\n", In[r + 1], Out[l]);
		// printf("[%d %d]\n", L, R);
		rep(j, 0, 9) printf("%d%c", sum[R][j] - sum[L][j], " \n"[j == 9]);
	}
	return 0;
}