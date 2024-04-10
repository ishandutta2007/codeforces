/*input
3 3
6 3 2
5 9 8
7 4 1 
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// #define LOCAL

#define deb err_stream()
#define endl '\n'
struct err_stream
{
	template <typename T>
	err_stream& operator<< (T x)
	{
		#ifdef LOCAL
		cout << x << flush;
		#endif
		return *this;
	}
};

const int MAXN = 200007;


int N, R, C;

int rev[MAXN], par[MAXN], ch[MAXN][2], st[MAXN], top;
bool dir(int x)
{ return x == ch[par[x]][1]; }
bool isroot(int x)
{ return x != ch[par[x]][dir(x)]; }

void pushdown(int x)
{
	if (rev[x]) {
		swap(ch[x][0], ch[x][1]);
		rev[ch[x][0]] ^= 1;
		rev[ch[x][1]] ^= 1;
		rev[x] = 0;
	}
}

void rot(int x)
{
	// deb << "rot: " << x << endl;
	int p = par[x], d = dir(x);
	if (!isroot(p)) ch[par[p]][dir(p)] = x; par[x] = par[p];
	par[ch[p][d] = ch[x][!d]] = p;
	par[ch[x][!d] = p] = x;
}

void splay(int x)
{
	// deb << "splay: " << x << endl;
	st[top = 1] = x;
	for (int u = x; !isroot(u); u = par[u]) st[++top] = par[u];
	while (top) pushdown(st[top--]);
	for (; !isroot(x); rot(x)) if (!isroot(par[x])) rot(dir(x) == dir(par[x]) ? par[x] : x); 
}

void access(int x)
{
	// deb << "access: " << x << endl;
	for (int y = 0; x; y = x, x = par[y]) {
		splay(x);
		ch[x][1] = y;
	}
}

void make_root(int x)
{
	// deb << "make_root: " << x << endl;
	access(x); splay(x); rev[x] ^= 1;
}

bool link(int x, int y)
{
	make_root(x); access(y); splay(y);
	deb << "link: " << x << ' ' << y << ' ' << par[x] << endl;
	if (par[x]) return false;
	par[x] = y;
	return true;
}

bool cut(int x, int y)
{
	make_root(x); access(y); splay(y);
	deb << "cut: " << x << ' ' << y << ": " << par[x] << ' ' << ch[y][0] << endl;
	if (par[x] != y || ch[x][1]) return false;
	ch[y][0] = par[x] = 0;
	return true;
}

int mn[MAXN << 2], cnt[MAXN << 2], inc[MAXN << 2];
void push(int rt, int lo, int hi)
{
	if (lo < hi && inc[rt]) {
		mn[rt << 1] += inc[rt];
		mn[rt << 1 | 1] += inc[rt];
		inc[rt << 1] += inc[rt];
		inc[rt << 1 | 1] += inc[rt];
		inc[rt] = 0;
	}
}

void pull(int rt)
{
	mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
	cnt[rt] = (mn[rt] == mn[rt << 1]) * cnt[rt << 1] + (mn[rt] == mn[rt << 1 | 1]) * cnt[rt << 1 | 1];
}

void upd(int l, int r, int x, int rt = 1, int lo = 1, int hi = N)
{
	// if (rt == 1) deb << "upd " << rt << ' ' << lo << ' ' << hi << ": " << l << ' ' << r << ' ' << x << ": " << mn[rt] << ' ' << cnt[rt] << endl;
	if (hi < l || r < lo) return;
	if (l <= lo && hi <= r) {
		mn[rt] += x, inc[rt] += x;
		return;
	}

	int md = (lo + hi) >> 1;
	push(rt, lo, hi);
	upd(l, r, x, rt << 1, lo, md);
	upd(l, r, x, rt << 1 | 1, md + 1, hi);
	pull(rt);
}

int get(int l, int r, int rt = 1, int lo = 1, int hi = N)
{
	if (hi < l || r < lo) return 0;
	// if (l <= lo && hi <= r) deb << "get " << rt << ' ' << lo << ' ' << hi << ": " << l << ' ' << r << " = " << mn[rt] << ' ' << cnt[rt] << endl;
	if (l <= lo && hi <= r) return (!mn[rt]) * cnt[rt];

	int md = (lo + hi) >> 1;
	push(rt, lo, hi);
	return get(l, r, rt << 1, lo, md) + get(l, r, rt << 1 | 1, md + 1, hi);
}

void build(int rt = 1, int lo = 1, int hi = N)
{
	if (lo == hi) {
		mn[rt] = lo, cnt[rt] = 1;
		return;
	}

	int md = (lo + hi) >> 1;
	build(rt << 1, lo, md);
	build(rt << 1 | 1, md + 1, hi);
	pull(rt);
}

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool valid(int i, int j)
{	return 0 <= i && i < R && 0 <= j && j < C; }
vector<vector<int>> A;
vector<pair<int, int>> add, rem;
pair<int, int> pos[MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	N = R * C;
	A.assign(R, vector<int>(C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> A[i][j];
			pos[A[i][j]] = make_pair(i, j);
		}
	}

	int E = (R - 1) * C + R * (C - 1);
	add.reserve(E);
	rem.reserve(E);
	for (int x = 1; x <= N; ++x) {
		int i = pos[x].first, j = pos[x].second;
		for (int d = 0; d < 4; ++d) {
			int i0 = i + dx[d], j0 = j + dy[d];
			if (valid(i0, j0)) {
				if (A[i0][j0] > x) {
					rem.emplace_back(x, A[i0][j0]);
				} else {
					add.emplace_back(x, A[i0][j0]);
				}
			}
		}
	}

	// for (auto x : rem) deb << x.first << ' ' << x.second << endl;

	build();
	int64_t ans = 0;
	for (int l = 1, i = 0, j = 0; l <= N; ++l) {
		upd(l, N, -1);
		for (; i < E; ++i) {
			if (add[i].second >= l) {
				if (link(add[i].first, add[i].second)) {
					deb << "Y" << endl;
					upd(add[i].first, N, -1);
				} else {
					break;
				}
			}
		}

		int r = (i == E ? N + 1 : add[i].first);
		ans += get(l, r - 1);
		deb << "S " << r << ' ' << get(l, r - 1) << endl;
		for (; j < E && rem[j].first == l; ++j) {
			if (cut(rem[j].first, rem[j].second)) {
				deb << "Y" << endl;
				upd(rem[j].second, N, 1);
			}
		}
	}

	cout << ans << endl;
	return 0;
}