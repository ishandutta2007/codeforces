/*
result of thinking: Pure.
ukv
start coding: 11:00
AC: 12:52 
7ms, :  O((n+q)klogk),  O(qk^2).
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
return x < y ? (x = y, true) : false;
}
bool Mbe;
#define maxn 200005
#define maxk 27
int n, k, T, q, pass[maxk], fine[maxk], top[maxn], par[maxn];
vector<P> adj[maxn];
char z[maxn];
ll len[maxn];
vector<int> cru[maxn];
int have[maxn];
void dfs1(int u, int p) {
par[u] = p;
for (auto e : adj[u]) {
int v = e.first;
if (v == p)
continue;
if (z[v] == z[u])
len[v] = len[u] + e.second, top[v] = top[u];
else
len[v] = e.second, top[v] = v;
dfs1(v, u);
}
}
void dfs2(int u, int p) {
have[u] = 1 << (lower_bound(cru[top[u]].begin(), cru[top[u]].end(),
(len[u] - 1) % T + 1) - cru[top[u]].begin());
for (auto e : adj[u]) {
int v = e.first;
if (v == p)
continue;
dfs2(v, u);
if (z[v] == z[u])
have[u] |= have[v];
}
}
ll query(int u, ll t) {
if (!u)
return 0;
return min(fine[z[u] - 'A']
* min((ll)pass[z[u] - 'A'], ((t + len[u] - 1) / T - (t - 1) / T)),
(ll)pass[z[u] - 'A']) + query(par[top[u]], t + len[u]);
}
bool Med;
int main() {
fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
scanf("%d", &n);
for (int i = 1; i < n; i++) {
int u, v, w;
scanf("%d%d%d", &u, &v, &w);
adj[u].push_back({v, w});
adj[v].push_back({u, w});
}
scanf("%d", &k);
scanf("%s", z + 1);
for (int i = 0; i < k; i++)
scanf("%d", pass + i);
for (int i = 0; i < k; i++)
scanf("%d", fine + i);
scanf("%d", &T);
top[1] = 1;
dfs1(1, 0);
for (int i = 2; i <= n; i++) {
if (top[i] == i) {
ll foo = 0;
for (int j = par[i]; j; j = par[top[j]]) {
foo += len[j];
if (foo % T)
cru[i].push_back(T - (foo - (foo - 1) / T * T));
}
sort(cru[i].begin(), cru[i].end());
cru[i].push_back(T);
}
}
cru[1].push_back(T);
dfs2(1, 0);
scanf("%d", &q);
while (q--) {
int fl, x;
char s[5];
scanf("%d", &fl);
if (fl == 1) {
scanf("%s%d", s, &x);
pass[s[0] - 'A'] = x;
} else if (fl == 2) {
scanf("%s%d", s, &x);
fine[s[0] - 'A'] = x;
} else {
scanf("%d", &x);
ll ans = infll;
for (int i = 0; i < (int)cru[top[x]].size(); i++) {
if (have[x] >> i & 1) {
chmin(ans, query(par[top[x]], cru[top[x]][i]));
}
}
printf("%lld\n", ans);
}
}
return 0;
}