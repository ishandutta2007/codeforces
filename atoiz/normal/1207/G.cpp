/*input

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 400050;

int strTrie[MAXN][26];
int strNode[MAXN], strPtr = 1;

int patTrie[MAXN][26];
bool hasQuery[MAXN];
vector<int> flags[MAXN];
int prv[MAXN], prvPtr = 1;

int queryMap[MAXN];
vector<int> queries[MAXN];

int N, M, ans[MAXN];

int addStr(string str)
{
	int cur = 1;
	FORA(_, str) {
		int ch = _ - 'a';
		cur = (patTrie[cur][ch] ? patTrie[cur][ch] : (patTrie[cur][ch] = ++prvPtr));
	}
	return cur;
}

pii tmp[MAXN << 1];
int qu[MAXN], fr, rr;
void initPrv()
{
	fr = 0, rr = 0;
	qu[++rr] = 1;
	while (fr < rr) {
		int u = qu[++fr];
		FOR(ch, 0, 25) if (patTrie[u][ch]) {
			int v = prv[u], child = patTrie[u][ch];
			for (; v > 1 && !patTrie[v][ch]; v = prv[v]);
			prv[child] = (patTrie[v][ch] ? patTrie[v][ch] : 1);
			qu[++rr] = child;

			flags[child] = flags[prv[child]];
			// cout << u << " -> " << child << ": " << char(ch + 'a') << " - ";
			if (hasQuery[child]) flags[child].push_back(child);

			// cout << endl;
			// FORA(x, flags[child]) cout << '(' << x.fi << ", " << x.se << ") ";
			// cout << endl;
		}
	}
}

int curCnt[MAXN];
void dfs(int strU, int patU)
{
	// cout << "dfs + " << strU << ' ' << patU << endl;
	FORA(x, flags[patU]) ++curCnt[x];

	FORA(q, queries[strU]) {
		ans[q] = curCnt[queryMap[q]];
		// cout << q << ": " << queryMap[q] << ' ' << ans[q] << endl;
	}

	int pending = 0;
	FOR(ch, 0, 25) if (strTrie[strU][ch]) pending ^= (1 << ch);
	for (int u = patU; pending > 0 && u > 0; u = prv[u]) {
		FOR(ch, 0, 25) if (((pending >> ch) & 1) && patTrie[u][ch]) {
			dfs(strTrie[strU][ch], patTrie[u][ch]);
			pending ^= (1 << ch);
		}
	}
	FOR(ch, 0, 25) if ((pending >> ch) & 1) dfs(strTrie[strU][ch], 1); 

	FORA(x, flags[patU]) --curCnt[x];
	// cout << "dfs - " << strU << ' ' << patU << endl;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	FOR(i, 1, N) {
		int type; cin >> type;
		char ch;
		int u;
		if (type == 1) {
			cin >> ch;
			u = 1;
		} else {
			cin >> u >> ch;
			u = strNode[u];
		}
		int id = ch - 'a';
		strNode[i] = (strTrie[u][id] ? strTrie[u][id] : (strTrie[u][id] = ++strPtr));
		
	}

	cin >> M;
	FOR(q, 1, M) {
		int i; string str;
		cin >> i >> str;
		hasQuery[queryMap[q] = addStr(str)] = 1;
		queries[strNode[i]].emplace_back(q);
	}

	initPrv();
	dfs(1, 1);
	FOR(q, 1, M) cout << ans[q] << '\n';

	return 0;
}