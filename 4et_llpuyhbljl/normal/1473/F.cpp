#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
using namespace std;
ll gcd(ll i, ll j) {
	if (i < j)swap(i, j);
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1e18;
const int mod = 1000000007, mod1 = 1000000009;
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 1601;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
int n, s, t;
struct MC {
    ll fr, to, f, c;
    MC(ll FR = 0, ll TO = 0, ll F = 0, ll C = 0) {
        fr = FR;
        to = TO;
        f = F;
        c = C;
    }
};
vector<MC>Ed;
vector<vector<int>>Gr;
void add(int fr, int to, ll c) {
    Ed.push_back(MC(fr, to, 0, c));
    Ed.push_back(MC(to, fr, 0, 0));
    Gr[fr].push_back(Ed.size() - 2);
    Gr[to].push_back(Ed.size() - 1);
}
vector<int>path;
bool bfs(int s) {
    path.assign(n, -1);
    path[s] = 0;
    queue<int>q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : Gr[v]) {
            if (Ed[e].f == Ed[e].c || path[Ed[e].to] != -1)continue;
            path[Ed[e].to] = path[v] + 1;
            q.push(Ed[e].to);
        }
    }
    return path[t] != -1;
}
vector<int>used;
ll dfs(int i, ll cs = INF) {
    if (i == t)return cs;
    for (; used[i] < Gr[i].size(); ++used[i]) {
        int e = Gr[i][used[i]];
        if (path[Ed[e].fr] + 1 == path[Ed[e].to] && Ed[e].c != Ed[e].f) {
            int tmp = dfs((ll)Ed[e].to, min(cs, (ll)Ed[e].c - Ed[e].f));
            if (tmp == 0)continue;
            Ed[e].f += tmp;
            Ed[e ^ 1].f -= tmp;
            return tmp;
        }
    }
    return 0;
}
void solve() {
    int sz;
    cin >> sz;
    n = sz + 2;
    Gr.resize(n);
    s = sz + 1;
    t = 0;
	vector<int>a(sz), b(sz);
	for (auto& x : a)cin >> x;
	for (auto& x : b)cin >> x;
    vector<int>lst(101, -1);
    ll sum = 0;
    for (int i = 0; i < sz; ++i) {
        if (b[i] > 0)sum += b[i];
        for (int j = 1; j <= 100; ++j) {
            if (a[i] % j == 0 && lst[j] != -1) {
                add(i + 1, lst[j] + 1, INF);
            }
        }
        lst[a[i]] = i;
        if (b[i] > 0)add(s, i + 1, b[i]);
        else add(i + 1, t, -b[i]);
    }
    long long ans = 0;
    while (bfs(s)) {
        used.assign(n, 0);
        while (long long pt = dfs(s)) {
            ans += pt;
        }
    }
    cout << sum - ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("epic.in", "r", stdin); freopen("epic.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}